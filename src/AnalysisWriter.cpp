#include "AnalysisWriter.h"

#include <fstream>
#include <stdexcept>

AnalysisWriter::AnalysisWriter(const Config& cfg) : cfg_(cfg) {}

// ---- Write the constraint handler
void AnalysisWriter::addConstraints(const std::string& type, double opt1,
                                    double opt2) {
  std::ofstream file(cfg_.analysisFile, std::ios::app);
  if (!file)
    throw std::runtime_error("Cannot Open File >> " + cfg_.analysisFile);

  file << "# Add Const. Handler\n";

  if (type == "Plain") {
    file << "constraints Plain\n";
  } else if (type == "Transformation") {
    file << "constraints Transformation\n";
  } else if (type == "Penalty") {
    file << "constraints Penalty " << opt1 << " " << opt2 << "\n";
  } else if (type == "Lagrange") {
    file << "constraints Lagrange " << opt1 << " " << opt2 << "\n";
  } else {
    throw std::runtime_error("Incorrect Const. Handler !!! \n");
  }

  file.close();
}

// ---- Write the numberer
void AnalysisWriter::addNumberer(const std::string& type) {
  std::ofstream file(cfg_.analysisFile, std::ios::app);
  if (!file)
    throw std::runtime_error("Cannot open Node file: " + cfg_.analysisFile);

  file << "# Add Numberer\n";

  if (type == "Plain") {
    file << "numberer Plain\n";
  } else if (type == "RCM") {
    file << "numberer RCM\n";
  } else if (type == "AMD") {
    file << "numberer AMD\n";
  } else {
    throw std::runtime_error("Incorrect Numberer !!! \n");
  }

  file.close();
}
// ---- Write system
void AnalysisWriter::addSystem(const std::string& type) {
  std::ofstream file(cfg_.analysisFile, std::ios::app);
  if (!file)
    throw std::runtime_error("Cannot open Node file: " + cfg_.analysisFile);

  file << "# Add System\n";

  if (type == "BandGeneral") {
    file << "system BandGeneral\n";
  } else if (type == "BandSPD") {
    file << "system BandSPD\n";
  } else if (type == "ProfileSPD") {
    file << "system ProfileSPD\n";
  } else if (type == "SparseGEN") {
    file << "system SparseGEN";
  } else if (type == "UmfPack") {
    file << "system UmfPack\n";
  } else if (type == "FullGeneral") {
    file << "system FullGeneral\n";
  } else if (type == "SparseSYM") {
    file << "system SparseSYM\n";
  } else if (type == "Mumps") {
    file << "system Mumps -ICNTL14 200\n";
  } else {
    throw std::runtime_error("Incorrect System !!! \n");
  }

  file.close();
}
// ---- Write test
void AnalysisWriter::addTest(const std::string& type, const double& tol,
                             const std::size_t& iter, const std::size_t& pFlag,
                             const std::size_t& nType) {
  std::ofstream file(cfg_.analysisFile, std::ios::app);
  if (!file)
    throw std::runtime_error("Cannot open Node file: " + cfg_.analysisFile);

  file << "# Add Test\n";

  if (type == "NormUnbalance") {
    file << "test NormUnbalance " << tol << " " << iter << " " << pFlag << " "
         << nType << "\n";
  } else if (type == "NormDispIncr") {
    file << "test NormDispIncr " << tol << " " << iter << " " << pFlag << " "
         << nType << "\n";
  } else if (type == "EnergyIncr") {
    file << "test EnergyIncr " << tol << " " << iter << " " << pFlag << " "
         << nType << "\n";
  } else if (type == "RelativeNormUnbalance") {
    file << "test RelativeNormUnbalance " << tol << " " << iter << " " << pFlag
         << " " << nType << "\n";
  } else if (type == "RelativeNormDispIncr") {
    file << "test RelativeNormDispIncr " << tol << " " << iter << " " << pFlag
         << " " << nType << "\n";
  } else if (type == "RelativeTotalNormDispIncr") {
    file << "test RelativeTotalNormDispIncr " << tol << " " << iter << " "
         << pFlag << " " << nType << "\n";
  } else if (type == "RelativeEnergyIncr") {
    file << "test RelativeEnergyIncr " << tol << " " << iter << " " << pFlag
         << " " << nType << "\n";
  } else if (type == "RelativeEnergyIncr") {
    file << "test RelativeEnergyIncr " << std::scientific << tol << " " << iter
         << " " << pFlag << " " << nType << "\n";
  } else if (type == "FixedNumIter ") {
    file << "test FixedNumIter  " << " " << iter << " " << pFlag << " " << nType
         << "\n";
  } else {
    throw std::runtime_error("Incorrect Test !!! \n");
  }

  file.close();
}

