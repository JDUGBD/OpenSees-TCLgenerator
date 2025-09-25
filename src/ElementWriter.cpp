#include "ElementWriter.h"

ElementWriter::ElementWriter(const Config& cfg) : cfg_(cfg) {}

// ---- Basic Elements ----
// ---- Truss Elements ----
void ElementWriter::addTrussElement(const std::size_t& tag,
                                    const std::size_t& iNode,
                                    const std::size_t& jNode, const double& A,
                                    const std::size_t& matTag,
                                    const double& rho, const std::size_t& cFlag,
                                    const std::size_t& rFlag) {
  std::ofstream file(cfg_.elementsFile, std::ios::app);
  if (!file)
    throw std::runtime_error("Cannot Open File >> " + cfg_.elementsFile);

  file << "# Element Truss Definition \n";
  file << "element truss " << tag << " " << iNode << " " << jNode << " " << A
       << " " << matTag;

  if (rho != 0.0) {
    file << " -rho " << rho;
  }

  if (cFlag) {
    file << " -cMass " << cFlag;
  }

  if (rFlag) {
    file << " -doRayleigh " << rFlag;
  }
  file << "\n";
  file.close();
}

void ElementWriter::addAdditionalTrussElement(
    const std::size_t& tag, const std::size_t& iNode, const std::size_t& jNode,
    const double& A, const std::size_t& matTag, const double& rho,
    const std::size_t& cFlag, const std::size_t& rFlag) {
  std::ofstream file(cfg_.analysisFile, std::ios::app);
  if (!file)
    throw std::runtime_error(
        "Cannot Open File Cannot Open File -> Analysis >> " +
        cfg_.analysisFile);

  file << "# Element Truss Definition \n";
  file << "element truss " << tag << " " << iNode << " " << jNode << " " << A
       << " " << matTag;

  if (rho != 0.0) {
    file << " -rho " << rho;
  }

  if (cFlag) {
    file << " -cMass " << cFlag;
  }

  if (rFlag) {
    file << " -doRayleigh " << rFlag;
  }
  file << "\n";
  file.close();
}

//---- Truss with section identifier
void ElementWriter::addTrussSectionElement(
    const std::size_t& tag, const std::size_t& iNode, const std::size_t& jNode,
    const std::size_t& secTag, const double& rho, const std::size_t& cFlag,
    const std::size_t& rFlag) {
  std::ofstream file(cfg_.elementsFile, std::ios::app);
  if (!file)
    throw std::runtime_error("Cannot Open File -> Analysis >> " +
                             cfg_.elementsFile);

  file << "# Element Truss Definition \n";
  file << "element truss " << tag << " " << iNode << " " << jNode << " "
       << secTag;

  if (rho != 0.0) {
    file << " -rho " << rho;
  }

  if (cFlag) {
    file << " -cMass " << cFlag;
  }

  if (rFlag) {
    file << " -doRayleigh " << rFlag;
  }
  file << "\n";
  file.close();
}

void ElementWriter::addAdditionalTrussSectionElement(
    const std::size_t& tag, const std::size_t& iNode, const std::size_t& jNode,
    const std::size_t& secTag, const double& rho, const std::size_t& cFlag,
    const std::size_t& rFlag) {
  std::ofstream file(cfg_.analysisFile, std::ios::app);
  if (!file)
    throw std::runtime_error("Cannot Open File -> Analysis >> " +
                             cfg_.analysisFile);

  file << "# Element Truss Definition \n";
  file << "element truss " << tag << " " << iNode << " " << jNode << " "
       << secTag;

  if (rho != 0.0) {
    file << " -rho " << rho;
  }

  if (cFlag) {
    file << " -cMass " << cFlag;
  }

  if (rFlag) {
    file << " -doRayleigh " << rFlag;
  }
  file << "\n";
  file.close();
}

