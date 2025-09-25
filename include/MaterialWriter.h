#ifndef MATERIALWRITER_H
#define MATERIALWRITER_H

#include <fstream>
#include <iomanip>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

#include "Config.h"

class MaterialWriter {
 public:
  explicit MaterialWriter(const Config& cfg);

  //-------------- nDMaterials --------------
  void addElasticIsotropic(const std::size_t& tag, const double& E,
                           const double& nu, const double& rho = 0.0);

  void addAdditionalElasticIsotropic(const std::size_t& tag, const double& E,
                                     const double& nu, const double& rho = 0.0);

  //-------------- Uniaxial Materials --------------
  //-------------- Elastic --------------
  void addUniaxialElasticMaterial(const std::size_t& tag, const double& E);

  void addAdditionalUniaxialElasticMaterial(const std::size_t& tag,
                                            const double& E);

  //-------------- Steel01 --------------
  void addUniaxialMaterialSteel01(const std::size_t& tag, const double& Fy,
                                  const double& E0, const double& b,
                                  const double& a1 = 0.0,
                                  const double& a2 = 1.0,
                                  const double& a3 = 0.0,
                                  const double& a4 = 1.0);

  void addAdditionalUniaxialMaterialSteel01(
      const std::size_t& tag, const double& Fy, const double& E0,
      const double& b, const double& a1 = 0.0, const double& a2 = 1.0,
      const double& a3 = 0.0, const double& a4 = 1.0);
  //-------------- Steel02 --------------
  void addUniaxialMaterialSteel02(
      const std::size_t& tag, const double& Fy, const double& E0,
      const double& b = 0.01, const double& R0 = 20.0,
      const double& cR1 = 0.925, const double& cR2 = 0.15,
      const double& a1 = 0.0, const double& a2 = 1.0, const double& a3 = 0.0,
      const double& a4 = 1.0, const double& sigInit = 0.0);

  void addAdditionalUniaxialMaterialSteel02(
      const std::size_t& tag, const double& Fy, const double& E0,
      const double& b = 0.01, const double& R0 = 20.0,
      const double& cR1 = 0.925, const double& cR2 = 0.15,
      const double& a1 = 0.0, const double& a2 = 1.0, const double& a3 = 0.0,
      const double& a4 = 1.0, const double& sigInit = 0.0);

  //-------------- Concrete01 --------------

  void addUniaxialMaterialConcrete01(const std::size_t& tag, const double fpc,
                                     const double epsc0, const double fpcu,
                                     const double epscu);

  void addAdditionalUniaxialMaterialConcrete01(const std::size_t& tag,
                                               const double fpc,
                                               const double epsc0,
                                               const double fpcu,
                                               const double epscu);

  //-------------- Concrete02 --------------

  void addUniaxialMaterialConcrete02(const std::size_t& tag, const double& fpc,
                                     const double& epsc0, const double& fpcu,
                                     const double& epscu, const double& lambda,
                                     const double& ft, const double& Ets);

  void addAdditionalUniaxialMaterialConcrete02(
      const std::size_t& tag, const double& fpc, const double& epsc0,
      const double& fpcu, const double& epscu, const double& lambda,
      const double& ft, const double& Ets);

  //-------------- Hardening --------------

  void addUniaxialMaterialHardening(const std::size_t& tag, const double& E,
                                    const double& fy, const double& Hiso,
                                    const double& Hkin);

  void addAdditionalUniaxialMaterialHardening(const std::size_t& tag,
                                              const double& E, const double& fy,
                                              const double& Hiso,
                                              const double& Hkin);

 private:
  const Config& cfg_;
};

#endif  // MATERIALWRITER_H