// ---- Write Algorithm
void AnalysisWriter::addAlgorithm(const std::string& type) {
  std::ofstream file(cfg_.analysisFile, std::ios::app);
  if (!file)
    throw std::runtime_error("Cannot open Node file: " + cfg_.analysisFile);

  file << "# Add Algorithm\n";

  if (type == "Linear") {
    file << "algorithm Linear \n";
  } else if (type == "Newton") {
    file << "algorithm Newton \n";
  } else if (type == "NewtonLineSearch") {
    file << "algorithm NewtonLineSearch \n";
  } else if (type == "ModifiedNewton") {
    file << "algorithm ModifiedNewton \n";
  } else if (type == "KrylovNewton") {
    file << "algorithm KrylovNewton \n";
  } else if (type == "SecantNewton") {
    file << "algorithm SecantNewton  \n";
  } else if (type == "SecantNewton") {
    file << "algorithm BFGS \n";
  } else if (type == "Broyden ") {
    file << "algorithm Broyden  \n";
  } else {
    throw std::runtime_error("Incorrect Agorithm !!! \n");
  }

  file.close();
}
// ---- Write Analysis command
void AnalysisWriter::addAnalysis(const std::string& type) {
  std::ofstream file(cfg_.analysisFile, std::ios::app);
  if (!file)
    throw std::runtime_error("Cannot open Node file: " + cfg_.analysisFile);

  file << "# Add Analysis command\n";
  if (type == "Static") {
    file << "analysis Static\n";
  } else if (type == "Transient") {
    file << "analysis Transient\n";
  } else if (type == "Variable Transient") {
    file << "analysis Variable Transient\n";
  } else {
    throw std::runtime_error("Incorrect Analysis Command !!! \n");
  }

  file.close();
}

// ---- Write Integrators
void AnalysisWriter::addNewmarkIntegrator(const double& gamma,
                                          const double& beta) {
  std::ofstream file(cfg_.analysisFile, std::ios::app);
  if (!file)
    throw std::runtime_error("Cannot open Node file: " + cfg_.analysisFile);

  file << "# Add Newmark Integrator command\n";
  file << "integrator Newmark " << gamma << " " << beta << "\n";

  file.close();
}

// ---- Write load or disp control
void AnalysisWriter::addLoadControl(const double& lambda,
                                    const std::size_t& iter,
                                    const double& minLambda,
                                    const double& maxLambda) {
  std::ofstream file(cfg_.analysisFile, std::ios::app);
  if (!file)
    throw std::runtime_error("Cannot open Node file: " + cfg_.analysisFile);

  file << "# Add Displacements Control command\n";
  if (minLambda == 0. && maxLambda == 0. && iter == 0.) {
    file << "integrator LoadControl " << lambda << "\n";
  } else {
    file << "integrator LoadControl " << lambda << " " << minLambda << " "
         << maxLambda << "\n";
  }
  file.close();
}

