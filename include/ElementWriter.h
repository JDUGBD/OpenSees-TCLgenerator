#ifndef ELEMENTWRITER_H
#define ELEMENTWRITER_H

#include <fstream>
#include <iomanip>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

#include "Config.h"

class ElementWriter {
 public:
  explicit ElementWriter(const Config& cfg);

  // ---- Basic Elements ----
  // ---- Truss Elements ----
  void addTrussElement(const std::size_t& tag, const std::size_t& iNode,
                       const std::size_t& jNode, const double& A,
                       const std::size_t& matTag, const double& rho = 0.,
                       const std::size_t& cFlag = 0,
                       const std::size_t& rFlag = 0);

  void addAdditionalTrussElement(const std::size_t& tag,
                                 const std::size_t& iNode,
                                 const std::size_t& jNode, const double& A,
                                 const std::size_t& matTag,
                                 const double& rho = 0.,
                                 const std::size_t& cFlag = 0,
                                 const std::size_t& rFlag = 0);
  // ---- Truss with section identifier
  void addTrussSectionElement(const std::size_t& tag, const std::size_t& iNode,
                              const std::size_t& jNode,
                              const std::size_t& secTag, const double& rho = 0.,
                              const std::size_t& cFlag = 0,
                              const std::size_t& rFlag = 0);

  void addAdditionalTrussSectionElement(const std::size_t& tag,
                                        const std::size_t& iNode,
                                        const std::size_t& jNode,
                                        const std::size_t& secTag,
                                        const double& rho = 0.,
                                        const std::size_t& cFlag = 0,
                                        const std::size_t& rFlag = 0);
  // ---- set Transofrmations for Elements
  // ---- 2D Linear Transformation
  void addLinearTransformation2D(const std::size_t& transfTag,
                                 const double& dXi = 0., const double& dYi = 0.,
                                 const double& dXj = 0.,
                                 const double& dYj = 0.);
  // ---- 3D Linear Transformation
  void addLinearTransformation3D(const std::size_t& transfTag,
                                 const double& vecxzX, const double& vecxzY,
                                 const double& vecxzZ, const double& dXi = 0.,
                                 const double& dYi = 0., const double& dZi = 0.,
                                 const double& dXj = 0., const double& dYj = 0.,
                                 const double& dZj = 0.);
  // ---- 2D PDelta Transformation
  void addPDeltaTransformation2D(const std::size_t& transfTag,
                                 const double& dXi = 0., const double& dYi = 0.,
                                 const double& dXj = 0.,
                                 const double& dYj = 0.);
  // ---- 3D PDelta Transformation
  void addPDeltaTransformation3D(const std::size_t& transfTag,
                                 const double& vecxzX, const double& vecxzY,
                                 const double& vecxzZ, const double& dXi = 0.,
                                 const double& dYi = 0., const double& dZi = 0.,
                                 const double& dXj = 0., const double& dYj = 0.,
                                 const double& dZj = 0.);
  // ---- 2D Corotational Transformation
  void addCorotationalTransformation2D(const std::size_t& transfTag,
                                       const double& dXi = 0.,
                                       const double& dYi = 0.,
                                       const double& dXj = 0.,
                                       const double& dYj = 0.);
  // ---- 3D PDelta Transformation
  void addCorotationalTransformation3D(const std::size_t& transfTag,
                                       const double& vecxzX,
                                       const double& vecxzY,
                                       const double& vecxzZ);

  // ---- ElasticBeamColumnElement ----
  // ---- 2D definition ----
  void addElasticBeamColumnElement(const std::size_t& tag,
                                   const std::size_t& iNode,
                                   const std::size_t& jNode, const double& A,
                                   const double& E, const double& Iz,
                                   const std::size_t& transfTag,
                                   const double& massDens = 0.0,
                                   const std::size_t& cMass = 0);

  void addAdditionalElasticBeamColumnElement(
      const std::size_t& tag, const std::size_t& iNode,
      const std::size_t& jNode, const double& A, const double& E,
      const double& Iz, const std::size_t& transfTag,
      const double& massDens = 0.0, const std::size_t& cMass = 0);
  // ---- 3D definition

  void addElasticBeamColumnElement(
      const std::size_t& tag, const std::size_t& iNode,
      const std::size_t& jNode, const double& A, const double& E,
      const double& G, const double& J, const double& Iy, const double& Iz,
      const std::size_t& transfTag, const double& massDens = 0.0,
      const std::size_t& cMass = 0);