// ---- ElasticBeamColumnElement ----
// ---- 2D definition ----
void ElementWriter::addElasticBeamColumnElement(
    const std::size_t& tag, const std::size_t& iNode, const std::size_t& jNode,
    const double& A, const double& E, const double& Iz,
    const std::size_t& transfTag, const double& massDens,
    const std::size_t& cMass) {
  std::ofstream file(cfg_.elementsFile, std::ios::app);
  if (!file)
    throw std::runtime_error("Cannot Open File >> " + cfg_.elementsFile);

  file << "# Element ElasticBeamColumn Definition\n";
  file << "element elasticBeamColumn ";
  file << tag << " " << iNode << " " << jNode << " " << A << " " << E << " "
       << Iz << " " << transfTag;

  if (massDens != 0.0) {
    file << " -mass " << massDens;
  }

  if (cMass) {
    file << " -cMass";
  }

  file << "\n";
  file.close();
}

void ElementWriter::addAdditionalElasticBeamColumnElement(
    const std::size_t& tag, const std::size_t& iNode, const std::size_t& jNode,
    const double& A, const double& E, const double& Iz,
    const std::size_t& transfTag, const double& massDens,
    const std::size_t& cMass) {
  std::ofstream file(cfg_.analysisFile, std::ios::app);
  if (!file)
    throw std::runtime_error("Cannot Open File -> Analysis >> " +
                             cfg_.analysisFile);

  file << "# Element ElasticBeamColumn Definition\n";
  file << "element elasticBeamColumn ";
  file << tag << " " << iNode << " " << jNode << " " << A << " " << E << " "
       << Iz << " " << transfTag;

  if (massDens != 0.0) {
    file << " -mass " << massDens;
  }

  if (cMass) {
    file << " -cMass";
  }

  file << "\n";
  file.close();
}

// ---- 3D definition
void ElementWriter::addElasticBeamColumnElement(
    const std::size_t& tag, const std::size_t& iNode, const std::size_t& jNode,
    const double& A, const double& E, const double& G, const double& J,
    const double& Iy, const double& Iz, const std::size_t& transfTag,
    const double& massDens, const std::size_t& cMass) {
  std::ofstream file(cfg_.elementsFile, std::ios::app);
  if (!file)
    throw std::runtime_error("Cannot Open File >> " + cfg_.elementsFile);

  file << "# Element ElasticBeamColumn Definition\n";
  file << "element elasticBeamColumn ";
  file << tag << " " << iNode << " " << jNode << " " << A << " " << E << " "
       << G << " " << J << " " << Iy << " " << Iz << " " << transfTag;

  if (massDens != 0.0) {
    file << " -mass " << massDens;
  }

  if (cMass) {
    file << " -cMass";
  }

  file << "\n";
  file.close();
}

void ElementWriter::addAdditionalElasticBeamColumnElement(
    const std::size_t& tag, const std::size_t& iNode, const std::size_t& jNode,
    const double& A, const double& E, const double& G, const double& J,
    const double& Iy, const double& Iz, const std::size_t& transfTag,
    const double& massDens, const std::size_t& cMass) {
  std::ofstream file(cfg_.analysisFile, std::ios::app);
  if (!file)
    throw std::runtime_error("Cannot Open File -> Analysis >> " +
                             cfg_.analysisFile);

  file << "# Element ElasticBeamColumn Definition\n";
  file << "element elasticBeamColumn ";
  file << tag << " " << iNode << " " << jNode << " " << A << " " << E << " "
       << G << " " << J << " " << Iy << " " << Iz << " " << transfTag;

  if (massDens != 0.0) {
    file << " -mass " << massDens;
  }

  if (cMass) {
    file << " -cMass";
  }

  file << "\n";
  file.close();
}

