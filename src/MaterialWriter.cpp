#include "MaterialWriter.h"

MaterialWriter::MaterialWriter(const Config& cfg) : cfg_(cfg) {}

//-------------- nDMaterials --------------
//-------------- ElasticIsotropic --------------
void MaterialWriter::addElasticIsotropic(const std::size_t& tag,
                                         const double& E, const double& nu,
                                         const double& rho) {
  std::ofstream file(cfg_.materialsFile, std::ios::app);
  if (!file) throw std::runtime_error("Cannot open Material file");
  file << "nDMaterial ElasticIsotropic " << tag << " " << std::fixed
       << std::setprecision(cfg_.precision) << E << " " << nu;

  if (rho != 0.0) file << " " << rho;
  file << "\n";

  file.close();
}

void MaterialWriter::addAdditionalElasticIsotropic(const std::size_t& tag,
                                                   const double& E,
                                                   const double& nu,
                                                   const double& rho) {
  std::ofstream file(cfg_.analysisFile, std::ios::app);
  if (!file) throw std::runtime_error("Cannot open Material file -> Analysis");
  file << "nDMaterial ElasticIsotropic " << tag << " " << std::fixed
       << std::setprecision(cfg_.precision) << E << " " << nu;

  if (rho != 0.0) file << " " << rho;
  file << "\n";

  file.close();
}

//-------------- Uniaxial Materials --------------
//-------------- Elastic --------------
void MaterialWriter::addUniaxialElasticMaterial(const std::size_t& tag,
                                                const double& E) {
  std::ofstream file(cfg_.materialsFile, std::ios::app);
  if (!file) throw std::runtime_error("Cannot open Material file-> Analysis");
  file << "uniaxialMaterial Elastic " << tag << " " << E << "\n";
  file.close();
}

void MaterialWriter::addAdditionalUniaxialElasticMaterial(
    const std::size_t& tag, const double& E) {
  std::ofstream file(cfg_.analysisFile, std::ios::app);
  if (!file) throw std::runtime_error("Cannot open Material file");
  file << "uniaxialMaterial Elastic " << tag << " " << E << "\n";
  file.close();
}

//-------------- Steel01 --------------
void MaterialWriter::addUniaxialMaterialSteel01(
    const std::size_t& tag, const double& Fy, const double& E0, const double& b,
    const double& a1, const double& a2, const double& a3, const double& a4) {
  std::ofstream file(cfg_.materialsFile, std::ios::app);
  if (!file) throw std::runtime_error("Cannot open Material file");

  file << "uniaxialMaterial Steel01 " << tag << " " << Fy << " " << E0 << " "
       << b << " " << a1 << " " << a2 << " " << a3 << " " << a4 << "\n";
  file.close();
}

void MaterialWriter::addAdditionalUniaxialMaterialSteel01(
    const std::size_t& tag, const double& Fy, const double& E0, const double& b,
    const double& a1, const double& a2, const double& a3, const double& a4) {
  std::ofstream file(cfg_.analysisFile, std::ios::app);
  if (!file) throw std::runtime_error("Cannot open Material file -> Analysis");

  file << "uniaxialMaterial Steel01 " << tag << " " << Fy << " " << E0 << " "
       << b << " " << a1 << " " << a2 << " " << a3 << " " << a4 << "\n";
  file.close();
}

//-------------- Steel02 --------------
void MaterialWriter::addUniaxialMaterialSteel02(
    const std::size_t& tag, const double& Fy, const double& E0, const double& b,
    const double& R0, const double& cR1, const double& cR2, const double& a1,
    const double& a2, const double& a3, const double& a4,
    const double& sigInit) {
  std::ofstream file(cfg_.materialsFile, std::ios::app);
  if (!file) throw std::runtime_error("Cannot open Material file");

  file << "uniaxialMaterial Steel02 " << tag << " " << Fy << " " << E0 << " "
       << b << " " << R0 << " " << cR1 << " " << cR2 << " " << a1 << " " << a2
       << " " << a3 << " " << a4 << " " << sigInit << "\n";
  file.close();
}

