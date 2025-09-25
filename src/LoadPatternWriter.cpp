#include "LoadPatternWriter.h"

LoadPatternwriter::LoadPatternwriter(const Config& cfg) : cfg_(cfg) {}

void LoadPatternwriter::addPlainPatternNodalLoad(
    const std::size_t& patternTAG, const std::size_t& timeSeriesTAG,
    const std::vector<std::size_t>& nodeTAG,
    const std::vector<std::vector<double>>& ndfs) {
  std::ofstream file(cfg_.loadPatternFile, std::ios::app);
  if (!file)
    throw std::runtime_error("Cannot Open File >> " + cfg_.loadPatternFile);

  // check for the dofs dimensions depend on the model basic builder
  std::size_t nodes = ndfs.size();
  std::size_t dim = ndfs[0].size();
  // write the Nodal Load pattern
  file << "\npattern Plain " << patternTAG << " " << timeSeriesTAG << " "
       << "{\n";
  for (int ii = 0; ii < nodes; ii++) {
    file << "\tload " << nodeTAG[ii];
    for (int jj = 0; jj < dim; jj++) {
      file << " " << ndfs[ii][jj];
    }
    file << "\n";
  }
  file << "} \n";
  file.close();
}

void LoadPatternwriter::addAdditionalPlainPatternNodalLoad(
    const std::size_t& patternTAG, const std::size_t& timeSeriesTAG,
    const std::vector<std::size_t>& nodeTAG,
    const std::vector<std::vector<double>>& ndfs) {
  std::ofstream file(cfg_.analysisFile, std::ios::app);
  if (!file)
    throw std::runtime_error("Cannot Open File -> Analysis >> " +
                             cfg_.analysisFile);

  // check for the dofs dimensions depend on the model basic builder
  std::size_t nodes = ndfs.size();
  std::size_t dim = ndfs[0].size();
  // write the Nodal Load pattern
  file << "\npattern Plain " << patternTAG << " " << timeSeriesTAG << " "
       << "{\n";
  for (int ii = 0; ii < nodes; ii++) {
    file << "\tload " << nodeTAG[ii];
    for (int jj = 0; jj < dim; jj++) {
      file << " " << ndfs[ii][jj];
    }
    file << "\n";
  }
  file << "} \n";
  file.close();
}

void LoadPatternwriter::addPlainPatternElementLoad(
    const std::size_t& patternTAG, const std::size_t& timeSeriesTAG,
    const std::vector<std::size_t>& eleTAG,
    const std::vector<std::vector<double>>& ndfs) {
  std::ofstream file(cfg_.loadPatternFile, std::ios::app);
  if (!file)
    throw std::runtime_error("Cannot Open File >> " + cfg_.loadPatternFile);
  // check for the dofs dimensions depend on the model basic builder
  std::size_t nodes = ndfs.size();
  std::size_t dim = ndfs[0].size();
  // write Elemen Load Pattern beam uniform
  file << "# Define Element BeamUniform Pattern\n";

  file << "\npattern Plain " << patternTAG << " " << timeSeriesTAG << " "
       << "{\n";

  for (int ii = 0; ii < nodes; ii++) {
    file << "\teleLoad -ele " << eleTAG[ii] << " -type -beamUniform ";
    for (int jj = 0; jj < dim; jj++) {
      file << " " << ndfs[ii][jj];
    }
    file << "\n";
  }
  file << "} \n";
  file.close();
}

void LoadPatternwriter::addPlainPatternElementLoad(
    const std::size_t& patternTAG, const std::size_t& timeSeriesTAG,
    const std::vector<std::size_t>& eleTAG, const std::vector<double>& ndfs) {
  std::ofstream file(cfg_.loadPatternFile, std::ios::app);
  if (!file)
    throw std::runtime_error("Cannot Open File >> " + cfg_.loadPatternFile);
  // check for the dofs dimensions depend on the model basic builder
  std::size_t nodes = eleTAG.size();
  std::size_t dim = ndfs.size();
  // write Elemen Load Pattern beam uniform
  file << "# Define Element BeamUniform Pattern\n";

  file << "\npattern Plain " << patternTAG << " " << timeSeriesTAG << " "
       << "{\n";

  for (int ii = 0; ii < nodes; ii++) {
    file << "\teleLoad -ele " << eleTAG[ii] << " -type -beamUniform ";
    for (int jj = 0; jj < dim; jj++) {
      file << " " << ndfs[jj];
    }
    file << "\n";
  }
  file << "} \n";
  file.close();
}

void LoadPatternwriter::addAdditionalPlainPatternElementLoad(
    const std::size_t& patternTAG, const std::size_t& timeSeriesTAG,
    const std::vector<std::size_t>& eleTAG,
    const std::vector<std::vector<double>>& ndfs) {
  std::ofstream file(cfg_.analysisFile, std::ios::app);
  if (!file)
    throw std::runtime_error("Cannot Open File >> " + cfg_.analysisFile);
  // check for the dofs dimensions depend on the model basic builder
  std::size_t nodes = ndfs.size();
  std::size_t dim = ndfs[0].size();
  // write Elemen Load Pattern beam uniform
  file << "# Define Element BeamUniform Pattern\n";

  file << "\npattern Plain " << patternTAG << " " << timeSeriesTAG << " "
       << "{\n";

  for (int ii = 0; ii < nodes; ii++) {
    file << "\teleLoad -ele " << eleTAG[ii] << " -type -beamUniform ";
    for (int jj = 0; jj < dim; jj++) {
      file << " " << ndfs[ii][jj];
    }
    file << "\n";
  }
  file << "} \n";
  file.close();
}

void LoadPatternwriter::addAdditionalPlainPatternElementLoad(
    const std::size_t& patternTAG, const std::size_t& timeSeriesTAG,
    const std::vector<std::size_t>& eleTAG, const std::vector<double>& ndfs) {
  std::ofstream file(cfg_.analysisFile, std::ios::app);
  if (!file)
    throw std::runtime_error("Cannot Open File >> " + cfg_.analysisFile);
  // check for the dofs dimensions depend on the model basic builder
  std::size_t nodes = eleTAG.size();
  std::size_t dim = ndfs.size();
  // write Elemen Load Pattern beam uniform
  file << "# Define Element BeamUniform Pattern\n";

  file << "\npattern Plain " << patternTAG << " " << timeSeriesTAG << " "
       << "{\n";

  for (int ii = 0; ii < nodes; ii++) {
    file << "\teleLoad -ele " << eleTAG[ii] << " -type -beamUniform ";
    for (int jj = 0; jj < dim; jj++) {
      file << " " << ndfs[jj];
    }
    file << "\n";
  }
  file << "} \n";
  file.close();
}