// ---- 2D and 3D definition with a section def
void ElementWriter::addElasticBeamColumnElement(
    const std::size_t& tag, const std::size_t& iNode, const std::size_t& jNode,
    const std::size_t& secTag, const std::size_t& transfTag,
    const double& massDens, const std::size_t& cMass) {
  std::ofstream file(cfg_.elementsFile, std::ios::app);
  if (!file)
    throw std::runtime_error("Cannot Open File >> " + cfg_.elementsFile);

  file << "# Element ElasticBeamColumn Definition\n";
  file << "element elasticBeamColumn ";
  file << tag << " " << iNode << " " << jNode << " " << secTag << " "
       << transfTag;

  if (massDens != 0.0) {
    file << " -mass " << massDens;
  }

  if (cMass) {
    file << " -cMass";
  }

  file << "\n";
  file.close();
}

void ElementWriter::addElasticBeamColumnElement(
    const std::vector<std::size_t>& tag,
    const std::vector<std::vector<std::size_t>>& Nodes,
    const std::size_t& secTag, const std::size_t& transfTag,
    const double& massDens, const std::size_t& cMass) {
  std::ofstream file(cfg_.elementsFile, std::ios::app);
  if (!file)
    throw std::runtime_error("Cannot Open File >> " + cfg_.elementsFile);

  file << "# Element ElasticBeamColumn Definition\n";
  for (auto ii = 0; ii < tag.size(); ii++) {
    file << "element elasticBeamColumn " << tag[ii] << " " << Nodes[ii][0]
         << " " << Nodes[ii][1] << " ";
    file << secTag << " " << transfTag << " ";
    if (massDens != 0.0) {
      file << " -mass " << massDens;
    }

    if (cMass) {
      file << " -cMass";
    }

    file << "\n";
  }
  file.close();
}

void ElementWriter::addAdditionalElasticBeamColumnElement(
    const std::size_t& tag, const std::size_t& iNode, const std::size_t& jNode,
    const std::size_t& secTag, const std::size_t& transfTag,
    const double& massDens, const std::size_t& cMass) {
  std::ofstream file(cfg_.analysisFile, std::ios::app);
  if (!file)
    throw std::runtime_error("Cannot Open File -> Analysis >> " +
                             cfg_.analysisFile);

  file << "# Element ElasticBeamColumn Definition\n";
  file << "element elasticBeamColumn ";
  file << tag << " " << iNode << " " << jNode << " " << secTag << " "
       << transfTag;

  if (massDens != 0.0) {
    file << " -mass " << massDens;
  }

  if (cMass) {
    file << " -cMass";
  }

  file << "\n";
  file.close();
}

void ElementWriter::addAdditionalElasticBeamColumnElement(
    const std::vector<std::size_t>& tag,
    const std::vector<std::vector<std::size_t>>& Nodes,
    const std::size_t& secTag, const std::size_t& transfTag,
    const double& massDens, const std::size_t& cMass) {
  std::ofstream file(cfg_.analysisFile, std::ios::app);
  if (!file)
    throw std::runtime_error("Cannot Open File >> " + cfg_.analysisFile);

  file << "# Element ElasticBeamColumn Definition\n";
  for (auto ii = 0; ii < tag.size(); ii++) {
    file << "element elasticBeamColumn " << tag[ii] << " " << Nodes[ii][0]
         << " " << Nodes[ii][1] << " ";
    file << secTag << " " << transfTag << " ";
    if (massDens != 0.0) {
      file << " -mass " << massDens;
    }

    if (cMass) {
      file << " -cMass";
    }

    file << "\n";
  }
  file.close();
}
// ---- ElasticBeamColumnElement ----

void ElementWriter::addforceBeamColumnElement(
    const std::vector<std::size_t>& tag,
    const std::vector<std::vector<std::size_t>>& Nodes,
    const std::size_t numIntgrPts, const std::size_t& secTag,
    const std::size_t& transfTag, const double& massDens) {
  std::ofstream file(cfg_.elementsFile, std::ios::app);
  if (!file)
    throw std::runtime_error("Cannot Open File >> " + cfg_.elementsFile);

  file << "# Element forceBeamColumnn Element Definition\n";

  for (auto ii = 0; ii < tag.size(); ii++) {
    file << "element forceBeamColumn " << tag[ii] << " " << Nodes[ii][0] << " "
         << Nodes[ii][1] << " " << numIntgrPts << " ";
    file << secTag << " " << transfTag << " ";
    if (massDens != 0.0) {
      file << " -mass " << massDens;
    }
    file << "\n";
  }

  file.close();
}