  void addAdditionalElasticBeamColumnElement(
      const std::size_t& tag, const std::size_t& iNode,
      const std::size_t& jNode, const double& A, const double& E,
      const double& G, const double& J, const double& Iy, const double& Iz,
      const std::size_t& transfTag, const double& massDens = 0.0,
      const std::size_t& cMass = 0);
  // ---- 2D and 3D definition with a section def
  void addElasticBeamColumnElement(const std::size_t& tag,
                                   const std::size_t& iNode,
                                   const std::size_t& jNode,
                                   const std::size_t& secTag,
                                   const std::size_t& transfTag,
                                   const double& massDens = 0.0,
                                   const std::size_t& cMass = 0);

  void addElasticBeamColumnElement(
      const std::vector<std::size_t>& tag,
      const std::vector<std::vector<std::size_t>>& Nodes,
      const std::size_t& secTag, const std::size_t& transfTag,
      const double& massDens = 0.0, const std::size_t& cMass = 0);

  void addAdditionalElasticBeamColumnElement(const std::size_t& tag,
                                             const std::size_t& iNode,
                                             const std::size_t& jNode,
                                             const std::size_t& secTag,
                                             const std::size_t& transfTag,
                                             const double& massDens = 0.0,
                                             const std::size_t& cMass = 0);

  void addAdditionalElasticBeamColumnElement(
      const std::vector<std::size_t>& tag,
      const std::vector<std::vector<std::size_t>>& Nodes,
      const std::size_t& secTag, const std::size_t& transfTag,
      const double& massDens = 0.0, const std::size_t& cMass = 0);

  // ---- ElasticBeamColumnElement ----

  void addforceBeamColumnElement(
      const std::vector<std::size_t>& tag,
      const std::vector<std::vector<std::size_t>>& Nodes,
      const std::size_t numIntgrPts, const std::size_t& secTag,
      const std::size_t& transfTag, const double& massDens = 0.0);

  void addAdditionalforceBeamColumnElement(
      const std::vector<std::size_t>& tag,
      const std::vector<std::vector<std::size_t>>& Nodes,
      const std::size_t numIntgrPts, const std::size_t& secTag,
      const std::size_t& transfTag, const double& massDens = 0.0);

  // ---- DispBeamColumnElement ----
  void adddispBeamColumnElement(
      const std::vector<std::size_t>& tag,
      const std::vector<std::vector<std::size_t>>& Nodes,
      const std::size_t numIntgrPts, const std::size_t& secTag,
      const std::size_t& transfTag, const double& massDens = 0.0);

  void addAdditionaldispBeamColumnElement(
      const std::vector<std::size_t>& tag,
      const std::vector<std::vector<std::size_t>>& Nodes,
      const std::size_t numIntgrPts, const std::size_t& secTag,
      const std::size_t& transfTag, const double& massDens = 0.0);

  // ---- 2D Elements ----
  // ---- Quad ----
  void addQuadElement(const std::size_t& tag, const std::size_t& iNode,
                      const std::size_t& jNode, const std::size_t& kNode,
                      const std::size_t& lNode, const double& thick,
                      const std::string& type, const std::size_t& matTag,
                      const double& pressure = 0., const double& rho = 0.,
                      const double& b1 = 0., const double& b2 = 0.);

  void addAdditionalQuadElement(
      const std::size_t& tag, const std::size_t& iNode,
      const std::size_t& jNode, const std::size_t& kNode,
      const std::size_t& lNode, const double& thick, const std::string& type,
      const std::size_t& matTag, const double& pressure = 0.,
      const double& rho = 0., const double& b1 = 0., const double& b2 = 0.);

  // ---- QuadSSP ----
  void addSSPQuadElement(const std::size_t& tag, const std::size_t& iNode,
                         const std::size_t& jNode, const std::size_t& kNode,
                         const std::size_t& lNode, const double& thick,
                         const std::string& type, const std::size_t& matTag,
                         const double& rho = 0., const double& b1 = 0.,
                         const double& b2 = 0.);

  void addAdditionalSSPQuadElement(
      const std::size_t& tag, const std::size_t& iNode,
      const std::size_t& jNode, const std::size_t& kNode,
      const std::size_t& lNode, const double& thick, const std::string& type,
      const std::size_t& matTag, const double& rho = 0., const double& b1 = 0.,
      const double& b2 = 0.);

 private:
  const Config& cfg_;
};

#endif  // ELEMENTWRITER_H
