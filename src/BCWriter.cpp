#include "BCWriter.h"

BCWriter::BCWriter(const Config& cfg) : cfg_(cfg) {};

// ---- SP fixities ----
void BCWriter::addFix(const std::size_t& nodeTag,
                      const std::vector<std::size_t>& fixities) {
  std::ofstream file(cfg_.bcFile, std::ios::app);
  if (!file) throw std::runtime_error("Cannot Open File >> " + cfg_.bcFile);

  file << "# Define SP fixities\n";
  file << "fix " << nodeTag;
  for (auto idx : fixities) {
    file << " " << idx;
  }
  file << "\n";
  file.close();
}

void BCWriter::addFix(const std::vector<std::size_t>& nodeTag,
                      const std::vector<std::size_t>& fixities) {
  std::ofstream file(cfg_.bcFile, std::ios::app);
  if (!file) throw std::runtime_error("Cannot Open File >> " + cfg_.bcFile);
  file << "# Define SP fixities\n";

  for (std::size_t ii = 0; ii < nodeTag.size(); ii++) {
    file << "fix " << nodeTag[ii] << " ";
    for (auto fix : fixities) {
      file << fix << " ";
    }
    file << "\n";
  }
  file.close();
}

void BCWriter::addFix(const std::vector<std::size_t>& nodeTags,
                      const std::vector<std::vector<std::size_t>>& fixities) {
  std::ofstream file(cfg_.bcFile, std::ios::app);
  if (!file) throw std::runtime_error("Cannot Open File >> " + cfg_.bcFile);

  file << "# Define SP fixities\n";

  for (std::size_t ii = 0; ii < nodeTags.size(); ii++) {
    file << "fix " << nodeTags[ii] << " ";
    for (std::size_t jj = 0; jj < fixities[ii].size(); jj++) {
      file << fixities[ii][jj] << " ";
    }
    file << "\n";
  }

  file.close();
}

void BCWriter::addAdditionalFix(const std::size_t& nodeTag,
                                const std::vector<std::size_t>& fixities) {
  std::ofstream file(cfg_.analysisFile, std::ios::app);
  if (!file)
    throw std::runtime_error("Cannot Open File -> Analysis >> " +
                             cfg_.analysisFile);

  file << "# Define SP fixities\n";
  file << "fix " << nodeTag;
  for (auto idx : fixities) {
    file << " " << idx;
    file << "\n";
  }
  file << "\n";
  file.close();
}

void BCWriter::addAdditionalFix(const std::vector<std::size_t>& nodeTag,
                                const std::vector<std::size_t>& fixities) {
  std::ofstream file(cfg_.analysisFile, std::ios::app);
  if (!file)
    throw std::runtime_error("Cannot Open File -> Analysis >> " +
                             cfg_.analysisFile);
  file << "# Define SP fixities\n";

  for (std::size_t ii = 0; ii < nodeTag.size(); ii++) {
    file << "fix " << nodeTag[ii] << " ";
    for (auto fix : fixities) {
      file << fix << " ";
    }
    file << "\n";
  }
  file.close();
}

void BCWriter::addAdditionalFix(
    const std::vector<std::size_t>& nodeTags,
    const std::vector<std::vector<std::size_t>>& fixities) {
  std::ofstream file(cfg_.analysisFile, std::ios::app);
  if (!file)
    throw std::runtime_error("Cannot Open File -> Analysis >> " +
                             cfg_.analysisFile);

  file << "# Define SP fixities\n";

  for (std::size_t ii = 0; ii < nodeTags.size(); ii++) {
    file << "fix " << nodeTags[ii] << " ";
    for (std::size_t jj = 0; jj < fixities[ii].size(); jj++) {
      file << fixities[ii][jj] << " ";
    }
    file << "\n";
  }

  file.close();
}

// ---- MP conditions ----
// ---- equalDOF
void BCWriter::addEqualDof(const std::size_t& rNodeTag,
                           const std::vector<std::size_t>& cNodeTag,
                           const std::vector<std::size_t>& dofs) {
  std::ofstream file(cfg_.bcFile, std::ios::app);
  if (!file) throw std::runtime_error("Cannot Open File >> " + cfg_.bcFile);

  file << "# Define MP equaldof\n";

  for (auto node : cNodeTag) {
    file << "equalDOF " << rNodeTag;
    for (auto df : dofs) {
      file << " " << df;
    }
    file << "\n";
  }
  file << "\n";
  file.close();
}