void ElementWriter::addAdditionalforceBeamColumnElement(
    const std::vector<std::size_t>& tag,
    const std::vector<std::vector<std::size_t>>& Nodes,
    const std::size_t numIntgrPts, const std::size_t& secTag,
    const std::size_t& transfTag, const double& massDens) {
  std::ofstream file(cfg_.elementsFile, std::ios::app);
  if (!file)
    throw std::runtime_error("Cannot Open File >> " + cfg_.elementsFile);

  file << "# Element forceBeamColumnn Element Definition\n";
  for (auto ii = 0; ii < tag.size(); ii++) {
    file << "element forceBeamColumn " << tag[ii] << " " << Nodes[ii][0] << " "
         << Nodes[ii][1] << " " << numIntgrPts << " ";
    file << secTag << " " << transfTag << " ";
    if (massDens != 0.0) {
      file << " -mass " << massDens;
    }
    file << "\n";
  }

  file.close();
}

// ---- DispBeamColumnElement ----
void ElementWriter::adddispBeamColumnElement(
    const std::vector<std::size_t>& tag,
    const std::vector<std::vector<std::size_t>>& Nodes,
    const std::size_t numIntgrPts, const std::size_t& secTag,
    const std::size_t& transfTag, const double& massDens) {
  std::ofstream file(cfg_.elementsFile, std::ios::app);
  if (!file)
    throw std::runtime_error("Cannot Open File >> " + cfg_.elementsFile);

  file << "# Element dispBeamColumnn Element Definition\n";

  for (auto ii = 0; ii < tag.size(); ii++) {
    file << "element dispBeamColumn " << tag[ii] << " " << Nodes[ii][0] << " "
         << Nodes[ii][1] << " " << numIntgrPts << " ";
    file << secTag << " " << transfTag << " ";
    if (massDens != 0.0) {
      file << " -mass " << massDens;
    }
    file << "\n";
  }

  file.close();
}

void ElementWriter::addAdditionaldispBeamColumnElement(
    const std::vector<std::size_t>& tag,
    const std::vector<std::vector<std::size_t>>& Nodes,
    const std::size_t numIntgrPts, const std::size_t& secTag,
    const std::size_t& transfTag, const double& massDens) {
  std::ofstream file(cfg_.analysisFile, std::ios::app);
  if (!file)
    throw std::runtime_error("Cannot Open File >> " + cfg_.analysisFile);

  file << "# Element dispBeamColumnn Element Definition\n";

  for (auto ii = 0; ii < tag.size(); ii++) {
    file << "element dispBeamColumn " << tag[ii] << " " << Nodes[ii][0] << " "
         << Nodes[ii][1] << " " << numIntgrPts << " ";
    file << secTag << " " << transfTag << " ";
    if (massDens != 0.0) {
      file << " -mass " << massDens;
    }
    file << "\n";
  }

  file.close();
}

// ---- 2D Elements ----
// ---- Quad ----
void ElementWriter::addQuadElement(
    const std::size_t& tag, const std::size_t& iNode, const std::size_t& jNode,
    const std::size_t& kNode, const std::size_t& lNode, const double& thick,
    const std::string& type, const std::size_t& matTag, const double& pressure,
    const double& rho, const double& b1, const double& b2) {
  std::ofstream file(cfg_.elementsFile, std::ios::app);
  if (!file)
    throw std::runtime_error("Cannot Open File >> " + cfg_.elementsFile);

  file << "# Element Quad Definition\n";
  file << "element quad " << tag << " " << iNode << " " << jNode << " " << kNode
       << " " << lNode << " " << thick << " \"" << type << "\" " << matTag;

  if (pressure != 0.0 || rho != 0.0 || b1 != 0.0 || b2 != 0.0) {
    file << " " << pressure << " " << rho << " " << b1 << " " << b2;
  }

  file << "\n";
  file.close();
}

