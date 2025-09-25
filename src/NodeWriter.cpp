#include "NodeWriter.h"

#include <fstream>
#include <iomanip>
#include <stdexcept>

NodeWriter::NodeWriter(Config& cfg) : cfg_(cfg) {}

void NodeWriter::addNode(const std::size_t& nodeTag,
                         const std::vector<double>& coords) {
  std::ofstream file(cfg_.nodesFile, std::ios::app);
  if (!file)
    throw std::runtime_error("Cannot open Node file: " + cfg_.nodesFile);

  file << "# Node Definition\n";
  file << "node " << nodeTag << " " << std::fixed
       << std::setprecision(cfg_.precision) << coords[0] << " " << coords[1]
       << " " << coords[2] << "\n";
  file.close();
}

void NodeWriter::addNode(const std::size_t& nodeTag,
                         const std::vector<double>& coords,
                         const std::size_t& ndm, const std::size_t& ndf) {
  cfg_.ndm = ndm;
  cfg_.ndf = ndf;
  std::ofstream file(cfg_.nodesFile, std::ios::app);
  if (!file)
    throw std::runtime_error("Cannot open Node file: " + cfg_.nodesFile);

  file << "# Node Definition\n";
  file << "model BasicBuilder -ndm " << cfg_.ndm << " -ndf " << cfg_.ndf
       << "\n";
  file << "node " << nodeTag << " " << std::fixed
       << std::setprecision(cfg_.precision) << coords[0] << " " << coords[1]
       << " " << coords[2] << "\n";
  file.close();
}

void NodeWriter::addNodes(const std::vector<std::size_t>& nodeTags,
                          const std::vector<std::vector<double>>& coords) {
  std::ofstream file(cfg_.nodesFile, std::ios::app);
  if (!file)
    throw std::runtime_error("Cannot open Node file: " + cfg_.nodesFile);

  file << "# Node Definition\n";
  for (std::size_t i = 0; i < nodeTags.size(); ++i) {
    file << "node " << nodeTags[i] << " " << std::fixed
         << std::setprecision(cfg_.precision) << coords[i][0] << " "
         << coords[i][1] << " " << coords[i][2] << "\n";
  }

  file.close();
}

void NodeWriter::addNodes(const std::vector<std::size_t>& nodeTags,
                          const std::vector<std::vector<double>>& coords,
                          const std::size_t& ndm, const std::size_t& ndf) {
  cfg_.ndm = ndm;
  cfg_.ndf = ndf;
  std::ofstream file(cfg_.nodesFile, std::ios::app);
  if (!file)
    throw std::runtime_error("Cannot open Node file: " + cfg_.nodesFile);

  file << "# Node Definition\n";
  file << "model BasicBuilder -ndm " << cfg_.ndm << " -ndf " << cfg_.ndf
       << "\n";

  for (std::size_t i = 0; i < nodeTags.size(); ++i) {
    file << "node " << nodeTags[i] << " " << std::fixed
         << std::setprecision(cfg_.precision) << coords[i][0] << " "
         << coords[i][1] << " " << coords[i][2] << "\n";
  }

  file.close();
}

void NodeWriter::addAdditionalNode(const std::size_t& nodeTag,
                                   const std::vector<double>& coords) {
  std::ofstream file(cfg_.analysisFile, std::ios::app);
  if (!file)
    throw std::runtime_error("Cannot open Node file: " + cfg_.nodesFile);

  file << "# Node Definition\n";
  file << "model BasicBuilder -ndm " << cfg_.ndm << " -ndf " << cfg_.ndf
       << "\n";

  file << "node " << nodeTag << " " << std::fixed
       << std::setprecision(cfg_.precision) << coords[0] << " " << coords[1]
       << " " << coords[2] << "\n";

  file.close();
}

void NodeWriter::addAdditionalNode(const std::size_t& nodeTag,
                                   const std::vector<double>& coords,
                                   const std::size_t& ndm,
                                   const std::size_t& ndf) {
  cfg_.ndm = ndm;
  cfg_.ndf = ndf;
  std::ofstream file(cfg_.analysisFile, std::ios::app);
  if (!file)
    throw std::runtime_error("Cannot open Node file: " + cfg_.nodesFile);

  file << "# Node Definition\n";
  file << "model BasicBuilder -ndm " << cfg_.ndm << " -ndf " << cfg_.ndf
       << "\n";

  file << "node " << nodeTag << " " << std::fixed
       << std::setprecision(cfg_.precision) << coords[0] << " " << coords[1]
       << " " << coords[2] << "\n";

  file.close();
}

void NodeWriter::addAdditionalNodes(
    const std::vector<std::size_t>& nodeTags,
    const std::vector<std::vector<double>>& coords) {
  std::ofstream file(cfg_.analysisFile, std::ios::app);
  if (!file)
    throw std::runtime_error("Cannot open Node file: " + cfg_.nodesFile);

  file << "# Node Definition\n";
  file << "model BasicBuilder -ndm " << cfg_.ndm << " -ndf " << cfg_.ndf
       << "\n";

  for (std::size_t i = 0; i < nodeTags.size(); ++i) {
    file << "node " << nodeTags[i] << " " << std::fixed
         << std::setprecision(cfg_.precision) << coords[i][0] << " "
         << coords[i][1] << " " << coords[i][2] << "\n";
  }

  file.close();
}

void NodeWriter::addAdditionalNodes(
    const std::vector<std::size_t>& nodeTags,
    const std::vector<std::vector<double>>& coords, const std::size_t& ndm,
    const std::size_t& ndf) {
  cfg_.ndm = ndm;
  cfg_.ndf = ndf;
  std::ofstream file(cfg_.analysisFile, std::ios::app);
  if (!file)
    throw std::runtime_error("Cannot open Node file: " + cfg_.analysisFile);

  file << "# Node Definition\n";
  file << "model BasicBuilder -ndm " << cfg_.ndm << " -ndf " << cfg_.ndf
       << "\n";

  for (std::size_t i = 0; i < nodeTags.size(); ++i) {
    file << "node " << nodeTags[i] << " " << std::fixed
         << std::setprecision(cfg_.precision) << coords[i][0] << " "
         << coords[i][1] << " " << coords[i][2] << "\n";
  }

  file.close();
}

// Add Nodal Mass
void NodeWriter::addMass(const std::size_t& nodeTag,
                         const std::vector<double>& massVals) {
  std::ofstream file(cfg_.nodesFile, std::ios::app);
  if (!file)
    throw std::runtime_error("Cannot open Node file: " + cfg_.nodesFile);

  file << "# Add Nodal Mass\n";
  file << "mass " << nodeTag;

  for (auto vals : massVals) {
    file << " " << vals;
  }
  file << "\n";
  file.close();
}

void NodeWriter::addMass(const std::vector<std::size_t>& nodeTags,
                         const std::vector<double>& massVals) {
  std::ofstream file(cfg_.nodesFile, std::ios::app);
  if (!file)
    throw std::runtime_error("Cannot open Node file: " + cfg_.nodesFile);

  file << "# Add Nodal Mass\n";

  for (auto node : nodeTags) {
    file << "mass " << node << " ";
    for (auto ii = 0; ii < cfg_.ndf; ii++) {
      file << massVals[ii] << " ";
    }
    file << "\n";
  }

  file << "\n";
  file.close();
}