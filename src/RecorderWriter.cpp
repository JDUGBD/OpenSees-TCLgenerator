#include "RecorderWriter.h"

RecorderWriter::RecorderWriter(const Config& cfg) : cfg_(cfg) {}

// ---- PVD Recorder
void RecorderWriter::addPVDRecorder(const std::string& fileNamePVD,
                                    const std::vector<std::string>& recorded) {
  std::ofstream file(cfg_.recorderFile, std::ios::app);
  if (!file)
    throw std::runtime_error("Cannot Open File >> " + cfg_.recorderFile);

  // get the current path to directory
  std::string current_path = getCurrentDirectory();
  std::string folder =
      current_path + "\\OpenSees_TCL_generator\\" + fileNamePVD;
  // check and create directory
  checkAndCreateDirectory(fileNamePVD);

  file << "recorder PVD " << "\"" << fileNamePVD << "\"" << " ";
  for (int ii = 0; ii < recorded.size(); ii++) {
    file << "\"" << recorded[ii] << "\"" << " ";
  }
  file << "\n";
  file.close();
}

void RecorderWriter::addAdditionalPVDRecorder(
    const std::string& fileNamePVD, const std::vector<std::string>& recorded) {
  std::ofstream file(cfg_.analysisFile, std::ios::app);
  if (!file)
    throw std::runtime_error("Cannot Open File >> " + cfg_.analysisFile);

  // get the current path to directory
  std::string current_path = getCurrentDirectory();
  std::string folder =
      current_path + "\\OpenSees_TCL_generator\\" + fileNamePVD;
  // check and create directory
  checkAndCreateDirectory(folder);

  file << "recorder PVD " << "\"" << fileNamePVD << "\"" << " ";
  for (int ii = 0; ii < recorded.size(); ii++) {
    file << "\"" << recorded[ii] << "\"" << " ";
  }
  file << "\n";
  file.close();
}

// ---- Node Recorder ----
void RecorderWriter::addNodeRecorder(const std::string& filename,
                                     const std::vector<std::size_t>& nodes,
                                     const std::vector<std::size_t>& dofs,
                                     const std::string& rec) {
  std::ofstream file(cfg_.recorderFile, std::ios::app);
  if (!file)
    throw std::runtime_error("Cannot Open File >> " + cfg_.recorderFile);

  file << "# Node Recorder Definition\n";

  file << "recorder Node -file " << filename << " -node ";

  for (auto& n : nodes) {
    file << n << " ";
  }

  file << "-dof ";

  for (auto& d : dofs) {
    file << d << " ";
  }

  file << rec << "\n";
  file.close();
}

void RecorderWriter::addNodeRecorder(const std::string& filename,
                                     const std::size_t& nodes,
                                     const std::vector<std::size_t>& dofs,
                                     const std::string& rec) {
  std::ofstream file(cfg_.recorderFile, std::ios::app);
  if (!file)
    throw std::runtime_error("Cannot Open File >> " + cfg_.recorderFile);

  file << "# Node Recorder Definition\n";

  file << "recorder Node -file " << filename << " -node " << nodes;
  file << " -dof ";

  for (auto& d : dofs) {
    file << d << " ";
  }

  file << rec << "\n";
  file.close();
}

void RecorderWriter::addNodeRecorder(const std::string& filename,
                                     const std::size_t& nodes,
                                     const std::size_t& dofs,
                                     const std::string& rec) {
  std::ofstream file(cfg_.recorderFile, std::ios::app);
  if (!file)
    throw std::runtime_error("Cannot Open File >> " + cfg_.recorderFile);

  file << "# Node Recorder Definition\n";
  file << "recorder Node -file " << filename << " -node " << nodes;
  file << " -dof " << dofs << " " << rec << "\n";
  file.close();
}

void RecorderWriter::addNodeRecorder(const std::string& filename,
                                     const std::vector<std::size_t>& nodes,
                                     const std::size_t& dofs,
                                     const std::string& rec) {
  std::ofstream file(cfg_.recorderFile, std::ios::app);
  if (!file)
    throw std::runtime_error("Cannot Open File >> " + cfg_.recorderFile);
  file << "# Node Recorder Definition\n";

  file << "recorder Node -file " << filename << " -node ";
  for (auto& n : nodes) {
    file << n << " ";
  }

  file << "-dof " << dofs << " " << rec << "\n";
  file.close();
}

void RecorderWriter::addAdditionalNodeRecorder(
    const std::string& filename, const std::vector<std::size_t>& nodes,
    const std::vector<std::size_t>& dofs, const std::string& rec) {
  std::ofstream file(cfg_.analysisFile, std::ios::app);
  if (!file)
    throw std::runtime_error("Cannot Open File -> Analysis >> " +
                             cfg_.analysisFile);

  file << "# Node Recorder Definition\n";

  file << "recorder Node -file " << filename << " -node ";

  for (auto& n : nodes) {
    file << n << " ";
  }

  file << "-dof ";

  for (auto& d : dofs) {
    file << d << " ";
  }

  file << rec << "\n";
  file.close();
}

void RecorderWriter::addAdditionalNodeRecorder(
    const std::string& filename, const std::size_t& nodes,
    const std::vector<std::size_t>& dofs, const std::string& rec) {
  std::ofstream file(cfg_.analysisFile, std::ios::app);
  if (!file)
    throw std::runtime_error("Cannot Open File -> Analysis >> " +
                             cfg_.analysisFile);

  file << "# Node Recorder Definition\n";

  file << "recorder Node -file " << filename << " -node " << nodes;
  file << " -dof ";

  for (auto& d : dofs) {
    file << d << " ";
  }

  file << rec << "\n";
  file.close();
}

void RecorderWriter::addAdditionalNodeRecorder(const std::string& filename,
                                               const std::size_t& nodes,
                                               const std::size_t& dofs,
                                               const std::string& rec) {
  std::ofstream file(cfg_.analysisFile, std::ios::app);
  if (!file)
    throw std::runtime_error("Cannot Open File -> Analysis >> " +
                             cfg_.analysisFile);

  file << "# Node Recorder Definition\n";
  file << "recorder Node -file " << filename << " -node " << nodes;
  file << " -dof " << dofs << " " << rec << "\n";
  file.close();
}

void RecorderWriter::addAdditionalNodeRecorder(
    const std::string& filename, const std::vector<std::size_t>& nodes,
    const std::size_t& dofs, const std::string& rec) {
  std::ofstream file(cfg_.analysisFile, std::ios::app);
  if (!file)
    throw std::runtime_error("Cannot Open File -> Analysis >> " +
                             cfg_.analysisFile);
  file << "# Node Recorder Definition\n";

  file << "recorder Node -file " << filename << " -node ";
  for (auto& n : nodes) {
    file << n << " ";
  }

  file << "-dof " << dofs << " " << rec << "\n";
  file.close();
}