void ElementWriter::addAdditionalQuadElement(
    const std::size_t& tag, const std::size_t& iNode, const std::size_t& jNode,
    const std::size_t& kNode, const std::size_t& lNode, const double& thick,
    const std::string& type, const std::size_t& matTag, const double& pressure,
    const double& rho, const double& b1, const double& b2) {
  std::ofstream file(cfg_.analysisFile, std::ios::app);
  if (!file)
    throw std::runtime_error("Cannot Open File -> Analysis >> " +
                             cfg_.analysisFile);

  file << "# Element Quad Definition\n";
  file << "element quad " << tag << " " << iNode << " " << jNode << " " << kNode
       << " " << lNode << " " << thick << " \"" << type << "\" " << matTag;

  if (pressure != 0.0 || rho != 0.0 || b1 != 0.0 || b2 != 0.0) {
    file << " " << pressure << " " << rho << " " << b1 << " " << b2;
  }

  file << "\n";
  file.close();
}

// ---- QuadSSP ----
void ElementWriter::addSSPQuadElement(
    const std::size_t& tag, const std::size_t& iNode, const std::size_t& jNode,
    const std::size_t& kNode, const std::size_t& lNode, const double& thick,
    const std::string& type, const std::size_t& matTag, const double& rho,
    const double& b1, const double& b2) {
  std::ofstream file(cfg_.elementsFile, std::ios::app);
  if (!file)
    throw std::runtime_error("Cannot Open File -> Analysis >> " +
                             cfg_.elementsFile);

  file << "# Element SSPQuad Definition\n";
  file << "element SSPquad " << tag << " " << iNode << " " << jNode << " "
       << kNode << " " << lNode << " " << thick << " \"" << type << "\" "
       << matTag;

  if (rho != 0.0 || b1 != 0.0 || b2 != 0.0) {
    file << " " << rho << " " << b1 << " " << b2;
  }

  file << "\n";
  file.close();
}

void ElementWriter::addAdditionalSSPQuadElement(
    const std::size_t& tag, const std::size_t& iNode, const std::size_t& jNode,
    const std::size_t& kNode, const std::size_t& lNode, const double& thick,
    const std::string& type, const std::size_t& matTag, const double& rho,
    const double& b1, const double& b2) {
  std::ofstream file(cfg_.analysisFile, std::ios::app);
  if (!file)
    throw std::runtime_error("Cannot Open File -> Analysis >> " +
                             cfg_.analysisFile);

  file << "# Element SSPQuad Definition\n";
  file << "element SSPquad " << tag << " " << iNode << " " << jNode << " "
       << kNode << " " << lNode << " " << thick << " \"" << type << "\" "
       << matTag;

  if (rho != 0.0 || b1 != 0.0 || b2 != 0.0) {
    file << " " << rho << " " << b1 << " " << b2;
  }

  file << "\n";
  file.close();
}

// ---- set Transofrmations for Elements
// ---- 2D Linear Transformation
void ElementWriter::addLinearTransformation2D(const std::size_t& transfTag,
                                              const double& dXi,
                                              const double& dYi,
                                              const double& dXj,
                                              const double& dYj) {
  std::ofstream file(cfg_.elementsFile, std::ios::app);
  if (!file)
    throw std::runtime_error("Cannot Open File >> " + cfg_.elementsFile);

  file << "# add Linear Transformation 2D\n";
  file << "geomTransf Linear " << transfTag << " ";
  if (dXi != 0. && dYi != 0. && dXj != 0. && dYj != 0.) {
    file << "-jntOffset " << dXi << " " << dYi << " " << dXj << " " << dYj;
  }

  file << "\n";
  file.close();
}

