#ifndef SECTIONWRIER_H
#define SECTIONWRITER_H

#include <fstream>
#include <iomanip>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

#include "Config.h"

class SectionWriter {
 public:
  explicit SectionWriter(const Config& cgf);

  // ---- Write ElasticSection
  void addElasticSection(const std::size_t& secTag, const double& E,
                         const double& A, const double& Iz,
                         const double& G = 0., const double& alphaY = 0.);

  void addElasticSection(const std::size_t& secTag, const double& E,
                         const double& A, const double& Iz, const double& Iy,
                         const double& G, const double& J,
                         const double& alphaY = 0., const double& alphaZ = 0.);

  // ---- Write Wide Flange Section

  void addWFSection2d(const std::size_t& secTag, const std::size_t& matTag,
                      const double& d, const double& tw, const double& bf,
                      const double& tf, const std::size_t& nfw,
                      const std::size_t& Nff);

  void addWFSection3d(const std::size_t& secTag, const std::size_t& matTag,
                      const double& d, const double& bf, const double& tf,
                      const double& tw, const std::size_t& nfdw,
                      const std::size_t& nftw, const std::size_t& nfbf,
                      const std::size_t& nftf);

  void addWFSection3d(const std::size_t& secTag, const std::size_t& matTag,
                      const double& GJ, const double& d, const double& bf,
                      const double& tf, const double& tw,
                      const std::size_t& nfdw, const std::size_t& nftw,
                      const std::size_t& nfbf, const std::size_t& nftf);

  // -- Write RC Section
  void addRCSection2d(const std::size_t& secTag, const double& coreTag,
                      const double& coverTag, const double& steelTag,
                      const double& d, const double& b, const double& cover,
                      const double& Atop, const double& Abot,
                      const double& Aside, const double& Nfcore,
                      const double& Nfcover, const double& Nfs);

  // ---- Write section aggregator
  void addSectionAggregator(const std::size_t& secTag,
                            const std::vector<std::size_t>& matTags,
                            const std::vector<std::string>& dofs,
                            const std::size_t& sectionTag = 0);

  void addSectionAggregator(const std::size_t& secTag,
                            const std::size_t& matTags, const std::string& dofs,
                            const std::size_t& sectionTag = 0);

 private:
  const Config& cfg_;
};

#endif