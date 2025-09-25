#ifndef RECORDERWRITER_H
#define RECORDERWRITER_H

#include <filesystem>
#include <fstream>
#include <string>
#include <vector>

#include "Config.h"
#include "utils.h"

class RecorderWriter {
 public:
  RecorderWriter(const Config& cfg);

  // ---- PVD Recorder
  void addPVDRecorder(const std::string& fileNamePVD,
                      const std::vector<std::string>& recorded);

  void addAdditionalPVDRecorder(const std::string& fileNamePVD,
                                const std::vector<std::string>& recorded);

  // ---- Node Recorder ----
  void addNodeRecorder(const std::string& filename,
                       const std::vector<std::size_t>& nodes,
                       const std::vector<std::size_t>& dofs,
                       const std::string& rec);

  void addNodeRecorder(const std::string& filename, const std::size_t& nodes,
                       const std::vector<std::size_t>& dofs,
                       const std::string& rec);

  void addNodeRecorder(const std::string& filename, const std::size_t& nodes,
                       const std::size_t& dofs, const std::string& rec);

  void addNodeRecorder(const std::string& filename,
                       const std::vector<std::size_t>& nodes,
                       const std::size_t& dofs, const std::string& rec);

  void addAdditionalNodeRecorder(const std::string& filename,
                                 const std::vector<std::size_t>& nodes,
                                 const std::vector<std::size_t>& dofs,
                                 const std::string& rec);

  void addAdditionalNodeRecorder(const std::string& filename,
                                 const std::size_t& nodes,
                                 const std::vector<std::size_t>& dofs,
                                 const std::string& rec);

  void addAdditionalNodeRecorder(const std::string& filename,
                                 const std::size_t& nodes,
                                 const std::size_t& dofs,
                                 const std::string& rec);

  void addAdditionalNodeRecorder(const std::string& filename,
                                 const std::vector<std::size_t>& nodes,
                                 const std::size_t& dofs,
                                 const std::string& rec);

 private:
  const Config cfg_;
};

#endif