void AnalysisWriter::addDisplacementsControl(
    const std::size_t& node, const std::size_t& dof, const double& incr,
    const std::size_t& numiter, const double& minStep, const double& maxStep) {
  std::ofstream file(cfg_.analysisFile, std::ios::app);
  if (!file)
    throw std::runtime_error("Cannot open Node file: " + cfg_.analysisFile);

  file << "# Add Load Control command\n";
  if (minStep == 0. && minStep == 0.0 && maxStep == 0.0) {
    file << "integrator DisplacementControl " << node << " " << dof << " "
         << incr << "\n";
  } else {
    file << "integrator DisplacementControl " << node << " " << dof << " "
         << incr << " " << numiter << " " << minStep << " " << maxStep << "\n";
  }

  file.close();
}

// ---- Write Analysis command
void AnalysisWriter::addStaticAnalysis(const std::size_t& nSteps) {
  std::ofstream file(cfg_.analysisFile, std::ios::app);
  if (!file)
    throw std::runtime_error("Cannot open Node file: " + cfg_.analysisFile);

  file << "# Add Static Analysis command\n";
  file << "for {set ii 0} {$ii < " << nSteps << "} {incr ii} { \n";
  file << "\tanalyze 1 \n";
  file << "\tputs \"Step [expr $ii + 1]/" << nSteps << " completed\" \n";
  file << "}\n";

  file.close();
}

void AnalysisWriter::addModalAnalysis(const std::size_t& nEigVals) {
  std::ofstream file(cfg_.analysisFile, std::ios::app);
  if (!file)
    throw std::runtime_error("Cannot open Node file: " + cfg_.analysisFile);

  file << "# Add Modal Analysis command\n";
  file << "set lambda [eigen " << nEigVals << "]\n";
  file << "puts \"Natural Frequencies\"\n";
  file << "foreach lam $lambda {\n";
  file << "\t set freq [expr sqrt($lam)/(2.0*3.141592)]\n";
  file << "\tputs $freq\n }\n";

  file.close();
}

void AnalysisWriter::addModalanalysisDamping(const std::size_t& nEigVals,
                                             const std::size_t& mode_1,
                                             const std::size_t& mode_2,
                                             const double& eta) {
  std::ofstream file(cfg_.analysisFile, std::ios::app);
  if (!file)
    throw std::runtime_error("Cannot open Node file: " + cfg_.analysisFile);

  file << "# Add Modal Analysis for Rayleigh Damping command\n";
  file << "set lambda [eigen " << nEigVals << "]\n";
  file << "puts \"Natural Frequencies\"\n";
  file << "foreach lam $lambda {\n";
  file << "\t set freq [expr sqrt($lam)/(2.0*3.141592)]\n";
  file << "\tputs $freq\n }\n";

  file << "\n # Compute the Rayleigh Coefficients \n";

  file << "set lambda1 [lindex $lambda " << mode_1 - 1 << "]\n";
  file << "set lambda2 [lindex $lambda " << mode_2 - 1 << "]\n";

  file << "set omega1 [expr sqrt($lambda1)] \n";
  file << "set omega2 [expr sqrt($lambda2)] \n";

  file << "set xi " << std::fixed << std::setprecision(5) << eta << "\n";

  file << "set alphaM [expr 2.0*$xi*$omega1*$omega2 / ($omega1 + $omega2)]\n";
  file << "set betaKinit [expr 2.0*$xi / ($omega1 + $omega2)]\n";

  file << "set betaK 0.0\n";
  file << "set betaKcomm 0.0\n";
  file << "rayleigh $alphaM $betaK $betaKinit $betaKcomm\n";

  file.close();
}

void AnalysisWriter::addTransientAnalysis(const int& numSteps,
                                          const double& dt) {
  std::ofstream file(cfg_.analysisFile, std::ios::app);
  if (!file)
    throw std::runtime_error("Cannot open Node file: " + cfg_.analysisFile);

  file << "# Add Transient Analysis command\n";

  file << "for {set kk 0} {$kk < " << numSteps << " } {incr kk} { \n";
  file << "\tanalyze 1 " << dt << "\n ";
  file << "\tputs \"Step [expr $kk + 1]/ " << numSteps << " completed\" \n";
  file << "}\n";

  file.close();
}

