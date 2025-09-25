#ifndef ANALYSISWRITER_H
#define ANALYSISWRITER_H

#include <string>
#include <vector>

#include "Config.h"

class AnalysisWriter {
 public:
  explicit AnalysisWriter(const Config& cfg);

  // ---- Write the constraint handler
  void addConstraints(const std::string& type, double opt1 = 0.,
                      double opt2 = 0.);
  // ---- Write the numberer
  void addNumberer(const std::string& type);
  // ---- Write system
  void addSystem(const std::string& type);
  // ---- Write test
  void addTest(const std::string& type, const double& tol,
               const std::size_t& iter, const std::size_t& pFlag = 0,
               const std::size_t& nType = 0);
  // ---- Write Algorithm
  void addAlgorithm(const std::string& type);
  // ---- Write Analysis Command
  void addAnalysis(const std::string& type);
  // ---- Write Integrators
  void addNewmarkIntegrator(const double& gamma = 0.5,
                            const double& beta = 0.25);
  // ---- Write load or disp control
  void addLoadControl(const double& lambda, const std::size_t& iter = 0.,
                      const double& minLambda = 0.,
                      const double& maxLambda = 0.);

  void addDisplacementsControl(const std::size_t& node, const std::size_t& dof,
                               const double& incr,
                               const std::size_t& numiter = 0,
                               const double& minStep = 0.,
                               const double& maxStep = 0.);

  // ---- Write Analysis command
  void addStaticAnalysis(const std::size_t& nSteps);
  void addModalAnalysis(const std::size_t& nEigVals);
  void addModalanalysisDamping(const std::size_t& nEigVals,
                               const std::size_t& mode_1,
                               const std::size_t& mode_2, const double& eta);
  void addTransientAnalysis(const int& numSteps, const double& dt);
  // ---- Damping and Regions
  void addRegionDampingEle(const std::size_t& regionTAG,
                           const std::vector<std::size_t>& elements,
                           const double& alphaM, const double& betaKinit);
  void addRegionDampingNodeRange(const std::size_t regionTAG,
                                 const std::size_t& nodeRange1,
                                 const std::size_t& nodeRange2,
                                 const double& alphaM, const double& betaKinit);
  void addRayleigh(const double& alphaM, const double& betaK,
                   const double& betaKinit, const double& betaKcomm);

  // ---- Commands
  void wipeAnalysis();
  void loadConst();
  void domainChange();
  void exit();

  // ---- Custom
  void addPushOver();

 private:
  const Config& cfg_;
};

#endif  // ANALYSISWRITER_H
