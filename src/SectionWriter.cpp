#include "SectionWriter.h"

SectionWriter::SectionWriter(const Config& cfg) : cfg_(cfg) {}

void SectionWriter::addElasticSection(const std::size_t& secTag,
                                      const double& E, const double& A,
                                      const double& Iz, const double& G,
                                      const double& alphaY) {
  std::ofstream file(cfg_.elementsFile, std::ios::app);
  if (!file)
    throw std::runtime_error("Cannot Open File >> " + cfg_.elementsFile);

  file << "# Define elastic Section\n";
  file << "section Elastic " << secTag << " " << E << " " << A << " " << Iz;

  if (G != 0.) {
    file << " " << G;
  }
  if (G != 0. && alphaY != 0.) {
    file << " " << alphaY;
  }

  file << "\n";
  file.close();
}

void SectionWriter::addElasticSection(const std::size_t& secTag,
                                      const double& E, const double& A,
                                      const double& Iz, const double& Iy,
                                      const double& G, const double& J,
                                      const double& alphaY,
                                      const double& alphaZ) {
  std::ofstream file(cfg_.elementsFile, std::ios::app);
  if (!file)
    throw std::runtime_error("Cannot Open File >> " + cfg_.elementsFile);

  file << "# Define elastic Section\n";
  file << "section Elastic " << secTag << " " << E << " " << A << " " << Iz
       << " " << Iy << " ";
  file << G << " " << J;

  if (alphaY != 0.) {
    file << " " << alphaY;
  }
  if (alphaY != 0. && alphaZ != 0.) {
    file << " " << alphaZ;
  }

  file << "\n";
  file.close();
}

// ---- Write Wide Flange Section

void SectionWriter::addWFSection2d(const std::size_t& secTag,
                                   const std::size_t& matTag, const double& d,
                                   const double& tw, const double& bf,
                                   const double& tf, const std::size_t& nfw,
                                   const std::size_t& Nff) {
  std::ofstream file(cfg_.elementsFile, std::ios::app);
  if (!file)
    throw std::runtime_error("Cannot Open File >> " + cfg_.elementsFile);

  file << "# Define Wide Flange Section\n";
  file << "section WFSection2d " << secTag << " " << matTag << " " << d << " "
       << tw << " " << bf << " " << tf << " " << nfw << " " << Nff << "\n";
  file.close();
}

void SectionWriter::addWFSection3d(const std::size_t& secTag,
                                   const std::size_t& matTag, const double& d,
                                   const double& bf, const double& tf,
                                   const double& tw, const std::size_t& nfdw,
                                   const std::size_t& nftw,
                                   const std::size_t& nfbf,
                                   const std::size_t& nftf) {
  std::ofstream file(cfg_.elementsFile, std::ios::app);
  if (!file)
    throw std::runtime_error("Cannot Open File >> " + cfg_.elementsFile);

  file << "# Define Wide Flange Section 3D\n";
  double dw = d - 2.0 * tf;
  double y1 = -d / 2.0;
  double y2 = -dw / 2.0;
  double y3 = dw / 2.0;
  double y4 = d / 2.0;

  double z1 = -bf / 2.0;
  double z2 = -tw / 2.0;
  double z3 = tw / 2.0;
  double z4 = bf / 2.0;

  // Write the section fiber definition
  file << "section Fiber " << secTag << " {\n";
  file << "    patch quadr " << matTag << " " << nfbf << " " << nftf << " "
       << y1 << " " << z4 << " " << y1 << " " << z1 << " " << y2 << " " << z1
       << " " << y2 << " " << z4 << "\n";

  file << "    patch quadr " << matTag << " " << nftw << " " << nfdw << " "
       << y2 << " " << z3 << " " << y2 << " " << z2 << " " << y3 << " " << z2
       << " " << y3 << " " << z3 << "\n";

  file << "    patch quadr " << matTag << " " << nfbf << " " << nftf << " "
       << y3 << " " << z4 << " " << y3 << " " << z1 << " " << y4 << " " << z1
       << " " << y4 << " " << z4 << "\n";

  file << "}\n";
  file.close();
}