void BCWriter::addEqualDof(const std::vector<std::size_t>& rNodeTags,
                           const std::vector<std::size_t>& cNodeTags,
                           const std::vector<std::size_t>& dofs) {
  std::ofstream file(cfg_.bcFile, std::ios::app);
  if (!file) throw std::runtime_error("Cannot Open File >> " + cfg_.bcFile);
  if (rNodeTags.size() != cNodeTags.size())
    throw std::runtime_error(
        "rNodeTags and cNodeTags must have same dimensions.");

  file << "# Define MP equaldof\n";
  for (std::size_t ii = 0; ii < rNodeTags.size(); ii++) {
    file << "equaldof " << rNodeTags[ii] << " " << cNodeTags[ii];
    for (auto df : dofs) {
      file << " " << df;
    }
    file << "\n";
  }

  file << "\n";
  file.close();
}

void BCWriter::addAdditionalEqualDof(const std::size_t& rNodeTag,
                                     const std::vector<std::size_t>& cNodeTag,
                                     const std::vector<std::size_t>& dofs) {
  std::ofstream file(cfg_.analysisFile, std::ios::app);
  if (!file)
    throw std::runtime_error("Cannot Open File -> Analysis >> " +
                             cfg_.analysisFile);

  file << "# Define MP equaldof\n";

  for (auto node : cNodeTag) {
    file << "equalDOF " << rNodeTag;
    for (auto df : dofs) {
      file << " " << df;
    }
    file << "\n";
  }
  file << "\n";
  file.close();
}

void BCWriter::addAdditionalEqualDof(const std::vector<std::size_t>& rNodeTags,
                                     const std::vector<std::size_t>& cNodeTags,
                                     const std::vector<std::size_t>& dofs) {
  std::ofstream file(cfg_.analysisFile, std::ios::app);
  if (!file)
    throw std::runtime_error("Cannot Open File -> Analysis >> " +
                             cfg_.analysisFile);
  if (rNodeTags.size() != cNodeTags.size())
    throw std::runtime_error(
        "rNodeTags and cNodeTags must have same dimensions.");

  file << "# Define MP equaldof\n";
  for (std::size_t ii = 0; ii < rNodeTags.size(); ii++) {
    file << "equaldof " << rNodeTags[ii] << " " << cNodeTags[ii];
    for (auto df : dofs) {
      file << " " << df;
    }
    file << "\n";
  }

  file << "\n";
  file.close();
}

void BCWriter::addRigidLink(const std::string& type,
                            const std::size_t& rNodeTag,
                            const std::size_t& cNodeTag) {
  std::ofstream file(cfg_.bcFile, std::ios::app);
  if (!file) throw std::runtime_error("Cannot Open File >> " + cfg_.bcFile);

  file << "# Define RigidLink Element\n";

  file << "rigidLink " << type << " " << rNodeTag << " " << cNodeTag << "\n";

  file << "\n";
  file.close();
}

void BCWriter::addRigidLink(const std::string& type,
                            const std::size_t& rNodeTag,
                            const std::vector<std::size_t>& cNodeTags) {
  std::ofstream file(cfg_.bcFile, std::ios::app);
  if (!file) throw std::runtime_error("Cannot Open File >> " + cfg_.bcFile);

  file << "# Define RigidLink Element\n";
  for (auto cNode : cNodeTags) {
    file << "rigidLink " << type << " " << rNodeTag << " " << cNode << "\n";
  }
  file << "\n";
  file.close();
}

void BCWriter::addRigidLink(const std::string& type,
                            const std::vector<std::size_t>& rNodeTags,
                            const std::vector<std::size_t>& cNodeTags) {
  std::ofstream file(cfg_.bcFile, std::ios::app);
  if (!file) throw std::runtime_error("Cannot Open File >> " + cfg_.bcFile);
  if (rNodeTags.size() != cNodeTags.size())
    throw std::runtime_error(
        "rNodeTags and cNodeTags must have same dimensions.");

  file << "# Define RigidLink Element\n";

  for (std::size_t ii = 0; ii < rNodeTags.size(); ii++) {
    file << "rigidLink " << type << " " << rNodeTags[ii] << " " << cNodeTags[ii]
         << "\n";
  }
  file << "\n";
  file.close();
}

