#ifndef BCWRITER_H
#define BCWRITER_H

#include <vector>

#include "Config.h"

class BCWriter {
 public:
  explicit BCWriter(const Config& cfg);

  // ---- SP fixities ----
  void addFix(const std::size_t& nodeTag,
              const std::vector<std::size_t>& fixities);

  void addFix(const std::vector<std::size_t>& nodeTag,
              const std::vector<std::size_t>& fixities);

  void addFix(const std::vector<std::size_t>& nodeTags,
              const std::vector<std::vector<std::size_t>>& fixities);

  void addAdditionalFix(const std::size_t& nodeTag,
                        const std::vector<std::size_t>& fixities);

  void addAdditionalFix(const std::vector<std::size_t>& nodeTag,
                        const std::vector<std::size_t>& fixities);

  void addAdditionalFix(const std::vector<std::size_t>& nodeTags,
                        const std::vector<std::vector<std::size_t>>& fixities);
  // ---- MP conditions ----
  // ---- equalDOF ----
  void addEqualDof(const std::size_t& rNodeTag,
                   const std::vector<std::size_t>& cNodeTag,
                   const std::vector<std::size_t>& dofs);

  void addEqualDof(const std::vector<std::size_t>& rNodeTags,
                   const std::vector<std::size_t>& cNodeTags,
                   const std::vector<std::size_t>& dofs);

  void addAdditionalEqualDof(const std::size_t& rNodeTag,
                             const std::vector<std::size_t>& cNodeTag,
                             const std::vector<std::size_t>& dofs);

  void addAdditionalEqualDof(const std::vector<std::size_t>& rNodeTags,
                             const std::vector<std::size_t>& cNodeTags,
                             const std::vector<std::size_t>& dofs);
  // ---- rigidLinkElement ----

  void addRigidLink(const std::string& type, const std::size_t& rNodeTag,
                    const std::size_t& cNodeTag);

  void addRigidLink(const std::string& type, const std::size_t& rNodeTag,
                    const std::vector<std::size_t>& cNodeTags);

  void addRigidLink(const std::string& type,
                    const std::vector<std::size_t>& rNodeTags,
                    const std::vector<std::size_t>& cNodeTags);

  void addAdditionalRigidLink(const std::string& type,
                              const std::size_t& rNodeTag,
                              const std::size_t& cNodeTag);

  void addAdditionalRigidLink(const std::string& type,
                              const std::size_t& rNodeTag,
                              const std::vector<std::size_t>& cNodeTags);

  void addAdditionalRigidLink(const std::string& type,
                              const std::vector<std::size_t>& rNodeTags,
                              const std::vector<std::size_t>& cNodeTags);

  // ---- Zero Length Element ----

  void addZeroLengthElement(const std::size_t& startingTag,
                            const std::vector<std::size_t>& iNodes,
                            const std::vector<std::size_t>& jNodes,
                            const std::vector<std::size_t>& matTags,
                            const std::vector<std::size_t>& dir);

  void addZeroLengthElement(const std::size_t& startingTAG,
                            const std::size_t& iNodes,
                            const std::size_t& jNodes,
                            const std::vector<std::size_t>& matTags,
                            const std::vector<std::size_t>& dir);

  void addAdditionalZeroLengthElement(const std::size_t& startingTag,
                                      const std::vector<std::size_t>& iNodes,
                                      const std::vector<std::size_t>& jNodes,
                                      const std::vector<std::size_t>& matTags,
                                      const std::vector<std::size_t>& dir);

  void addAdditionalZeroLengthElement(const std::size_t& startingTAG,
                                      const std::size_t& iNodes,
                                      const std::size_t& jNodes,
                                      const std::vector<std::size_t>& matTags,
                                      const std::vector<std::size_t>& dir);

  // ---- RigidDiaphram ----
  void addRigidDiaphram(const std::size_t& direction,
                        const std::size_t& rNodeTag,
                        const std::vector<std::size_t>& cNodeTag);

  void addAdditionalRigidDiaphram(const std::size_t& direction,
                                  const std::size_t& rNodeTag,
                                  const std::vector<std::size_t>& cNodeTag);

  // ---- Remove SP Fixities
  void removeSPfix(const std::vector<std::size_t>& nodesTAG,
                   const std::vector<size_t>& dofs);

 private:
  const Config& cfg_;
};

#endif