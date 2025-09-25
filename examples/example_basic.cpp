#include <gmsh.h>

#include <iostream>

#include "AnalysisWriter.h"
#include "BCWriter.h"
#include "Config.h"
#include "ElementWriter.h"
#include "LoadPatternWriter.h"
#include "MaterialWriter.h"
#include "NodeWriter.h"
#include "RecorderWriter.h"
#include "SectionWriter.h"
#include "TimeSeriesWriter.h"
#include "utils.h"

int main() {
  // Define Units
  double in = 1.;                 // define basic units -- output units
  double kip = 1.;                // define basic units -- output units
  double sec = 1.;                // define basic units -- output units
  std::string LunitTXT = "inch";  // define basic-unit text for output
  std::string FunitTXT = "kip";   // define basic-unit text for output
  std::string TunitTXT = "sec";   // define basic-unit text for output
  double ft = 12. * in;           // define engineering units
  double ksi = kip / pow(in, 2);
  double psi = ksi / 1000.;
  double lbf = psi * in * in;      // pounds force
  double pcf = lbf / pow(ft, 3);   // pounds per cubic foot
  double psf = lbf / pow(ft, 3);   // pounds per square foot
  double in2 = in * in;            // inch^2
  double in4 = in * in * in * in;  // inch^4
  double cm = in / 2.54;      // centimeter, needed for displacement input in
                              // MultipleSupport excitation
  double PI = 2 * asin(1.0);  // define constants
  double g = 32.2 * ft / pow(sec, 2);  // gravitational acceleration
  double Ubig = 1.e10;                 // a really large number
  double Usmall = 1 / Ubig;            // a really small number

  // initializa the gmsh APIs
  gmsh::initialize();
  // ---- define units
  // ---- define geometry
  double LCol = 12. * ft;   // column height (parallel to Y axis)
  double LBeam = 20. * ft;  // beam length (parallel to X axis)
  double LGird = 20. * ft;  // girder length (parallel to Z axis)

  // ---- define nodes -> explicit tags
  double _ = 0.;
  int p1 = gmsh::model::geo::addPoint(0., 0., 0.);
  int p2 = gmsh::model::geo::addPoint(0., LCol, 0.);
  int p3 = gmsh::model::geo::addPoint(0., 2.0 * LCol, 0.);
  int p4 = gmsh::model::geo::addPoint(0., 3.0 * LCol, 0.);

  int p5 = gmsh::model::geo::addPoint(LBeam, 0., 0.);
  int p6 = gmsh::model::geo::addPoint(LBeam, LCol, 0.);
  int p7 = gmsh::model::geo::addPoint(LBeam, 2.0 * LCol, 0.);
  int p8 = gmsh::model::geo::addPoint(LBeam, 3.0 * LCol, 0.);

  int p9 = gmsh::model::geo::addPoint(0., 0., LGird);
  int p10 = gmsh::model::geo::addPoint(0., LCol, LGird);
  int p11 = gmsh::model::geo::addPoint(0., 2.0 * LCol, LGird);
  int p12 = gmsh::model::geo::addPoint(0., 3.0 * LCol, LGird);

  int p13 = gmsh::model::geo::addPoint(LBeam, 0., LGird);
  int p14 = gmsh::model::geo::addPoint(LBeam, LCol, LGird);
  int p15 = gmsh::model::geo::addPoint(LBeam, 2.0 * LCol, LGird);
  int p16 = gmsh::model::geo::addPoint(LBeam, 3.0 * LCol, LGird);

  // ---- define beams
  int l1 = gmsh::model::geo::addLine(p1, p2);
  int l2 = gmsh::model::geo::addLine(p2, p3);
  int l3 = gmsh::model::geo::addLine(p3, p4);

  int l4 = gmsh::model::geo::addLine(p5, p6);
  int l5 = gmsh::model::geo::addLine(p6, p7);
  int l6 = gmsh::model::geo::addLine(p7, p8);

  int l7 = gmsh::model::geo::addLine(p2, p6);
  int l8 = gmsh::model::geo::addLine(p3, p7);
  int l9 = gmsh::model::geo::addLine(p4, p8);

  int l10 = gmsh::model::geo::addLine(p9, p10);
  int l11 = gmsh::model::geo::addLine(p10, p11);
  int l12 = gmsh::model::geo::addLine(p11, p12);

  int l13 = gmsh::model::geo::addLine(p13, p14);
  int l14 = gmsh::model::geo::addLine(p14, p15);
  int l15 = gmsh::model::geo::addLine(p15, p16);

  int l16 = gmsh::model::geo::addLine(p10, p14);
  int l17 = gmsh::model::geo::addLine(p11, p15);
  int l18 = gmsh::model::geo::addLine(p12, p16);
  // ---- girder
  int l19 = gmsh::model::geo::addLine(p2, p10);
  int l20 = gmsh::model::geo::addLine(p3, p11);
  int l21 = gmsh::model::geo::addLine(p4, p12);

  int l22 = gmsh::model::geo::addLine(p6, p14);
  int l23 = gmsh::model::geo::addLine(p7, p15);
  int l24 = gmsh::model::geo::addLine(p8, p16);

  // syn the goemetry
  gmsh::model::geo::synchronize();

  int pg1 = gmsh::model::addPhysicalGroup(0, {p2, p6, p10, p14});
  int pg2 = gmsh::model::addPhysicalGroup(0, {p3, p7, p11, p15});
  int pg3 = gmsh::model::addPhysicalGroup(0, {p4, p8, p12, p16});

  int pg11 = gmsh::model::addPhysicalGroup(0, {p1, p5, p9, p13});

  // ---- Set transfinite for Mesh
  int segBeam = 1;
  int segCol = 1;
  int segGir = 1;
  // --- Columns
  gmsh::model::mesh::setTransfiniteCurve(l1, segCol);
  gmsh::model::mesh::setTransfiniteCurve(l2, segCol);
  gmsh::model::mesh::setTransfiniteCurve(l3, segCol);
  gmsh::model::mesh::setTransfiniteCurve(l4, segCol);
  gmsh::model::mesh::setTransfiniteCurve(l5, segCol);
  gmsh::model::mesh::setTransfiniteCurve(l6, segCol);
  gmsh::model::mesh::setTransfiniteCurve(l10, segCol);
  gmsh::model::mesh::setTransfiniteCurve(l11, segCol);
  gmsh::model::mesh::setTransfiniteCurve(l12, segCol);
  gmsh::model::mesh::setTransfiniteCurve(l13, segCol);
  gmsh::model::mesh::setTransfiniteCurve(l14, segCol);
  gmsh::model::mesh::setTransfiniteCurve(l15, segCol);
  // ---- Beams
  gmsh::model::mesh::setTransfiniteCurve(l7, segBeam);
  gmsh::model::mesh::setTransfiniteCurve(l8, segBeam);
  gmsh::model::mesh::setTransfiniteCurve(l9, segBeam);
  gmsh::model::mesh::setTransfiniteCurve(l16, segBeam);
  gmsh::model::mesh::setTransfiniteCurve(l17, segBeam);
  gmsh::model::mesh::setTransfiniteCurve(l18, segBeam);
  // ---- Girders
  gmsh::model::mesh::setTransfiniteCurve(l19, segGir);
  gmsh::model::mesh::setTransfiniteCurve(l20, segGir);
  gmsh::model::mesh::setTransfiniteCurve(l21, segGir);
  gmsh::model::mesh::setTransfiniteCurve(l22, segGir);
  gmsh::model::mesh::setTransfiniteCurve(l23, segGir);
  gmsh::model::mesh::setTransfiniteCurve(l24, segGir);

  // genrate 1D mesh
  gmsh::model::mesh::generate(1);
  // ---- query the nodes
  std::vector<size_t> nodeTags;
  std::vector<double> unshapedNodeCoords, __;
  std::vector<std::vector<double>> nodeCoords;
  gmsh::model::mesh::getNodes(nodeTags, unshapedNodeCoords, __);
  reshapeNodeCoords(unshapedNodeCoords, nodeCoords);
  // ---- query elements ----
  // ---- columns
  std::vector<int> listCol = {l1,  l2,  l3,  l4,  l5,  l6,
                              l10, l11, l12, l13, l14, l15};
  std::vector<size_t> elemTagsCol;
  std::vector<std::vector<size_t>> elemNodeTagsCol;

  getLineElementInfo(listCol, elemTagsCol, elemNodeTagsCol);
  // ---- beams
  std::vector<int> listBeam = {l7, l8, l9, l16, l17, l18};
  std::vector<size_t> elemTagsBeam;
  std::vector<std::vector<size_t>> elemNodeTagsBeam;

  getLineElementInfo(listBeam, elemTagsBeam, elemNodeTagsBeam);

  // ---- girders
  std::vector<int> listGir = {l19, l20, l21, l22, l23, l24};
  std::vector<size_t> elemTagsGir;
  std::vector<std::vector<size_t>> elemNodeTagsGir;

  getLineElementInfo(listGir, elemTagsGir, elemNodeTagsGir);

  // ---- get the floor nodes
  std::vector<size_t> firstFloorNodes, secondFloorNodes, thirdFloorNodes,
      baseFloorNodes;
  std::vector<double> _dummy;

  gmsh::model::mesh::getNodesForPhysicalGroup(0, pg1, firstFloorNodes, _dummy);
  gmsh::model::mesh::getNodesForPhysicalGroup(0, pg2, secondFloorNodes, _dummy);
  gmsh::model::mesh::getNodesForPhysicalGroup(0, pg3, thirdFloorNodes, _dummy);
  gmsh::model::mesh::getNodesForPhysicalGroup(0, pg11, baseFloorNodes, _dummy);

  // Display the mesh
  gmsh::fltk::run();

  // finalize command
  gmsh::finalize();

  // Call the TCL generator and write files
  // ---- Initialize
  Config cfg;
  NodeWriter nodeWriter(cfg);
  MaterialWriter materialWriter(cfg);
  ElementWriter elementWriter(cfg);
  BCWriter bcWriter(cfg);
  RecorderWriter recWriter(cfg);
  SectionWriter sectionWriter(cfg);
  TimeSeriesWriter timeSeriesWriter(cfg);
  LoadPatternwriter loadPatternWriter(cfg);
  AnalysisWriter analysisWriter(cfg);

  // ---- Write Nodes
  size_t ndm = 3;
  size_t ndf = 6;

  nodeWriter.addNodes(nodeTags, nodeCoords, ndm, ndf);

  // ---- Write The master nodes for rigidDiaprham
  size_t masterTag1 = 1001;
  size_t masterTag2 = 1002;
  size_t masterTag3 = 1003;

  std::vector<double> masterCoords1 = {0.5 * LBeam, LCol, 0.5 * LGird};
  std::vector<double> masterCoords2 = {0.5 * LBeam, 2.0 * LCol, 0.5 * LGird};
  std::vector<double> masterCoords3 = {0.5 * LBeam, 3.0 * LCol, 0.5 * LGird};

  nodeWriter.addNode(masterTag1, masterCoords1);
  nodeWriter.addNode(masterTag2, masterCoords2);
  nodeWriter.addNode(masterTag3, masterCoords3);

  // ---- Fix master node
  bcWriter.addFix(masterTag1, {0, 1, 0, 1, 0, 1});
  bcWriter.addFix(masterTag2, {0, 1, 0, 1, 0, 1});
  bcWriter.addFix(masterTag3, {0, 1, 0, 1, 0, 1});

  // ---- Set RigidDiaphram
  size_t dir = 2;

  bcWriter.addRigidDiaphram(dir, masterTag1, firstFloorNodes);
  bcWriter.addRigidDiaphram(dir, masterTag2, secondFloorNodes);
  bcWriter.addRigidDiaphram(dir, masterTag3, thirdFloorNodes);

  // ---- Pin Base Nodes
  bcWriter.addFix(baseFloorNodes, {
                                      1,
                                      1,
                                      1,
                                      1,
                                      1,
                                      1,
                                  });

#if 0
  // ---- Define Fiber Sections
  // define MATERIAL properties
  double Fy = 60.0 * ksi;
  double Es = 29000. * ksi;  // Steel Young's Modulus
  double nu = 0.3;
  double Gs = Es / (2. * (1 + nu));  // Torsional stiffness Modulus
  double Hiso = 0.;
  double Hkin = 1000.;
  size_t matIDhard = 1;

  materialWriter.addUniaxialMaterialHardening(matIDhard, Es, Fy, Hiso, Hkin);

  // column sections: W27x114
  double d = 27.29 * in;   // depth
  double bf = 10.07 * in;  // flange width
  double tf = 0.93 * in;   // flange thickness
  double tw = 0.57 * in;   // web thickness
  size_t nfdw = 16.;       // number of fibers along dw
  size_t nftw = 2;         // number of fibers along tw
  size_t nfbf = 16;        // number of fibers along bf
  size_t nftf = 4;         // number of fibers along tf
  size_t ColSecTag = 1;
  size_t ColSecTagFiber = 4;
  sectionWriter.addWFSection3d(ColSecTagFiber, matIDhard, Ubig, d, bf, tf, tw,
                               nfdw, nftw, nfbf, nftf);

  // beam sections: W24x94
  d = 24.31 * in;   // depth
  bf = 9.065 * in;  // flange width
  tf = 0.875 * in;  // flange thickness
  tw = 0.515 * in;  // web thickness
  nfdw = 16;        // number of fibers along dw
  nftw = 2;         // number of fibers along tw
  nfbf = 16;        // number of fibers along bf
  nftf = 4;         // number of fibers along tf
  size_t BeamSecTag = 2;
  size_t BeamSecTagFiber = 5;
  sectionWriter.addWFSection3d(BeamSecTagFiber, matIDhard, Ubig, d, bf, tf, tw,
                               nfdw, nftw, nfbf, nftf);

  // girder sections: W24x94
  d = 24.31 * in;   // depth
  bf = 9.065 * in;  // flange width
  tf = 0.875 * in;  // flange thickness
  tw = 0.515 * in;  // web thickness
  nfdw = 16;        // number of fibers along dw
  nftw = 2;         // number of fibers along tw
  nfbf = 16;        // number of fibers along bf
  nftf = 4;         // number of fibers along tf
  size_t GirdSecTag = 3;
  size_t GirdSecTagFiber = 6;
  sectionWriter.addWFSection3d(GirdSecTagFiber, matIDhard, Ubig, d, bf, tf, tw,
                               nfdw, nftw, nfbf, nftf);

  // assign torsional Stiffness for 3D module
  // size_t secTagTorsion = 70;
  // std::string aggDof = "T";
  // materialWriter.addUniaxialElasticMaterial(secTagTorsion, Ubig);
  // sectionWriter.addSectionAggregator(ColSecTag, secTagTorsion, aggDof,
  //                                    ColSecTagFiber);
  //
  // sectionWriter.addSectionAggregator(BeamSecTag, secTagTorsion, aggDof,
  //                                   BeamSecTagFiber);
  //
  // sectionWriter.addSectionAggregator(GirdSecTag, secTagTorsion, aggDof,
  //                                   GirdSecTagFiber);

  elementWriter.addLinearTransformation3D(ColSecTag, 0., 0., 1.);
  elementWriter.addLinearTransformation3D(BeamSecTag, 0., 0., 1.);
  elementWriter.addLinearTransformation3D(GirdSecTag, 1, 0., 0);

  size_t intPoints = 4;
  elementWriter.adddispBeamColumnElement(elemTagsCol, elemNodeTagsCol,
                                         intPoints, ColSecTagFiber, ColSecTag);
  elementWriter.adddispBeamColumnElement(
      elemTagsBeam, elemNodeTagsBeam, intPoints, BeamSecTagFiber, BeamSecTag);
  elementWriter.adddispBeamColumnElement(
      elemTagsGir, elemNodeTagsGir, intPoints, GirdSecTagFiber, GirdSecTag);
#endif

#if 1
  // ---- Define Elastic Section
  // material properties
  double Es, nu, Gs, J;
  Es = 29000.;
  nu = 0.3;
  Gs = Es / (2. * (1 + nu));
  J = 1e10;
  // column section: W27x114
  double AgCol, IzCol, IyCol;
  AgCol = 33.5;
  IzCol = 4090.;
  IyCol = 159.;
  // beam section: W24x94
  double AgBeam, IzBeam, IyBeam;
  AgBeam = 27.7;
  IzBeam = 2700.;
  IyBeam = 109.;
  // girder section: W24x94
  double AgGirder, IzGirder, IyGirder;
  AgGirder = 27.7;
  IzGirder = 2700.;
  IyGirder = 109.;

  // tags
  size_t colSecTag = 1;
  size_t beamSecTag = 2;
  size_t girderSecTag = 3;

  sectionWriter.addElasticSection(colSecTag, Es, AgCol, IzCol, IyCol, Gs, J);
  sectionWriter.addElasticSection(beamSecTag, Es, AgBeam, IzBeam, IyBeam, Gs,
                                  J);
  sectionWriter.addElasticSection(girderSecTag, Es, AgGirder, IzGirder,
                                  IyGirder, Gs, J);

  // ---- Define beam column finite elements
  size_t colTransfTag = 11;
  size_t beamTransfTag = 12;
  size_t girTransfTag = 13;

  elementWriter.addLinearTransformation3D(colTransfTag, 0., 0., 1.);
  elementWriter.addLinearTransformation3D(beamTransfTag, 0., 0., 1.);
  elementWriter.addLinearTransformation3D(girTransfTag, 1, 0., 0);

  elementWriter.addElasticBeamColumnElement(elemTagsGir, elemNodeTagsGir,
                                            girderSecTag, girTransfTag);

  elementWriter.addElasticBeamColumnElement(elemTagsBeam, elemNodeTagsBeam,
                                            beamSecTag, beamTransfTag);

  elementWriter.addElasticBeamColumnElement(elemTagsCol, elemNodeTagsCol,
                                            colSecTag, colTransfTag);

#endif

  // Compute gravity loads

  double QdlCol = 114. * lbf / ft;  // W-section weight per length
  double QBeam = 94. * lbf / ft;    // W-section weight per length
  double QGird = 94. * lbf / ft;    // W-section weight per length

  double GammaConcrete =
      150. * pcf;  // Reinforced-Concrete weight density (weight per volume)
  double Tslab = 6. * in;  // 6-inch slab
  double Lslab =
      LGird / 2.;         // slab extends a distance of LGird/2 in/out of plane
  double DLfactor = 1.0;  // scale dead load up a little
  double Qslab = GammaConcrete * Tslab * Lslab * DLfactor;
  double QdlBeam =
      Qslab + QBeam;       // dead load distributed along beam (one-way slab)
  double QdlGird = QGird;  // dead load distributed along girder
  double WeightCol = QdlCol * LCol;     // total Column weight
  double WeightBeam = QdlBeam * LBeam;  // total Beam weight
  double WeightGird = QdlGird * LGird;  // total Beam weight

  double Mmid =
      (WeightCol / 2. + WeightCol / 2. + WeightBeam / 2. + WeightGird / 2.) / g;
  double Mtop = (WeightCol / 2. + WeightBeam / 2. + WeightGird / 2.) / g;

  // Assign Masses
  // Frame 1
  nodeWriter.addMass(firstFloorNodes, {Mmid, 0., Mmid, 0., 0., 0.});
  nodeWriter.addMass(secondFloorNodes, {Mmid, 0., Mmid, 0., 0., 0.});
  nodeWriter.addMass(thirdFloorNodes, {Mtop, 0., Mtop, 0., 0., 0.});

  double FloorWeight2 = 4 * WeightCol + 2 * WeightGird + 2 * WeightBeam;
  double FloorWeight3 = 4 * WeightCol + 2 * WeightGird + 2 * WeightBeam;
  double FloorWeight4 = 2 * WeightCol + 2 * WeightGird + 2 * WeightBeam;
  double WeightTotal =
      FloorWeight2 + FloorWeight3 + FloorWeight4;  // total building weight
  double MassTotal = WeightTotal / g;              // total building mass

  // --------------------------------------------------------------------------------------------------------------------------------
  // LATERAL-LOAD distribution for static pushover analysis
  // calculate distribution of lateral load based on mass/weight distributions
  // along building height Fj = WjHj/sum(WiHi)  * Weight   at each floor j
  double Y1, Y2, Y3, Y4;
  Y1 = 0.;
  Y2 = Y1 + LCol;
  Y3 = Y2 + LCol;
  Y4 = Y3 + LCol;
  double sumWiHi = FloorWeight2 * Y2 + FloorWeight3 * Y3 +
                   FloorWeight4 * Y4;  // sum of storey weight times height, for
                                       // lateral-load distribution
  double WiHi2 =
      FloorWeight2 *
      Y2;  // storey weight times height, for lateral-load distribution
  double WiHi3 =
      FloorWeight3 *
      Y3;  // storey weight times height, for lateral-load distribution
  double WiHi4 =
      FloorWeight4 *
      Y4;  // storey weight times height, for lateral-load distribution
  double F2 = WiHi2 / sumWiHi * WeightTotal;  // lateral load at level
  double F3 = WiHi3 / sumWiHi * WeightTotal;  // lateral load at level
  double F4 = WiHi4 / sumWiHi * WeightTotal;  // lateral load at level

  // Define a Linear TimeSeries
  size_t timeSeriesTag = 101;
  timeSeriesWriter.addLinearTimeSeries(timeSeriesTag);

  // Define Element Load Patterns
  size_t colLoadPat = 201;
  size_t beamLoadPat = 202;
  size_t girdLoadPat = 203;

  std::vector<double> colLoad = {0., 0., -QdlCol};
  std::vector<double> beamLoad = {-QdlBeam, 0., 0.};
  std::vector<double> girdLoad = {-QdlGird, 0., 0.};

  loadPatternWriter.addPlainPatternElementLoad(colLoadPat, timeSeriesTag,
                                               elemTagsCol, colLoad);

  loadPatternWriter.addPlainPatternElementLoad(beamLoadPat, timeSeriesTag,
                                               elemTagsBeam, beamLoad);

  loadPatternWriter.addPlainPatternElementLoad(girdLoadPat, timeSeriesTag,
                                               elemTagsGir, girdLoad);

  // Define the recorders
  std::string fileNamePVD = "/home/master/TCLgenerator/out/recorder.pvd";
  std::vector<std::string> recorder = {"disp", "accel"};

  RecorderWriter recordWriter(cfg);
  recordWriter.addPVDRecorder(fileNamePVD, recorder);

  // Define the Analysis
  // Gravity
  analysisWriter.addConstraints("Penalty", 1.00e18, 1.00e18);
  analysisWriter.addNumberer("RCM");
  analysisWriter.addSystem("UmfPack");
  analysisWriter.addTest("NormDispIncr", 1.00e-3, 100);
  analysisWriter.addAlgorithm("Newton");

  size_t NstepGravity = 10;
  double DGravity = 1. / NstepGravity;

  analysisWriter.addLoadControl(DGravity);
  analysisWriter.addAnalysis("Static");
  analysisWriter.addStaticAnalysis(10);

  analysisWriter.loadConst();
  // Define Push Over Analysis
  double LBuilding = 3.0 * LCol;
  double Dmax = 0.1 * LBuilding;
  double Dincr = 0.001 * LBuilding;

  // Define Load Pattern nodal
  size_t POpatternTAG = 301;
  std::vector<size_t> IDContNode = {1001, 1002, 1003};
  std::vector<std::vector<double>> Forces = {
      {F2, 0., 0., 0., 0., 0.},
      {F3, 0., 0., 0., 0., 0.},
      {F4, 0., 0., 0., 0., 0.},
  };

  loadPatternWriter.addAdditionalPlainPatternNodalLoad(
      POpatternTAG, timeSeriesTag, IDContNode, Forces);

  size_t controlNodeID = 1003;
  size_t dofPO = 1;

  analysisWriter.addDisplacementsControl(controlNodeID, dofPO, Dmax);
  analysisWriter.addStaticAnalysis(Dmax / Dincr);

  return 0;
}