void BCWriter::addAdditionalRigidLink(const std::string& type,
                                      const std::size_t& rNodeTag,
                                      const std::size_t& cNodeTag) {
  std::ofstream file(cfg_.analysisFile, std::ios::app);
  if (!file)
    throw std::runtime_error("Cannot Open File -> Analysis >> " +
                             cfg_.analysisFile);

  file << "# Define RigidLink Element\n";

  file << "rigidLink " << type << " " << rNodeTag << " " << cNodeTag << "\n";

  file << "\n";
  file.close();
}

void BCWriter::addAdditionalRigidLink(
    const std::string& type, const std::size_t& rNodeTag,
    const std::vector<std::size_t>& cNodeTags) {
  std::ofstream file(cfg_.analysisFile, std::ios::app);
  if (!file)
    throw std::runtime_error("Cannot Open File -> Analysis >> " +
                             cfg_.analysisFile);

  file << "# Define RigidLink Element\n";
  for (auto cNode : cNodeTags) {
    file << "rigidLink " << type << " " << rNodeTag << " " << cNode << "\n";
  }
  file << "\n";
  file.close();
}

void BCWriter::addAdditionalRigidLink(
    const std::string& type, const std::vector<std::size_t>& rNodeTags,
    const std::vector<std::size_t>& cNodeTags) {
  std::ofstream file(cfg_.analysisFile, std::ios::app);
  if (!file)
    throw std::runtime_error("Cannot Open File -> Analysis >> " +
                             cfg_.analysisFile);
  if (rNodeTags.size() != cNodeTags.size())
    throw std::runtime_error(
        "rNodeTags and cNodeTags must have same dimensions.");

  file << "# Define RigidLink Element\n";

  for (std::size_t ii = 0; ii < rNodeTags.size(); ii++) {
    file << "rigidLink " << type << " " << rNodeTags[ii] << " " << cNodeTags[ii]
         << "\n";
  }
  file << "\n";
  file.close();
}

// ---- Zero Length Element ----
void BCWriter::addZeroLengthElement(const std::size_t& startingTag,
                                    const std::vector<std::size_t>& iNodes,
                                    const std::vector<std::size_t>& jNodes,
                                    const std::vector<std::size_t>& matTags,
                                    const std::vector<std::size_t>& dir) {
  std::ofstream file(cfg_.bcFile, std::ios::app);
  if (!file) throw std::runtime_error("Cannot Open File >> " + cfg_.bcFile);

  if (iNodes.size() != jNodes.size())
    throw std::runtime_error(
        "Error in ZeroLenght Element: iNodes and jNodes must have the same "
        "size.");

  if (matTags.size() != dir.size())
    throw std::runtime_error(
        "Error in ZeroLenght Element: matTags and dir must have the same "
        "size.");

  file << "# Define ZeroLength Element\n";

  for (std::size_t ii = 0; ii < iNodes.size(); ii++) {
    file << "element zeroLength " << startingTag + ii << " " << iNodes[ii]
         << " " << jNodes[ii] << " -mat ";
    for (auto mat : matTags) {
      file << mat << " ";
    }
    file << "-dir ";
    for (auto d : dir) {
      file << d << " ";
    }
    file << "\n";
  }
  file << "\n";
  file.close();
}

void BCWriter::addZeroLengthElement(const std::size_t& startingTAG,
                                    const std::size_t& iNodes,
                                    const std::size_t& jNodes,
                                    const std::vector<std::size_t>& matTags,
                                    const std::vector<std::size_t>& dir) {
  std::ofstream file(cfg_.bcFile, std::ios::app);
  if (!file) throw std::runtime_error("Cannot Open File >> " + cfg_.bcFile);

  if (matTags.size() != dir.size())
    throw std::runtime_error(
        "Error in ZeroLenght Element: matTags and dir must have the same "
        "size.");

  file << "# Define ZeroLength Element\n";

  file << "element zeroLength " << startingTAG + 1 << " " << iNodes << " "
       << jNodes << " -mat ";
  for (auto mat : matTags) {
    file << mat << " ";
  }
  file << "-dir ";
  for (auto d : dir) {
    file << d << " ";
  }

  file << "\n";
  file.close();
}