// ---- 3D Linear Transformation
void ElementWriter::addLinearTransformation3D(
    const std::size_t& transfTag, const double& vecxzX, const double& vecxzY,
    const double& vecxzZ, const double& dXi, const double& dYi,
    const double& dZi, const double& dXj, const double& dYj,
    const double& dZj) {
  std::ofstream file(cfg_.elementsFile, std::ios::app);
  if (!file)
    throw std::runtime_error("Cannot Open File >> " + cfg_.elementsFile);

  file << "# add Linear Transformation 3D\n";
  file << "geomTransf Linear " << transfTag << " " << vecxzX << " " << vecxzY
       << " " << vecxzZ;
  if (dXi != 0. && dYi != 0. && dZi != 0. && dXj != 0. && dYj != 0. &&
      dZj != 0.) {
    file << "-jntOffset " << dXi << " " << dYi << " " << dZi << " " << dXj
         << " " << dYj << " " << dZj;
  }

  file << "\n";
  file.close();
}

// ---- 2D PDelta Transformation
void ElementWriter::addPDeltaTransformation2D(const std::size_t& transfTag,
                                              const double& dXi,
                                              const double& dYi,
                                              const double& dXj,
                                              const double& dYj) {
  std::ofstream file(cfg_.elementsFile, std::ios::app);
  if (!file)
    throw std::runtime_error("Cannot Open File >> " + cfg_.elementsFile);

  file << "# add PDelta Transformation 2D\n";
  file << "geomTransf PDelta " << transfTag << " ";
  if (dXi != 0. && dYi != 0. && dXj != 0. && dYj != 0.) {
    file << "-jntOffset " << dXi << " " << dYi << " " << dXj << " " << dYj;
  }

  file << "\n";
  file.close();
}
// ---- 3D PDelta Transformation
void ElementWriter::addPDeltaTransformation3D(
    const std::size_t& transfTag, const double& vecxzX, const double& vecxzY,
    const double& vecxzZ, const double& dXi, const double& dYi,
    const double& dZi, const double& dXj, const double& dYj,
    const double& dZj) {
  std::ofstream file(cfg_.elementsFile, std::ios::app);
  if (!file)
    throw std::runtime_error("Cannot Open File >> " + cfg_.elementsFile);

  file << "# add PDelta Transformation 3D\n";
  file << "geomTransf PDelta " << transfTag << " " << vecxzX << " " << vecxzY
       << " " << vecxzZ;
  if (dXi != 0. && dYi != 0. && dZi != 0. && dXj != 0. && dYj != 0. &&
      dZj != 0.) {
    file << "-jntOffset " << dXi << " " << dYi << " " << dZi << " " << dXj
         << " " << dYj << " " << dZj;
  }

  file << "\n";
  file.close();
}

// ---- 2D Corotational Transformation
void ElementWriter::addCorotationalTransformation2D(
    const std::size_t& transfTag, const double& dXi, const double& dYi,
    const double& dXj, const double& dYj) {
  std::ofstream file(cfg_.elementsFile, std::ios::app);
  if (!file)
    throw std::runtime_error("Cannot Open File >> " + cfg_.elementsFile);

  file << "# add Corotational  Transformation 2D\n";
  file << "geomTransf Corotational " << transfTag << " ";
  if (dXi != 0. && dYi != 0. && dXj != 0. && dYj != 0.) {
    file << "-jntOffset " << dXi << " " << dYi << " " << dXj << " " << dYj;
  }

  file << "\n";
  file.close();
}

// ---- 3D PDelta Transformation
void ElementWriter::addCorotationalTransformation3D(
    const std::size_t& transfTag, const double& vecxzX, const double& vecxzY,
    const double& vecxzZ) {
  std::ofstream file(cfg_.elementsFile, std::ios::app);
  if (!file)
    throw std::runtime_error("Cannot Open File >> " + cfg_.elementsFile);

  file << "# add Corotational Transformation 3D\n";
  file << "geomTransf Corotational " << transfTag << " " << vecxzX << " "
       << vecxzY << " " << vecxzZ << "\n";

  file.close();
}