void MaterialWriter::addAdditionalUniaxialMaterialSteel02(
    const std::size_t& tag, const double& Fy, const double& E0, const double& b,
    const double& R0, const double& cR1, const double& cR2, const double& a1,
    const double& a2, const double& a3, const double& a4,
    const double& sigInit) {
  std::ofstream file(cfg_.analysisFile, std::ios::app);
  if (!file) throw std::runtime_error("Cannot open Material file -> Analysis");
  file << "uniaxialMaterial Steel02 " << tag << " " << Fy << " " << E0 << " "
       << b << " " << R0 << " " << cR1 << " " << cR2 << " " << a1 << " " << a2
       << " " << a3 << " " << a4 << " " << sigInit << "\n";
  file.close();
}

//-------------- Concrete01 --------------
void MaterialWriter::addUniaxialMaterialConcrete01(const std::size_t& tag,
                                                   const double fpc,
                                                   const double epsc0,
                                                   const double fpcu,
                                                   const double epscu) {
  std::ofstream file(cfg_.materialsFile, std::ios::app);
  if (!file) throw std::runtime_error("Cannot open Material file");
  file << "uniaxialMaterial Concrete01 " << tag << " " << fpc << " " << epsc0
       << " " << fpcu << " " << epscu << "\n";
  file.close();
}

void MaterialWriter::addAdditionalUniaxialMaterialConcrete01(
    const std::size_t& tag, const double fpc, const double epsc0,
    const double fpcu, const double epscu) {
  std::ofstream file(cfg_.analysisFile, std::ios::app);
  if (!file) throw std::runtime_error("Cannot open Material file -> Analysis");
  file << "uniaxialMaterial Concrete01 " << tag << " " << fpc << " " << epsc0
       << " " << fpcu << " " << epscu << "\n";
  file.close();
}

//-------------- Concrete02 --------------
void MaterialWriter::addUniaxialMaterialConcrete02(
    const std::size_t& tag, const double& fpc, const double& epsc0,
    const double& fpcu, const double& epscu, const double& lambda,
    const double& ft, const double& Ets) {
  std::ofstream file(cfg_.materialsFile, std::ios::app);
  if (!file) throw std::runtime_error("Cannot open Material file");
  file << "uniaxialMaterial Concrete02 " << tag << " " << fpc << " " << epsc0
       << " " << fpcu << " " << epscu << " " << lambda << " " << ft << " "
       << Ets << "\n";
  file.close();
}

void MaterialWriter::addAdditionalUniaxialMaterialConcrete02(
    const std::size_t& tag, const double& fpc, const double& epsc0,
    const double& fpcu, const double& epscu, const double& lambda,
    const double& ft, const double& Ets) {
  std::ofstream file(cfg_.analysisFile, std::ios::app);
  if (!file) throw std::runtime_error("Cannot open Material file -> Analysis");
  file << "uniaxialMaterial Concrete02 " << tag << " " << fpc << " " << epsc0
       << " " << fpcu << " " << epscu << " " << lambda << " " << ft << " "
       << Ets << "\n";
  file.close();
}

//-------------- Hardening --------------
void MaterialWriter::addUniaxialMaterialHardening(const std::size_t& tag,
                                                  const double& E,
                                                  const double& fy,
                                                  const double& Hiso,
                                                  const double& Hkin) {
  std::ofstream file(cfg_.materialsFile, std::ios::app);
  if (!file) throw std::runtime_error("Cannot open Material file");

  file << "uniaxialMaterial Hardening " << tag << " " << E << " " << fy << " "
       << Hiso << " " << Hkin << "\n";
  file.close();
}

void MaterialWriter::addAdditionalUniaxialMaterialHardening(
    const std::size_t& tag, const double& E, const double& fy,
    const double& Hiso, const double& Hkin) {
  std::ofstream file(cfg_.analysisFile, std::ios::app);
  if (!file) throw std::runtime_error("Cannot open Material file -> Analysis");

  file << "uniaxialMaterial Hardening " << tag << " " << E << " " << fy << " "
       << Hiso << " " << Hkin << "\n";
  file.close();
}