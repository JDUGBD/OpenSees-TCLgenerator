#ifndef NODEWRITER_H
#define NODEWRITER_H

#include <string>
#include <vector>

#include "Config.h"

class NodeWriter {
 public:
  explicit NodeWriter(Config& cfg);

  // Methods to define a single node
  void addNode(const std::size_t& nodeTag, const std::vector<double>& coords);
  void addNode(const std::size_t& nodeTag, const std::vector<double>& coords,
               const std::size_t& ndm, const std::size_t& ndf);
  // Methods to define multiple nodes
  void addNodes(const std::vector<std::size_t>& nodeTags,
                const std::vector<std::vector<double>>& coords);

  void addNodes(const std::vector<std::size_t>& nodeTags,
                const std::vector<std::vector<double>>& coords,
                const std::size_t& ndm, const std::size_t& ndf);

  // Method to define single node after the analysis steps
  void addAdditionalNode(const std::size_t& nodeTag,
                         const std::vector<double>& coords);

  void addAdditionalNode(const std::size_t& nodeTag,
                         const std::vector<double>& coords,
                         const std::size_t& ndm, const std::size_t& ndf);

  // Methods to define multiple nodes after the analysis step
  void addAdditionalNodes(const std::vector<std::size_t>& nodeTags,
                          const std::vector<std::vector<double>>& coords);

  void addAdditionalNodes(const std::vector<std::size_t>& nodeTags,
                          const std::vector<std::vector<double>>& coords,
                          const std::size_t& ndm, const std::size_t& ndf);
  // Add Nodal Mass
  void addMass(const std::size_t& nodeTag, const std::vector<double>& massVals);
  void addMass(const std::vector<std::size_t>& nodeTags,
               const std::vector<double>& massVals);

 private:
  Config& cfg_;
};

#endif  // NODEWRITER_H