// ---- Damping and Regions
void AnalysisWriter::addRegionDampingEle(
    const std::size_t& regionTAG, const std::vector<std::size_t>& elements,
    const double& alphaM, const double& betaKinit) {
  std::ofstream file(cfg_.analysisFile, std::ios::app);
  if (!file)
    throw std::runtime_error("Cannot open Node file: " + cfg_.analysisFile);

  file << "# Add Region for Rayleigh Damping -> Elements command\n";

  file << "region " << regionTAG << " " << "-ele ";

  for (auto ele : elements) {
    file << ele << " ";
  }

  file << "-rayleigh " << alphaM << " ";
  file << "0.0" << " " << betaKinit << " ";

  file << "0.0\n";
  file.close();
}

void AnalysisWriter::addRegionDampingNodeRange(const std::size_t regionTAG,
                                               const std::size_t& nodeRange1,
                                               const std::size_t& nodeRange2,
                                               const double& alphaM,
                                               const double& betaKinit) {
  std::ofstream file(cfg_.analysisFile, std::ios::app);
  if (!file)
    throw std::runtime_error("Cannot open Node file: " + cfg_.analysisFile);

  file << "# Add Region for Rayleigh Damping -> Nodes Range command\n";
  file << "region " << regionTAG << " " << "-nodeRange " << nodeRange1 << " "
       << nodeRange2;

  file << " -rayleigh " << alphaM << " ";
  file << "0.0" << " " << betaKinit << " ";

  file << "0.0\n";
  file.close();
}

void AnalysisWriter::addRayleigh(const double& alphaM, const double& betaK,
                                 const double& betaKinit,
                                 const double& betaKcomm) {
  std::ofstream file(cfg_.analysisFile, std::ios::app);
  if (!file)
    throw std::runtime_error("Cannot open Node file: " + cfg_.analysisFile);

  file << "# Add Region for Rayleigh Damping\n";
  file << "rayleigh " << alphaM << " ";
  file << betaK << " ";
  file << betaKinit << " ";
  file << betaKcomm << " \n";

  file.close();
}

void AnalysisWriter::wipeAnalysis() {
  std::ofstream file(cfg_.analysisFile, std::ios::app);
  if (!file)
    throw std::runtime_error("Cannot open Node file: " + cfg_.analysisFile);
  file << "# wipeAnalysis Command\n";
  file << "wipeAnalysis\n";
  file.close();
}

void AnalysisWriter::loadConst() {
  std::ofstream file(cfg_.analysisFile, std::ios::app);
  if (!file)
    throw std::runtime_error("Cannot open Node file: " + cfg_.analysisFile);
  file << "# loadConst Command\n";
  file << "loadConst -time 0.0\n";
  file.close();
}

void AnalysisWriter::domainChange() {
  std::ofstream file(cfg_.analysisFile, std::ios::app);
  if (!file)
    throw std::runtime_error("Cannot open Node file: " + cfg_.analysisFile);
  file << "# domainChange Command\n";
  file << "domainChange\n";
  file.close();
}

void AnalysisWriter::exit() {
  std::ofstream file(cfg_.analysisFile, std::ios::app);
  if (!file)
    throw std::runtime_error("Cannot open Node file: " + cfg_.analysisFile);
  file << "# exit Command\n";
  file << "exit\n";
  file.close();
}

void AnalysisWriter::addPushOver() {
  std::ofstream file(cfg_.analysisFile, std::ios::app);
  if (!file)
    throw std::runtime_error("Cannot open Node file: " + cfg_.analysisFile);

  file << "# Define Push Over Custom\n";
}