void SectionWriter::addWFSection3d(
    const std::size_t& secTag, const std::size_t& matTag, const double& GJ,
    const double& d, const double& bf, const double& tf, const double& tw,
    const std::size_t& nfdw, const std::size_t& nftw, const std::size_t& nfbf,
    const std::size_t& nftf) {
  std::ofstream file(cfg_.elementsFile, std::ios::app);
  if (!file)
    throw std::runtime_error("Cannot Open File >> " + cfg_.elementsFile);

  file << "# Define Wide Flange Section 3D\n";
  double dw = d - 2.0 * tf;
  double y1 = -d / 2.0;
  double y2 = -dw / 2.0;
  double y3 = dw / 2.0;
  double y4 = d / 2.0;

  double z1 = -bf / 2.0;
  double z2 = -tw / 2.0;
  double z3 = tw / 2.0;
  double z4 = bf / 2.0;

  // Write the section fiber definition
  file << "section Fiber " << secTag << " -GJ " << GJ << " {\n";
  file << "    patch quadr " << matTag << " " << nfbf << " " << nftf << " "
       << y1 << " " << z4 << " " << y1 << " " << z1 << " " << y2 << " " << z1
       << " " << y2 << " " << z4 << "\n";

  file << "    patch quadr " << matTag << " " << nftw << " " << nfdw << " "
       << y2 << " " << z3 << " " << y2 << " " << z2 << " " << y3 << " " << z2
       << " " << y3 << " " << z3 << "\n";

  file << "    patch quadr " << matTag << " " << nfbf << " " << nftf << " "
       << y3 << " " << z4 << " " << y3 << " " << z1 << " " << y4 << " " << z1
       << " " << y4 << " " << z4 << "\n";

  file << "}\n";
  file.close();
}

// -- Write RC Section
void SectionWriter::addRCSection2d(const std::size_t& secTag,
                                   const double& coreTag,
                                   const double& coverTag,
                                   const double& steelTag, const double& d,
                                   const double& b, const double& cover,
                                   const double& Atop, const double& Abot,
                                   const double& Aside, const double& Nfcore,
                                   const double& Nfcover, const double& Nfs) {
  std::ofstream file(cfg_.elementsFile, std::ios::app);
  if (!file)
    throw std::runtime_error("Cannot Open File >> " + cfg_.elementsFile);

  file << "# Define RC Section\n";
  file << "section RCSection2d " << secTag << " " << coreTag << " " << coverTag
       << " " << steelTag << " " << d << " " << b << " " << cover << " " << Atop
       << " " << Abot << " " << Aside << " " << Nfcore << " " << Nfcover << " "
       << Nfs << "\n";

  file.close();
}

// ---- Write Seciton Aggregator ----
void SectionWriter::addSectionAggregator(
    const std::size_t& secTag, const std::vector<std::size_t>& matTags,
    const std::vector<std::string>& dofs, const std::size_t& sectionTag) {
  std::ofstream file(cfg_.elementsFile, std::ios::app);
  if (!file)
    throw std::runtime_error("Cannot Open File >> " + cfg_.elementsFile);

  file << "# Define Section Aggregator\n";
  file << "section Aggregator " << secTag << " ";

  for (auto mat : matTags) {
    file << mat << " ";
  }

  for (auto d : dofs) {
    file << d << " ";
  }

  if (sectionTag != 0) {
    file << "-section " << sectionTag;
  }

  file << "\n";
  file.close();
}

void SectionWriter::addSectionAggregator(const std::size_t& secTag,
                                         const std::size_t& matTags,
                                         const std::string& dofs,
                                         const std::size_t& sectionTag) {
  std::ofstream file(cfg_.elementsFile, std::ios::app);
  if (!file)
    throw std::runtime_error("Cannot Open File >> " + cfg_.elementsFile);

  file << "# Define Section Aggregator\n";
  file << "section Aggregator ";
  file << secTag << " " << matTags << " " << dofs;

  if (sectionTag != 0) {
    file << " -section " << sectionTag;
  }

  file << "\n";
  file.close();
}