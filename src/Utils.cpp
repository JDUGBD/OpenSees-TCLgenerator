#include "Utils.h"

void checkAndCreateDirectory(const std::string &dirPath) {
  try {
    // Create directories (including intermediate directories if necessary)
    if (std::filesystem::create_directories(dirPath)) {
      std::cout << "Directory created successfully: " << dirPath << std::endl;
    } else {
      std::cout << "Directory already exists: " << dirPath << std::endl;
    }
  } catch (const std::filesystem::filesystem_error &e) {
    std::cerr << "Error creating directory: " << e.what() << std::endl;
  }
}

std::string getCurrentDirectory() {
  char currentDir[FILENAME_MAX];
#ifdef _WIN32
  _getcwd(currentDir, sizeof(currentDir));  // Funzione per Windows
#else
  getcwd(currentDir, sizeof(currentDir));  // Funzione per Linux/Unix/Mac
#endif
  return std::string(currentDir);
}

void reshapeNodeCoords(const std::vector<double> &nodeCoords,
                       std::vector<std::vector<double>> &reshapedCoords) {
  if (nodeCoords.size() % 3 != 0) {
    std::cerr << "Errore: il numero di coordinate non è un multiplo di 3!"
              << std::endl;
    return;
  }

  // Usando iteratori per ristrutturare i dati
  for (auto it = nodeCoords.begin(); it != nodeCoords.end(); it += 3) {
    reshapedCoords.push_back({*(it), *(it + 1), *(it + 2)});
  }
}

void reshapeNodeTags(const std::vector<std::vector<std::size_t>> &nodeTags,
                     std::vector<std::vector<std::size_t>> &reshapedTags,
                     std::size_t nodes) {
  const size_t elementsPerVector = nodes;

  // Pulisce il vettore di output
  reshapedTags.clear();

  // Itera su ogni riga del vettore di input (ogni vettore in nodeTags)
  for (const auto &row : nodeTags) {
    // Aggiunge gli elementi della riga a reshapedTags in gruppi di
    // 'elementsPerVector'
    for (size_t i = 0; i < row.size(); i += elementsPerVector) {
      // Crea un sottovettore con gli elementi della riga, 4 per volta
      std::vector<std::size_t> subVector(
          row.begin() + i,
          row.begin() + std::min(i + elementsPerVector, row.size()));
      reshapedTags.push_back(subVector);
    }
  }
}

void sortNodeTagsByCoordinate(std::vector<std::size_t> &nodeTags,
                              char direction) {
  // Determine the index of the coordinate (0 = x, 1 = y, 2 = z)
  int coordIndex;
  switch (direction) {
    case 'x':
      coordIndex = 0;
      break;
    case 'y':
      coordIndex = 1;
      break;
    case 'z':
      coordIndex = 2;
      break;
    default:
      throw std::invalid_argument("Direction must be 'x', 'y', or 'z'");
  }

  // Get all nodes in the model to extract their coordinates
  std::vector<std::size_t> allNodeTags;
  std::vector<double> allCoords, _;
  gmsh::model::mesh::getNodes(allNodeTags, allCoords, _);

  // Map tag → coordinate
  std::unordered_map<std::size_t, std::vector<double>> tagToCoord;
  for (std::size_t i = 0; i < allNodeTags.size(); ++i) {
    tagToCoord[allNodeTags[i]] = {allCoords[3 * i], allCoords[3 * i + 1],
                                  allCoords[3 * i + 2]};
  }

  // Sort the input node tags by the selected coordinate
  std::sort(nodeTags.begin(), nodeTags.end(),
            [&tagToCoord, coordIndex](std::size_t a, std::size_t b) {
              return tagToCoord[a][coordIndex] < tagToCoord[b][coordIndex];
            });
}

void sortNodeTagsAndCoordinatesByDirection(
    std::vector<std::size_t> &nodeTags,
    std::vector<std::vector<double>> &coordinates, char direction) {
  // Determina l'indice della coordinata: 0 = x, 1 = y, 2 = z
  int coordIndex;
  switch (direction) {
    case 'x':
      coordIndex = 0;
      break;
    case 'y':
      coordIndex = 1;
      break;
    case 'z':
      coordIndex = 2;
      break;
    default:
      throw std::invalid_argument("La direzione deve essere 'x', 'y' o 'z'");
  }

  // Verifica che nodeTags e coordinates abbiano la stessa dimensione
  if (nodeTags.size() != coordinates.size()) {
    throw std::invalid_argument(
        "nodeTags e coordinates devono avere la stessa dimensione");
  }

  // Crea un vettore di indici
  std::vector<std::size_t> indices(nodeTags.size());
  for (std::size_t i = 0; i < indices.size(); ++i) {
    indices[i] = i;
  }

  // Ordina gli indici in base alla coordinata specificata
  std::sort(indices.begin(), indices.end(),
            [&coordinates, coordIndex](std::size_t a, std::size_t b) {
              return coordinates[a][coordIndex] < coordinates[b][coordIndex];
            });

  // Applica l'ordinamento a nodeTags e coordinates
  std::vector<std::size_t> sortedNodeTags;
  std::vector<std::vector<double>> sortedCoordinates;
  for (std::size_t i : indices) {
    sortedNodeTags.push_back(nodeTags[i]);
    sortedCoordinates.push_back(coordinates[i]);
  }

  // Aggiorna i vettori originali
  nodeTags = std::move(sortedNodeTags);
  coordinates = std::move(sortedCoordinates);
}

void getLineElementInfo(const std::vector<int> list,
                        std::vector<std::size_t> &elemTags,
                        std::vector<std::vector<size_t>> &elemNodeTags) {
  for (auto ele : list) {
    std::vector<int> elemType;
    std::vector<std::vector<size_t>> nodeTagsUnshaped, elemTags__, nodeTags;
    gmsh::model::mesh::getElements(elemType, elemTags__, nodeTagsUnshaped, 1,
                                   ele);
    // PushBack id
    for (auto vec : elemTags__[0]) {
      elemTags.push_back(vec);
    }
    // reshape Node Tags
    std::size_t numNodes = 2;
    reshapeNodeTags(nodeTagsUnshaped, nodeTags, 2);
    // push back to the vector
    for (auto vec : nodeTags) {
      elemNodeTags.push_back(vec);
    }
  }
}