void BCWriter::addAdditionalZeroLengthElement(
    const std::size_t& startingTag, const std::vector<std::size_t>& iNodes,
    const std::vector<std::size_t>& jNodes,
    const std::vector<std::size_t>& matTags,
    const std::vector<std::size_t>& dir) {
  std::ofstream file(cfg_.analysisFile, std::ios::app);
  if (!file)
    throw std::runtime_error("Cannot Open File -> Analysis >> " +
                             cfg_.analysisFile);

  if (iNodes.size() != jNodes.size())
    throw std::runtime_error(
        "Error in ZeroLenght Element: iNodes and jNodes must have the same "
        "size.");

  if (matTags.size() != dir.size())
    throw std::runtime_error(
        "Error in ZeroLenght Element: matTags and dir must have the same "
        "size.");

  file << "# Define ZeroLength Element\n";

  for (std::size_t ii = 0; ii < iNodes.size(); ii++) {
    file << "element zeroLength " << startingTag + ii << " " << iNodes[ii]
         << " " << jNodes[ii] << " -mat ";
    for (auto mat : matTags) {
      file << mat << " ";
    }
    file << "-dir ";
    for (auto d : dir) {
      file << d << " ";
    }
    file << "\n";
  }
  file << "\n";
  file.close();
}

void BCWriter::addAdditionalZeroLengthElement(
    const std::size_t& startingTAG, const std::size_t& iNodes,
    const std::size_t& jNodes, const std::vector<std::size_t>& matTags,
    const std::vector<std::size_t>& dir) {
  std::ofstream file(cfg_.analysisFile, std::ios::app);
  if (!file)
    throw std::runtime_error("Cannot Open File -> Analysis >> " +
                             cfg_.analysisFile);

  if (matTags.size() != dir.size())
    throw std::runtime_error(
        "Error in ZeroLenght Element: matTags and dir must have the same "
        "size.");

  file << "# Define ZeroLength Element\n";

  file << "element zeroLength " << startingTAG + 1 << " " << iNodes << " "
       << jNodes << " -mat ";
  for (auto mat : matTags) {
    file << mat << " ";
  }
  file << "-dir ";
  for (auto d : dir) {
    file << d << " ";
  }

  file << "\n";
  file.close();
}

// ---- RigidDiaphram ----
void BCWriter::addRigidDiaphram(const std::size_t& direction,
                                const std::size_t& rNodeTag,
                                const std::vector<std::size_t>& cNodeTag) {
  std::ofstream file(cfg_.bcFile, std::ios::app);
  if (!file) throw std::runtime_error("Cannot Open File >> " + cfg_.bcFile);

  file << " # Define RigidDiaphram \n";
  file << "rigidDiaphragm " << direction << " " << rNodeTag << " ";

  for (auto node : cNodeTag) {
    file << node << " ";
  }

  file << "\n";
  file.close();
}

void BCWriter::addAdditionalRigidDiaphram(
    const std::size_t& direction, const std::size_t& rNodeTag,
    const std::vector<std::size_t>& cNodeTag) {
  std::ofstream file(cfg_.analysisFile, std::ios::app);
  if (!file)
    throw std::runtime_error("Cannot Open File -> Analysis >> " +
                             cfg_.analysisFile);

  file << " # Define RigidDiaphram \n";
  file << "rigidDiaphragm " << direction << " " << rNodeTag << " ";

  for (auto node : cNodeTag) {
    file << node << " ";
  }

  file << "\n";
  file.close();
}

// ---- Remove SP Fixities
void BCWriter::removeSPfix(const std::vector<std::size_t>& nodesTAG,
                           const std::vector<size_t>& dofs) {
  std::ofstream file(cfg_.analysisFile, std::ios::app);
  if (!file)
    throw std::runtime_error("Cannot Open File -> Analysis >> " +
                             cfg_.analysisFile);

  file << "# Remove SP fixities\n";
  for (int ii = 0; ii < nodesTAG.size(); ii++) {
    file << "remove sp " << nodesTAG[ii] << " ";

    for (int jj = 0; jj < dofs.size(); jj++) {
      file << dofs[jj] << " ";
    }

    file << "\n";
  }
  file.close();
}