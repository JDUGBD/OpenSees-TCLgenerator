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
  // Define Units N, mm, ton , s
  // DEfine geometric properties of the frame
  double hcol = 3500.;
  double lbeam = 5000.;
  double lgird = lbeam;

  // intialize gmsh APIs
  gmsh::initialize();
  // Define points

  // Base
  double b2 = 0.5 * lbeam;
  double b1 = lbeam + b2;

  double g2 = 0.5 * lgird;
  double g1 = lgird + g2;

  double h1 = hcol * 1.;
  double h2 = hcol * 2.;
  double h3 = hcol * 3.;
  double h4 = hcol * 4.;
  double h5 = hcol * 5.;
  double h6 = hcol * 6.;
  double h7 = hcol * 7.;

  // Base Floor
  int pt01 = gmsh::model::geo::addPoint(-b1, 0.0, -g1);
  int pt02 = gmsh::model::geo::addPoint(-b2, 0.0, -g1);
  int pt03 = gmsh::model::geo::addPoint(b2, 0.0, -g1);
  int pt04 = gmsh::model::geo::addPoint(b1, 0.0, -g1);
  int pt05 = gmsh::model::geo::addPoint(-b1, 0.0, -g2);
  int pt06 = gmsh::model::geo::addPoint(-b2, 0.0, -g2);
  int pt07 = gmsh::model::geo::addPoint(b2, 0.0, -g2);
  int pt08 = gmsh::model::geo::addPoint(b1, 0.0, -g2);
  int pt09 = gmsh::model::geo::addPoint(-b1, 0.0, g2);
  int pt010 = gmsh::model::geo::addPoint(-b2, 0.0, g2);
  int pt011 = gmsh::model::geo::addPoint(b2, 0.0, g2);
  int pt012 = gmsh::model::geo::addPoint(b1, 0.0, g2);
  int pt013 = gmsh::model::geo::addPoint(-b1, 0.0, g1);
  int pt014 = gmsh::model::geo::addPoint(-b2, 0.0, g1);
  int pt015 = gmsh::model::geo::addPoint(b2, 0.0, g1);
  int pt016 = gmsh::model::geo::addPoint(b1, 0.0, g1);

  // I Floor
  int pt11 = gmsh::model::geo::addPoint(-b1, h1, -g1);
  int pt12 = gmsh::model::geo::addPoint(-b2, h1, -g1);
  int pt13 = gmsh::model::geo::addPoint(b2, h1, -g1);
  int pt14 = gmsh::model::geo::addPoint(b1, h1, -g1);
  int pt15 = gmsh::model::geo::addPoint(-b1, h1, -g2);
  int pt16 = gmsh::model::geo::addPoint(-b2, h1, -g2);
  int pt17 = gmsh::model::geo::addPoint(b2, h1, -g2);
  int pt18 = gmsh::model::geo::addPoint(b1, h1, -g2);
  int pt19 = gmsh::model::geo::addPoint(-b1, h1, g2);
  int pt110 = gmsh::model::geo::addPoint(-b2, h1, g2);
  int pt111 = gmsh::model::geo::addPoint(b2, h1, g2);
  int pt112 = gmsh::model::geo::addPoint(b1, h1, g2);
  int pt113 = gmsh::model::geo::addPoint(-b1, h1, g1);
  int pt114 = gmsh::model::geo::addPoint(-b2, h1, g1);
  int pt115 = gmsh::model::geo::addPoint(b2, h1, g1);
  int pt116 = gmsh::model::geo::addPoint(b1, h1, g1);

  // II Floor
  int pt21 = gmsh::model::geo::addPoint(-b1, h2, -g1);
  int pt22 = gmsh::model::geo::addPoint(-b2, h2, -g1);
  int pt23 = gmsh::model::geo::addPoint(b2, h2, -g1);
  int pt24 = gmsh::model::geo::addPoint(b1, h2, -g1);
  int pt25 = gmsh::model::geo::addPoint(-b1, h2, -g2);
  int pt26 = gmsh::model::geo::addPoint(-b2, h2, -g2);
  int pt27 = gmsh::model::geo::addPoint(b2, h2, -g2);
  int pt28 = gmsh::model::geo::addPoint(b1, h2, -g2);
  int pt29 = gmsh::model::geo::addPoint(-b1, h2, g2);
  int pt210 = gmsh::model::geo::addPoint(-b2, h2, g2);
  int pt211 = gmsh::model::geo::addPoint(b2, h2, g2);
  int pt212 = gmsh::model::geo::addPoint(b1, h2, g2);
  int pt213 = gmsh::model::geo::addPoint(-b1, h2, g1);
  int pt214 = gmsh::model::geo::addPoint(-b2, h2, g1);
  int pt215 = gmsh::model::geo::addPoint(b2, h2, g1);
  int pt216 = gmsh::model::geo::addPoint(b1, h2, g1);

  // III Floor
  int pt31 = gmsh::model::geo::addPoint(-b1, h3, -g1);
  int pt32 = gmsh::model::geo::addPoint(-b2, h3, -g1);
  int pt33 = gmsh::model::geo::addPoint(b2, h3, -g1);
  int pt34 = gmsh::model::geo::addPoint(b1, h3, -g1);
  int pt35 = gmsh::model::geo::addPoint(-b1, h3, -g2);
  int pt36 = gmsh::model::geo::addPoint(-b2, h3, -g2);
  int pt37 = gmsh::model::geo::addPoint(b2, h3, -g2);
  int pt38 = gmsh::model::geo::addPoint(b1, h3, -g2);
  int pt39 = gmsh::model::geo::addPoint(-b1, h3, g2);
  int pt310 = gmsh::model::geo::addPoint(-b2, h3, g2);
  int pt311 = gmsh::model::geo::addPoint(b2, h3, g2);
  int pt312 = gmsh::model::geo::addPoint(b1, h3, g2);
  int pt313 = gmsh::model::geo::addPoint(-b1, h3, g1);
  int pt314 = gmsh::model::geo::addPoint(-b2, h3, g1);
  int pt315 = gmsh::model::geo::addPoint(b2, h3, g1);
  int pt316 = gmsh::model::geo::addPoint(b1, h3, g1);

  // IV Floor
  int pt41 = gmsh::model::geo::addPoint(-b1, h4, -g1);
  int pt42 = gmsh::model::geo::addPoint(-b2, h4, -g1);
  int pt43 = gmsh::model::geo::addPoint(b2, h4, -g1);
  int pt44 = gmsh::model::geo::addPoint(b1, h4, -g1);
  int pt45 = gmsh::model::geo::addPoint(-b1, h4, -g2);
  int pt46 = gmsh::model::geo::addPoint(-b2, h4, -g2);
  int pt47 = gmsh::model::geo::addPoint(b2, h4, -g2);
  int pt48 = gmsh::model::geo::addPoint(b1, h4, -g2);
  int pt49 = gmsh::model::geo::addPoint(-b1, h4, g2);
  int pt410 = gmsh::model::geo::addPoint(-b2, h4, g2);
  int pt411 = gmsh::model::geo::addPoint(b2, h4, g2);
  int pt412 = gmsh::model::geo::addPoint(b1, h4, g2);
  int pt413 = gmsh::model::geo::addPoint(-b1, h4, g1);
  int pt414 = gmsh::model::geo::addPoint(-b2, h4, g1);
  int pt415 = gmsh::model::geo::addPoint(b2, h4, g1);
  int pt416 = gmsh::model::geo::addPoint(b1, h4, g1);

  // V Floor
  int pt51 = gmsh::model::geo::addPoint(-b1, h5, -g1);
  int pt52 = gmsh::model::geo::addPoint(-b2, h5, -g1);
  int pt53 = gmsh::model::geo::addPoint(b2, h5, -g1);
  int pt54 = gmsh::model::geo::addPoint(b1, h5, -g1);
  int pt55 = gmsh::model::geo::addPoint(-b1, h5, -g2);
  int pt56 = gmsh::model::geo::addPoint(-b2, h5, -g2);
  int pt57 = gmsh::model::geo::addPoint(b2, h5, -g2);
  int pt58 = gmsh::model::geo::addPoint(b1, h5, -g2);
  int pt59 = gmsh::model::geo::addPoint(-b1, h5, g2);
  int pt510 = gmsh::model::geo::addPoint(-b2, h5, g2);
  int pt511 = gmsh::model::geo::addPoint(b2, h5, g2);
  int pt512 = gmsh::model::geo::addPoint(b1, h5, g2);
  int pt513 = gmsh::model::geo::addPoint(-b1, h5, g1);
  int pt514 = gmsh::model::geo::addPoint(-b2, h5, g1);
  int pt515 = gmsh::model::geo::addPoint(b2, h5, g1);
  int pt516 = gmsh::model::geo::addPoint(b1, h5, g1);

  // VI Floor
  int pt61 = gmsh::model::geo::addPoint(-b1, h6, -g1);
  int pt62 = gmsh::model::geo::addPoint(-b2, h6, -g1);
  int pt63 = gmsh::model::geo::addPoint(b2, h6, -g1);
  int pt64 = gmsh::model::geo::addPoint(b1, h6, -g1);
  int pt65 = gmsh::model::geo::addPoint(-b1, h6, -g2);
  int pt66 = gmsh::model::geo::addPoint(-b2, h6, -g2);
  int pt67 = gmsh::model::geo::addPoint(b2, h6, -g2);
  int pt68 = gmsh::model::geo::addPoint(b1, h6, -g2);
  int pt69 = gmsh::model::geo::addPoint(-b1, h6, g2);
  int pt610 = gmsh::model::geo::addPoint(-b2, h6, g2);
  int pt611 = gmsh::model::geo::addPoint(b2, h6, g2);
  int pt612 = gmsh::model::geo::addPoint(b1, h6, g2);
  int pt613 = gmsh::model::geo::addPoint(-b1, h6, g1);
  int pt614 = gmsh::model::geo::addPoint(-b2, h6, g1);
  int pt615 = gmsh::model::geo::addPoint(b2, h6, g1);
  int pt616 = gmsh::model::geo::addPoint(b1, h6, g1);

  // VII Floor
  int pt71 = gmsh::model::geo::addPoint(-b1, h7, -g1);
  int pt72 = gmsh::model::geo::addPoint(-b2, h7, -g1);
  int pt73 = gmsh::model::geo::addPoint(b2, h7, -g1);
  int pt74 = gmsh::model::geo::addPoint(b1, h7, -g1);
  int pt75 = gmsh::model::geo::addPoint(-b1, h7, -g2);
  int pt76 = gmsh::model::geo::addPoint(-b2, h7, -g2);
  int pt77 = gmsh::model::geo::addPoint(b2, h7, -g2);
  int pt78 = gmsh::model::geo::addPoint(b1, h7, -g2);
  int pt79 = gmsh::model::geo::addPoint(-b1, h7, g2);
  int pt710 = gmsh::model::geo::addPoint(-b2, h7, g2);
  int pt711 = gmsh::model::geo::addPoint(b2, h7, g2);
  int pt712 = gmsh::model::geo::addPoint(b1, h7, g2);
  int pt713 = gmsh::model::geo::addPoint(-b1, h7, g1);
  int pt714 = gmsh::model::geo::addPoint(-b2, h7, g1);
  int pt715 = gmsh::model::geo::addPoint(b2, h7, g1);
  int pt716 = gmsh::model::geo::addPoint(b1, h7, g1);

  // Define lines between nodes

  // Beam I floor
  int l11 = gmsh::model::geo::addLine(pt11, pt12);
  int l12 = gmsh::model::geo::addLine(pt12, pt13);
  int l13 = gmsh::model::geo::addLine(pt13, pt14);
  int l14 = gmsh::model::geo::addLine(pt15, pt16);
  int l15 = gmsh::model::geo::addLine(pt16, pt17);
  int l16 = gmsh::model::geo::addLine(pt17, pt18);
  int l17 = gmsh::model::geo::addLine(pt19, pt110);
  int l18 = gmsh::model::geo::addLine(pt110, pt111);
  int l19 = gmsh::model::geo::addLine(pt111, pt112);
  int l110 = gmsh::model::geo::addLine(pt113, pt114);
  int l111 = gmsh::model::geo::addLine(pt114, pt115);
  int l112 = gmsh::model::geo::addLine(pt115, pt116);

  // Beam II floor
  int l21 = gmsh::model::geo::addLine(pt21, pt22);
  int l22 = gmsh::model::geo::addLine(pt22, pt23);
  int l23 = gmsh::model::geo::addLine(pt23, pt24);
  int l24 = gmsh::model::geo::addLine(pt25, pt26);
  int l25 = gmsh::model::geo::addLine(pt26, pt27);
  int l26 = gmsh::model::geo::addLine(pt27, pt28);
  int l27 = gmsh::model::geo::addLine(pt29, pt210);
  int l28 = gmsh::model::geo::addLine(pt210, pt211);
  int l29 = gmsh::model::geo::addLine(pt211, pt212);
  int l210 = gmsh::model::geo::addLine(pt213, pt214);
  int l211 = gmsh::model::geo::addLine(pt214, pt215);
  int l212 = gmsh::model::geo::addLine(pt215, pt216);

  // Beam III floor
  int l31 = gmsh::model::geo::addLine(pt31, pt32);
  int l32 = gmsh::model::geo::addLine(pt32, pt33);
  int l33 = gmsh::model::geo::addLine(pt33, pt34);
  int l34 = gmsh::model::geo::addLine(pt35, pt36);
  int l35 = gmsh::model::geo::addLine(pt36, pt37);
  int l36 = gmsh::model::geo::addLine(pt37, pt38);
  int l37 = gmsh::model::geo::addLine(pt39, pt310);
  int l38 = gmsh::model::geo::addLine(pt310, pt311);
  int l39 = gmsh::model::geo::addLine(pt311, pt312);
  int l310 = gmsh::model::geo::addLine(pt313, pt314);
  int l311 = gmsh::model::geo::addLine(pt314, pt315);
  int l312 = gmsh::model::geo::addLine(pt315, pt316);

  // Beam IV floor
  int l41 = gmsh::model::geo::addLine(pt41, pt42);
  int l42 = gmsh::model::geo::addLine(pt42, pt43);
  int l43 = gmsh::model::geo::addLine(pt43, pt44);
  int l44 = gmsh::model::geo::addLine(pt45, pt46);
  int l45 = gmsh::model::geo::addLine(pt46, pt47);
  int l46 = gmsh::model::geo::addLine(pt47, pt48);
  int l47 = gmsh::model::geo::addLine(pt49, pt410);
  int l48 = gmsh::model::geo::addLine(pt410, pt411);
  int l49 = gmsh::model::geo::addLine(pt411, pt412);
  int l410 = gmsh::model::geo::addLine(pt413, pt414);
  int l411 = gmsh::model::geo::addLine(pt414, pt415);
  int l412 = gmsh::model::geo::addLine(pt415, pt416);

  // Beam V floor
  int l51 = gmsh::model::geo::addLine(pt51, pt52);
  int l52 = gmsh::model::geo::addLine(pt52, pt53);
  int l53 = gmsh::model::geo::addLine(pt53, pt54);
  int l54 = gmsh::model::geo::addLine(pt55, pt56);
  int l55 = gmsh::model::geo::addLine(pt56, pt57);
  int l56 = gmsh::model::geo::addLine(pt57, pt58);
  int l57 = gmsh::model::geo::addLine(pt59, pt510);
  int l58 = gmsh::model::geo::addLine(pt510, pt511);
  int l59 = gmsh::model::geo::addLine(pt511, pt512);
  int l510 = gmsh::model::geo::addLine(pt513, pt514);
  int l511 = gmsh::model::geo::addLine(pt514, pt515);
  int l512 = gmsh::model::geo::addLine(pt515, pt516);

  // Beam VI floor
  int l61 = gmsh::model::geo::addLine(pt61, pt62);
  int l62 = gmsh::model::geo::addLine(pt62, pt63);
  int l63 = gmsh::model::geo::addLine(pt63, pt64);
  int l64 = gmsh::model::geo::addLine(pt65, pt66);
  int l65 = gmsh::model::geo::addLine(pt66, pt67);
  int l66 = gmsh::model::geo::addLine(pt67, pt68);
  int l67 = gmsh::model::geo::addLine(pt69, pt610);
  int l68 = gmsh::model::geo::addLine(pt610, pt611);
  int l69 = gmsh::model::geo::addLine(pt611, pt612);
  int l610 = gmsh::model::geo::addLine(pt613, pt614);
  int l611 = gmsh::model::geo::addLine(pt614, pt615);
  int l612 = gmsh::model::geo::addLine(pt615, pt616);

  // Beam VII floor
  int l71 = gmsh::model::geo::addLine(pt71, pt72);
  int l72 = gmsh::model::geo::addLine(pt72, pt73);
  int l73 = gmsh::model::geo::addLine(pt73, pt74);
  int l74 = gmsh::model::geo::addLine(pt75, pt76);
  int l75 = gmsh::model::geo::addLine(pt76, pt77);
  int l76 = gmsh::model::geo::addLine(pt77, pt78);
  int l77 = gmsh::model::geo::addLine(pt79, pt710);
  int l78 = gmsh::model::geo::addLine(pt710, pt711);
  int l79 = gmsh::model::geo::addLine(pt711, pt712);
  int l710 = gmsh::model::geo::addLine(pt713, pt714);
  int l711 = gmsh::model::geo::addLine(pt714, pt715);
  int l712 = gmsh::model::geo::addLine(pt715, pt716);

  // Girder I Floor
  int g11 = gmsh::model::geo::addLine(pt11, pt15);
  int g12 = gmsh::model::geo::addLine(pt15, pt19);
  int g13 = gmsh::model::geo::addLine(pt19, pt113);
  int g14 = gmsh::model::geo::addLine(pt12, pt16);
  int g15 = gmsh::model::geo::addLine(pt16, pt110);
  int g16 = gmsh::model::geo::addLine(pt110, pt114);
  int g17 = gmsh::model::geo::addLine(pt13, pt17);
  int g18 = gmsh::model::geo::addLine(pt17, pt111);
  int g19 = gmsh::model::geo::addLine(pt111, pt115);
  int g110 = gmsh::model::geo::addLine(pt14, pt18);
  int g111 = gmsh::model::geo::addLine(pt18, pt112);
  int g112 = gmsh::model::geo::addLine(pt112, pt116);

  // Girder II Floor
  int g21 = gmsh::model::geo::addLine(pt21, pt25);
  int g22 = gmsh::model::geo::addLine(pt25, pt29);
  int g23 = gmsh::model::geo::addLine(pt29, pt213);
  int g24 = gmsh::model::geo::addLine(pt22, pt26);
  int g25 = gmsh::model::geo::addLine(pt26, pt210);
  int g26 = gmsh::model::geo::addLine(pt210, pt214);
  int g27 = gmsh::model::geo::addLine(pt23, pt27);
  int g28 = gmsh::model::geo::addLine(pt27, pt211);
  int g29 = gmsh::model::geo::addLine(pt211, pt215);
  int g210 = gmsh::model::geo::addLine(pt24, pt28);
  int g211 = gmsh::model::geo::addLine(pt28, pt212);
  int g212 = gmsh::model::geo::addLine(pt212, pt216);

  // Girder III Floor
  int g31 = gmsh::model::geo::addLine(pt31, pt35);
  int g32 = gmsh::model::geo::addLine(pt35, pt39);
  int g33 = gmsh::model::geo::addLine(pt39, pt313);
  int g34 = gmsh::model::geo::addLine(pt32, pt36);
  int g35 = gmsh::model::geo::addLine(pt36, pt310);
  int g36 = gmsh::model::geo::addLine(pt310, pt314);
  int g37 = gmsh::model::geo::addLine(pt33, pt37);
  int g38 = gmsh::model::geo::addLine(pt37, pt311);
  int g39 = gmsh::model::geo::addLine(pt311, pt315);
  int g310 = gmsh::model::geo::addLine(pt34, pt38);
  int g311 = gmsh::model::geo::addLine(pt38, pt312);
  int g312 = gmsh::model::geo::addLine(pt312, pt316);

  // Girder IV Floor
  int g41 = gmsh::model::geo::addLine(pt41, pt45);
  int g42 = gmsh::model::geo::addLine(pt45, pt49);
  int g43 = gmsh::model::geo::addLine(pt49, pt413);
  int g44 = gmsh::model::geo::addLine(pt42, pt46);
  int g45 = gmsh::model::geo::addLine(pt46, pt410);
  int g46 = gmsh::model::geo::addLine(pt410, pt414);
  int g47 = gmsh::model::geo::addLine(pt43, pt47);
  int g48 = gmsh::model::geo::addLine(pt47, pt411);
  int g49 = gmsh::model::geo::addLine(pt411, pt415);
  int g410 = gmsh::model::geo::addLine(pt44, pt48);
  int g411 = gmsh::model::geo::addLine(pt48, pt412);
  int g412 = gmsh::model::geo::addLine(pt412, pt416);

  // Girder V Floor
  int g51 = gmsh::model::geo::addLine(pt51, pt55);
  int g52 = gmsh::model::geo::addLine(pt55, pt59);
  int g53 = gmsh::model::geo::addLine(pt59, pt513);
  int g54 = gmsh::model::geo::addLine(pt52, pt56);
  int g55 = gmsh::model::geo::addLine(pt56, pt510);
  int g56 = gmsh::model::geo::addLine(pt510, pt514);
  int g57 = gmsh::model::geo::addLine(pt53, pt57);
  int g58 = gmsh::model::geo::addLine(pt57, pt511);
  int g59 = gmsh::model::geo::addLine(pt511, pt515);
  int g510 = gmsh::model::geo::addLine(pt54, pt58);
  int g511 = gmsh::model::geo::addLine(pt58, pt512);
  int g512 = gmsh::model::geo::addLine(pt512, pt516);

  // Girder VI Floor
  int g61 = gmsh::model::geo::addLine(pt61, pt65);
  int g62 = gmsh::model::geo::addLine(pt65, pt69);
  int g63 = gmsh::model::geo::addLine(pt69, pt613);
  int g64 = gmsh::model::geo::addLine(pt62, pt66);
  int g65 = gmsh::model::geo::addLine(pt66, pt610);
  int g66 = gmsh::model::geo::addLine(pt610, pt614);
  int g67 = gmsh::model::geo::addLine(pt63, pt67);
  int g68 = gmsh::model::geo::addLine(pt67, pt611);
  int g69 = gmsh::model::geo::addLine(pt611, pt615);
  int g610 = gmsh::model::geo::addLine(pt64, pt68);
  int g611 = gmsh::model::geo::addLine(pt68, pt612);
  int g612 = gmsh::model::geo::addLine(pt612, pt616);

  // Girder VII Floor
  int g71 = gmsh::model::geo::addLine(pt71, pt75);
  int g72 = gmsh::model::geo::addLine(pt75, pt79);
  int g73 = gmsh::model::geo::addLine(pt79, pt713);
  int g74 = gmsh::model::geo::addLine(pt72, pt76);
  int g75 = gmsh::model::geo::addLine(pt76, pt710);
  int g76 = gmsh::model::geo::addLine(pt710, pt714);
  int g77 = gmsh::model::geo::addLine(pt73, pt77);
  int g78 = gmsh::model::geo::addLine(pt77, pt711);
  int g79 = gmsh::model::geo::addLine(pt711, pt715);
  int g710 = gmsh::model::geo::addLine(pt74, pt78);
  int g711 = gmsh::model::geo::addLine(pt78, pt712);
  int g712 = gmsh::model::geo::addLine(pt712, pt716);

  // Column I - I
  int c11 = gmsh::model::geo::addLine(pt01, pt11);
  int c12 = gmsh::model::geo::addLine(pt11, pt21);
  int c13 = gmsh::model::geo::addLine(pt21, pt31);
  int c14 = gmsh::model::geo::addLine(pt31, pt41);
  int c15 = gmsh::model::geo::addLine(pt41, pt51);
  int c16 = gmsh::model::geo::addLine(pt51, pt61);
  int c17 = gmsh::model::geo::addLine(pt61, pt71);

  // Column I - I
  int c21 = gmsh::model::geo::addLine(pt02, pt12);
  int c22 = gmsh::model::geo::addLine(pt12, pt22);
  int c23 = gmsh::model::geo::addLine(pt22, pt32);
  int c24 = gmsh::model::geo::addLine(pt32, pt42);
  int c25 = gmsh::model::geo::addLine(pt42, pt52);
  int c26 = gmsh::model::geo::addLine(pt52, pt62);
  int c27 = gmsh::model::geo::addLine(pt62, pt72);

  // Column I - II
  int c31 = gmsh::model::geo::addLine(pt03, pt13);
  int c32 = gmsh::model::geo::addLine(pt13, pt23);
  int c33 = gmsh::model::geo::addLine(pt23, pt33);
  int c34 = gmsh::model::geo::addLine(pt33, pt43);
  int c35 = gmsh::model::geo::addLine(pt43, pt53);
  int c36 = gmsh::model::geo::addLine(pt53, pt63);
  int c37 = gmsh::model::geo::addLine(pt63, pt73);

  // Column I - II
  int c41 = gmsh::model::geo::addLine(pt04, pt14);
  int c42 = gmsh::model::geo::addLine(pt14, pt24);
  int c43 = gmsh::model::geo::addLine(pt24, pt34);
  int c44 = gmsh::model::geo::addLine(pt34, pt44);
  int c45 = gmsh::model::geo::addLine(pt44, pt54);
  int c46 = gmsh::model::geo::addLine(pt54, pt64);
  int c47 = gmsh::model::geo::addLine(pt64, pt74);

  // Column II - I
  int c51 = gmsh::model::geo::addLine(pt05, pt15);
  int c52 = gmsh::model::geo::addLine(pt15, pt25);
  int c53 = gmsh::model::geo::addLine(pt25, pt35);
  int c54 = gmsh::model::geo::addLine(pt35, pt45);
  int c55 = gmsh::model::geo::addLine(pt45, pt55);
  int c56 = gmsh::model::geo::addLine(pt55, pt65);
  int c57 = gmsh::model::geo::addLine(pt65, pt75);

  // Column II - II
  int c61 = gmsh::model::geo::addLine(pt06, pt16);
  int c62 = gmsh::model::geo::addLine(pt16, pt26);
  int c63 = gmsh::model::geo::addLine(pt26, pt36);
  int c64 = gmsh::model::geo::addLine(pt36, pt46);
  int c65 = gmsh::model::geo::addLine(pt46, pt56);
  int c66 = gmsh::model::geo::addLine(pt56, pt66);
  int c67 = gmsh::model::geo::addLine(pt66, pt76);

  // Column II - III
  int c71 = gmsh::model::geo::addLine(pt07, pt17);
  int c72 = gmsh::model::geo::addLine(pt17, pt27);
  int c73 = gmsh::model::geo::addLine(pt27, pt37);
  int c74 = gmsh::model::geo::addLine(pt37, pt47);
  int c75 = gmsh::model::geo::addLine(pt47, pt57);
  int c76 = gmsh::model::geo::addLine(pt57, pt67);
  int c77 = gmsh::model::geo::addLine(pt67, pt77);

  // Column II - IV
  int c81 = gmsh::model::geo::addLine(pt08, pt18);
  int c82 = gmsh::model::geo::addLine(pt18, pt28);
  int c83 = gmsh::model::geo::addLine(pt28, pt38);
  int c84 = gmsh::model::geo::addLine(pt38, pt48);
  int c85 = gmsh::model::geo::addLine(pt48, pt58);
  int c86 = gmsh::model::geo::addLine(pt58, pt68);
  int c87 = gmsh::model::geo::addLine(pt68, pt78);

  // Column III - I
  int c91 = gmsh::model::geo::addLine(pt09, pt19);
  int c92 = gmsh::model::geo::addLine(pt19, pt29);
  int c93 = gmsh::model::geo::addLine(pt29, pt39);
  int c94 = gmsh::model::geo::addLine(pt39, pt49);
  int c95 = gmsh::model::geo::addLine(pt49, pt59);
  int c96 = gmsh::model::geo::addLine(pt59, pt69);
  int c97 = gmsh::model::geo::addLine(pt69, pt79);

  // Column III - II
  int c101 = gmsh::model::geo::addLine(pt010, pt110);
  int c102 = gmsh::model::geo::addLine(pt110, pt210);
  int c103 = gmsh::model::geo::addLine(pt210, pt310);
  int c104 = gmsh::model::geo::addLine(pt310, pt410);
  int c105 = gmsh::model::geo::addLine(pt410, pt510);
  int c106 = gmsh::model::geo::addLine(pt510, pt610);
  int c107 = gmsh::model::geo::addLine(pt610, pt710);

  // Column III - III
  int c111 = gmsh::model::geo::addLine(pt011, pt111);
  int c112 = gmsh::model::geo::addLine(pt111, pt211);
  int c113 = gmsh::model::geo::addLine(pt211, pt311);
  int c114 = gmsh::model::geo::addLine(pt311, pt411);
  int c115 = gmsh::model::geo::addLine(pt411, pt511);
  int c116 = gmsh::model::geo::addLine(pt511, pt611);
  int c117 = gmsh::model::geo::addLine(pt611, pt711);

  // Column III - IV
  int c121 = gmsh::model::geo::addLine(pt012, pt112);
  int c122 = gmsh::model::geo::addLine(pt112, pt212);
  int c123 = gmsh::model::geo::addLine(pt212, pt312);
  int c124 = gmsh::model::geo::addLine(pt312, pt412);
  int c125 = gmsh::model::geo::addLine(pt412, pt512);
  int c126 = gmsh::model::geo::addLine(pt512, pt612);
  int c127 = gmsh::model::geo::addLine(pt612, pt712);

  // Column IV - I
  int c131 = gmsh::model::geo::addLine(pt013, pt113);
  int c132 = gmsh::model::geo::addLine(pt113, pt213);
  int c133 = gmsh::model::geo::addLine(pt213, pt313);
  int c134 = gmsh::model::geo::addLine(pt313, pt413);
  int c135 = gmsh::model::geo::addLine(pt413, pt513);
  int c136 = gmsh::model::geo::addLine(pt513, pt613);
  int c137 = gmsh::model::geo::addLine(pt613, pt713);

  // Column IV - II
  int c141 = gmsh::model::geo::addLine(pt014, pt114);
  int c142 = gmsh::model::geo::addLine(pt114, pt214);
  int c143 = gmsh::model::geo::addLine(pt214, pt314);
  int c144 = gmsh::model::geo::addLine(pt314, pt414);
  int c145 = gmsh::model::geo::addLine(pt414, pt514);
  int c146 = gmsh::model::geo::addLine(pt514, pt614);
  int c147 = gmsh::model::geo::addLine(pt614, pt714);

  // Column IV - III
  int c151 = gmsh::model::geo::addLine(pt015, pt115);
  int c152 = gmsh::model::geo::addLine(pt115, pt215);
  int c153 = gmsh::model::geo::addLine(pt215, pt315);
  int c154 = gmsh::model::geo::addLine(pt315, pt415);
  int c155 = gmsh::model::geo::addLine(pt415, pt515);
  int c156 = gmsh::model::geo::addLine(pt515, pt615);
  int c157 = gmsh::model::geo::addLine(pt615, pt715);

  // Column IV - IV
  int c161 = gmsh::model::geo::addLine(pt016, pt116);
  int c162 = gmsh::model::geo::addLine(pt116, pt216);
  int c163 = gmsh::model::geo::addLine(pt216, pt316);
  int c164 = gmsh::model::geo::addLine(pt316, pt416);
  int c165 = gmsh::model::geo::addLine(pt416, pt516);
  int c166 = gmsh::model::geo::addLine(pt516, pt616);
  int c167 = gmsh::model::geo::addLine(pt616, pt716);

  // syn the goemetry
  gmsh::model::geo::synchronize();

  // Define Physical Groups
  int nodeBasePG = gmsh::model::addPhysicalGroup(
      0, {pt01, pt02, pt03, pt04, pt05, pt06, pt07, pt08, pt09, pt010, pt011,
          pt012, pt013, pt014, pt015, pt016});

  int nodeFloorIPG = gmsh::model::addPhysicalGroup(
      0, {pt11, pt12, pt13, pt14, pt15, pt16, pt17, pt18, pt19, pt110, pt111,
          pt112, pt113, pt114, pt115, pt116});

  int nodeFloorIIPG = gmsh::model::addPhysicalGroup(
      0, {pt21, pt22, pt23, pt24, pt25, pt26, pt27, pt28, pt29, pt210, pt211,
          pt212, pt213, pt214, pt215, pt216});

  int nodeFloorIIIPG = gmsh::model::addPhysicalGroup(
      0, {pt31, pt32, pt33, pt34, pt35, pt36, pt37, pt38, pt39, pt310, pt311,
          pt312, pt313, pt314, pt315, pt316});

  int nodeFloorIVPG = gmsh::model::addPhysicalGroup(
      0, {pt41, pt42, pt43, pt44, pt45, pt46, pt47, pt48, pt49, pt410, pt411,
          pt412, pt413, pt414, pt415, pt416});

  int nodeFloorVPG = gmsh::model::addPhysicalGroup(
      0, {pt51, pt52, pt53, pt54, pt55, pt56, pt57, pt58, pt59, pt510, pt511,
          pt512, pt513, pt514, pt515, pt516});

  int nodeFloorVIPG = gmsh::model::addPhysicalGroup(
      0, {pt61, pt62, pt63, pt64, pt65, pt66, pt67, pt68, pt69, pt610, pt611,
          pt612, pt613, pt614, pt615, pt616});

  int nodeFloorVIIPG = gmsh::model::addPhysicalGroup(
      0, {pt71, pt72, pt73, pt74, pt75, pt76, pt77, pt78, pt79, pt710, pt711,
          pt712, pt713, pt714, pt715, pt716});

  // Set Transfinite for Mesh
  int meshBeam = 10;
  int meshCol = 10;
  int meshGir = 10;

  // Columns
  gmsh::model::mesh::setTransfiniteCurve(c11, meshCol);
  gmsh::model::mesh::setTransfiniteCurve(c21, meshCol);
  gmsh::model::mesh::setTransfiniteCurve(c31, meshCol);
  gmsh::model::mesh::setTransfiniteCurve(c41, meshCol);
  gmsh::model::mesh::setTransfiniteCurve(c12, meshCol);
  gmsh::model::mesh::setTransfiniteCurve(c22, meshCol);
  gmsh::model::mesh::setTransfiniteCurve(c32, meshCol);
  gmsh::model::mesh::setTransfiniteCurve(c42, meshCol);
  gmsh::model::mesh::setTransfiniteCurve(c13, meshCol);
  gmsh::model::mesh::setTransfiniteCurve(c23, meshCol);
  gmsh::model::mesh::setTransfiniteCurve(c33, meshCol);
  gmsh::model::mesh::setTransfiniteCurve(c43, meshCol);
  gmsh::model::mesh::setTransfiniteCurve(c14, meshCol);
  gmsh::model::mesh::setTransfiniteCurve(c24, meshCol);
  gmsh::model::mesh::setTransfiniteCurve(c34, meshCol);
  gmsh::model::mesh::setTransfiniteCurve(c44, meshCol);
  gmsh::model::mesh::setTransfiniteCurve(c15, meshCol);
  gmsh::model::mesh::setTransfiniteCurve(c25, meshCol);
  gmsh::model::mesh::setTransfiniteCurve(c35, meshCol);
  gmsh::model::mesh::setTransfiniteCurve(c45, meshCol);
  gmsh::model::mesh::setTransfiniteCurve(c16, meshCol);
  gmsh::model::mesh::setTransfiniteCurve(c26, meshCol);
  gmsh::model::mesh::setTransfiniteCurve(c36, meshCol);
  gmsh::model::mesh::setTransfiniteCurve(c46, meshCol);
  gmsh::model::mesh::setTransfiniteCurve(c17, meshCol);
  gmsh::model::mesh::setTransfiniteCurve(c27, meshCol);
  gmsh::model::mesh::setTransfiniteCurve(c37, meshCol);
  gmsh::model::mesh::setTransfiniteCurve(c47, meshCol);
  gmsh::model::mesh::setTransfiniteCurve(c51, meshCol);
  gmsh::model::mesh::setTransfiniteCurve(c61, meshCol);
  gmsh::model::mesh::setTransfiniteCurve(c71, meshCol);
  gmsh::model::mesh::setTransfiniteCurve(c81, meshCol);
  gmsh::model::mesh::setTransfiniteCurve(c52, meshCol);
  gmsh::model::mesh::setTransfiniteCurve(c62, meshCol);
  gmsh::model::mesh::setTransfiniteCurve(c72, meshCol);
  gmsh::model::mesh::setTransfiniteCurve(c82, meshCol);
  gmsh::model::mesh::setTransfiniteCurve(c53, meshCol);
  gmsh::model::mesh::setTransfiniteCurve(c63, meshCol);
  gmsh::model::mesh::setTransfiniteCurve(c73, meshCol);
  gmsh::model::mesh::setTransfiniteCurve(c83, meshCol);
  gmsh::model::mesh::setTransfiniteCurve(c54, meshCol);
  gmsh::model::mesh::setTransfiniteCurve(c64, meshCol);
  gmsh::model::mesh::setTransfiniteCurve(c74, meshCol);
  gmsh::model::mesh::setTransfiniteCurve(c84, meshCol);
  gmsh::model::mesh::setTransfiniteCurve(c55, meshCol);
  gmsh::model::mesh::setTransfiniteCurve(c65, meshCol);
  gmsh::model::mesh::setTransfiniteCurve(c75, meshCol);
  gmsh::model::mesh::setTransfiniteCurve(c85, meshCol);
  gmsh::model::mesh::setTransfiniteCurve(c56, meshCol);
  gmsh::model::mesh::setTransfiniteCurve(c66, meshCol);
  gmsh::model::mesh::setTransfiniteCurve(c76, meshCol);
  gmsh::model::mesh::setTransfiniteCurve(c86, meshCol);
  gmsh::model::mesh::setTransfiniteCurve(c57, meshCol);
  gmsh::model::mesh::setTransfiniteCurve(c67, meshCol);
  gmsh::model::mesh::setTransfiniteCurve(c77, meshCol);
  gmsh::model::mesh::setTransfiniteCurve(c87, meshCol);
  gmsh::model::mesh::setTransfiniteCurve(c91, meshCol);
  gmsh::model::mesh::setTransfiniteCurve(c101, meshCol);
  gmsh::model::mesh::setTransfiniteCurve(c111, meshCol);
  gmsh::model::mesh::setTransfiniteCurve(c121, meshCol);
  gmsh::model::mesh::setTransfiniteCurve(c92, meshCol);
  gmsh::model::mesh::setTransfiniteCurve(c102, meshCol);
  gmsh::model::mesh::setTransfiniteCurve(c112, meshCol);
  gmsh::model::mesh::setTransfiniteCurve(c122, meshCol);
  gmsh::model::mesh::setTransfiniteCurve(c93, meshCol);
  gmsh::model::mesh::setTransfiniteCurve(c103, meshCol);
  gmsh::model::mesh::setTransfiniteCurve(c113, meshCol);
  gmsh::model::mesh::setTransfiniteCurve(c123, meshCol);
  gmsh::model::mesh::setTransfiniteCurve(c94, meshCol);
  gmsh::model::mesh::setTransfiniteCurve(c104, meshCol);
  gmsh::model::mesh::setTransfiniteCurve(c114, meshCol);
  gmsh::model::mesh::setTransfiniteCurve(c124, meshCol);
  gmsh::model::mesh::setTransfiniteCurve(c95, meshCol);
  gmsh::model::mesh::setTransfiniteCurve(c105, meshCol);
  gmsh::model::mesh::setTransfiniteCurve(c115, meshCol);
  gmsh::model::mesh::setTransfiniteCurve(c125, meshCol);
  gmsh::model::mesh::setTransfiniteCurve(c96, meshCol);
  gmsh::model::mesh::setTransfiniteCurve(c106, meshCol);
  gmsh::model::mesh::setTransfiniteCurve(c116, meshCol);
  gmsh::model::mesh::setTransfiniteCurve(c126, meshCol);
  gmsh::model::mesh::setTransfiniteCurve(c97, meshCol);
  gmsh::model::mesh::setTransfiniteCurve(c107, meshCol);
  gmsh::model::mesh::setTransfiniteCurve(c117, meshCol);
  gmsh::model::mesh::setTransfiniteCurve(c127, meshCol);
  gmsh::model::mesh::setTransfiniteCurve(c131, meshCol);
  gmsh::model::mesh::setTransfiniteCurve(c141, meshCol);
  gmsh::model::mesh::setTransfiniteCurve(c151, meshCol);
  gmsh::model::mesh::setTransfiniteCurve(c161, meshCol);
  gmsh::model::mesh::setTransfiniteCurve(c132, meshCol);
  gmsh::model::mesh::setTransfiniteCurve(c142, meshCol);
  gmsh::model::mesh::setTransfiniteCurve(c152, meshCol);
  gmsh::model::mesh::setTransfiniteCurve(c162, meshCol);
  gmsh::model::mesh::setTransfiniteCurve(c133, meshCol);
  gmsh::model::mesh::setTransfiniteCurve(c143, meshCol);
  gmsh::model::mesh::setTransfiniteCurve(c153, meshCol);
  gmsh::model::mesh::setTransfiniteCurve(c163, meshCol);
  gmsh::model::mesh::setTransfiniteCurve(c134, meshCol);
  gmsh::model::mesh::setTransfiniteCurve(c144, meshCol);
  gmsh::model::mesh::setTransfiniteCurve(c154, meshCol);
  gmsh::model::mesh::setTransfiniteCurve(c164, meshCol);
  gmsh::model::mesh::setTransfiniteCurve(c135, meshCol);
  gmsh::model::mesh::setTransfiniteCurve(c145, meshCol);
  gmsh::model::mesh::setTransfiniteCurve(c155, meshCol);
  gmsh::model::mesh::setTransfiniteCurve(c165, meshCol);
  gmsh::model::mesh::setTransfiniteCurve(c136, meshCol);
  gmsh::model::mesh::setTransfiniteCurve(c146, meshCol);
  gmsh::model::mesh::setTransfiniteCurve(c156, meshCol);
  gmsh::model::mesh::setTransfiniteCurve(c166, meshCol);
  gmsh::model::mesh::setTransfiniteCurve(c137, meshCol);
  gmsh::model::mesh::setTransfiniteCurve(c147, meshCol);
  gmsh::model::mesh::setTransfiniteCurve(c157, meshCol);
  gmsh::model::mesh::setTransfiniteCurve(c167, meshCol);

  // Beams
  gmsh::model::mesh::setTransfiniteCurve(l11, meshBeam);
  gmsh::model::mesh::setTransfiniteCurve(l21, meshBeam);
  gmsh::model::mesh::setTransfiniteCurve(l31, meshBeam);
  gmsh::model::mesh::setTransfiniteCurve(l12, meshBeam);
  gmsh::model::mesh::setTransfiniteCurve(l22, meshBeam);
  gmsh::model::mesh::setTransfiniteCurve(l32, meshBeam);
  gmsh::model::mesh::setTransfiniteCurve(l13, meshBeam);
  gmsh::model::mesh::setTransfiniteCurve(l23, meshBeam);
  gmsh::model::mesh::setTransfiniteCurve(l33, meshBeam);
  gmsh::model::mesh::setTransfiniteCurve(l14, meshBeam);
  gmsh::model::mesh::setTransfiniteCurve(l24, meshBeam);
  gmsh::model::mesh::setTransfiniteCurve(l34, meshBeam);
  gmsh::model::mesh::setTransfiniteCurve(l15, meshBeam);
  gmsh::model::mesh::setTransfiniteCurve(l25, meshBeam);
  gmsh::model::mesh::setTransfiniteCurve(l35, meshBeam);
  gmsh::model::mesh::setTransfiniteCurve(l16, meshBeam);
  gmsh::model::mesh::setTransfiniteCurve(l26, meshBeam);
  gmsh::model::mesh::setTransfiniteCurve(l36, meshBeam);
  gmsh::model::mesh::setTransfiniteCurve(l17, meshBeam);
  gmsh::model::mesh::setTransfiniteCurve(l27, meshBeam);
  gmsh::model::mesh::setTransfiniteCurve(l37, meshBeam);
  gmsh::model::mesh::setTransfiniteCurve(l18, meshBeam);
  gmsh::model::mesh::setTransfiniteCurve(l28, meshBeam);
  gmsh::model::mesh::setTransfiniteCurve(l38, meshBeam);
  gmsh::model::mesh::setTransfiniteCurve(l19, meshBeam);
  gmsh::model::mesh::setTransfiniteCurve(l29, meshBeam);
  gmsh::model::mesh::setTransfiniteCurve(l39, meshBeam);
  gmsh::model::mesh::setTransfiniteCurve(l110, meshBeam);
  gmsh::model::mesh::setTransfiniteCurve(l210, meshBeam);
  gmsh::model::mesh::setTransfiniteCurve(l310, meshBeam);
  gmsh::model::mesh::setTransfiniteCurve(l111, meshBeam);
  gmsh::model::mesh::setTransfiniteCurve(l211, meshBeam);
  gmsh::model::mesh::setTransfiniteCurve(l311, meshBeam);
  gmsh::model::mesh::setTransfiniteCurve(l112, meshBeam);
  gmsh::model::mesh::setTransfiniteCurve(l212, meshBeam);
  gmsh::model::mesh::setTransfiniteCurve(l312, meshBeam);
  gmsh::model::mesh::setTransfiniteCurve(l41, meshBeam);
  gmsh::model::mesh::setTransfiniteCurve(l51, meshBeam);
  gmsh::model::mesh::setTransfiniteCurve(l61, meshBeam);
  gmsh::model::mesh::setTransfiniteCurve(l42, meshBeam);
  gmsh::model::mesh::setTransfiniteCurve(l52, meshBeam);
  gmsh::model::mesh::setTransfiniteCurve(l62, meshBeam);
  gmsh::model::mesh::setTransfiniteCurve(l43, meshBeam);
  gmsh::model::mesh::setTransfiniteCurve(l53, meshBeam);
  gmsh::model::mesh::setTransfiniteCurve(l63, meshBeam);
  gmsh::model::mesh::setTransfiniteCurve(l44, meshBeam);
  gmsh::model::mesh::setTransfiniteCurve(l54, meshBeam);
  gmsh::model::mesh::setTransfiniteCurve(l64, meshBeam);
  gmsh::model::mesh::setTransfiniteCurve(l45, meshBeam);
  gmsh::model::mesh::setTransfiniteCurve(l55, meshBeam);
  gmsh::model::mesh::setTransfiniteCurve(l65, meshBeam);
  gmsh::model::mesh::setTransfiniteCurve(l46, meshBeam);
  gmsh::model::mesh::setTransfiniteCurve(l56, meshBeam);
  gmsh::model::mesh::setTransfiniteCurve(l66, meshBeam);
  gmsh::model::mesh::setTransfiniteCurve(l47, meshBeam);
  gmsh::model::mesh::setTransfiniteCurve(l57, meshBeam);
  gmsh::model::mesh::setTransfiniteCurve(l67, meshBeam);
  gmsh::model::mesh::setTransfiniteCurve(l48, meshBeam);
  gmsh::model::mesh::setTransfiniteCurve(l58, meshBeam);
  gmsh::model::mesh::setTransfiniteCurve(l68, meshBeam);
  gmsh::model::mesh::setTransfiniteCurve(l49, meshBeam);
  gmsh::model::mesh::setTransfiniteCurve(l59, meshBeam);
  gmsh::model::mesh::setTransfiniteCurve(l69, meshBeam);
  gmsh::model::mesh::setTransfiniteCurve(l410, meshBeam);
  gmsh::model::mesh::setTransfiniteCurve(l510, meshBeam);
  gmsh::model::mesh::setTransfiniteCurve(l610, meshBeam);
  gmsh::model::mesh::setTransfiniteCurve(l411, meshBeam);
  gmsh::model::mesh::setTransfiniteCurve(l511, meshBeam);
  gmsh::model::mesh::setTransfiniteCurve(l611, meshBeam);
  gmsh::model::mesh::setTransfiniteCurve(l412, meshBeam);
  gmsh::model::mesh::setTransfiniteCurve(l512, meshBeam);
  gmsh::model::mesh::setTransfiniteCurve(l612, meshBeam);
  gmsh::model::mesh::setTransfiniteCurve(l71, meshBeam);
  gmsh::model::mesh::setTransfiniteCurve(l72, meshBeam);
  gmsh::model::mesh::setTransfiniteCurve(l73, meshBeam);
  gmsh::model::mesh::setTransfiniteCurve(l74, meshBeam);
  gmsh::model::mesh::setTransfiniteCurve(l75, meshBeam);
  gmsh::model::mesh::setTransfiniteCurve(l76, meshBeam);
  gmsh::model::mesh::setTransfiniteCurve(l77, meshBeam);
  gmsh::model::mesh::setTransfiniteCurve(l78, meshBeam);
  gmsh::model::mesh::setTransfiniteCurve(l79, meshBeam);
  gmsh::model::mesh::setTransfiniteCurve(l710, meshBeam);
  gmsh::model::mesh::setTransfiniteCurve(l711, meshBeam);
  gmsh::model::mesh::setTransfiniteCurve(l712, meshBeam);

  // Girders

  gmsh::model::mesh::setTransfiniteCurve(g11, meshGir);
  gmsh::model::mesh::setTransfiniteCurve(g21, meshGir);
  gmsh::model::mesh::setTransfiniteCurve(g31, meshGir);
  gmsh::model::mesh::setTransfiniteCurve(g12, meshGir);
  gmsh::model::mesh::setTransfiniteCurve(g22, meshGir);
  gmsh::model::mesh::setTransfiniteCurve(g32, meshGir);
  gmsh::model::mesh::setTransfiniteCurve(g13, meshGir);
  gmsh::model::mesh::setTransfiniteCurve(g23, meshGir);
  gmsh::model::mesh::setTransfiniteCurve(g33, meshGir);
  gmsh::model::mesh::setTransfiniteCurve(g14, meshGir);
  gmsh::model::mesh::setTransfiniteCurve(g24, meshGir);
  gmsh::model::mesh::setTransfiniteCurve(g34, meshGir);
  gmsh::model::mesh::setTransfiniteCurve(g15, meshGir);
  gmsh::model::mesh::setTransfiniteCurve(g25, meshGir);
  gmsh::model::mesh::setTransfiniteCurve(g35, meshGir);
  gmsh::model::mesh::setTransfiniteCurve(g16, meshGir);
  gmsh::model::mesh::setTransfiniteCurve(g26, meshGir);
  gmsh::model::mesh::setTransfiniteCurve(g36, meshGir);
  gmsh::model::mesh::setTransfiniteCurve(g17, meshGir);
  gmsh::model::mesh::setTransfiniteCurve(g27, meshGir);
  gmsh::model::mesh::setTransfiniteCurve(g37, meshGir);
  gmsh::model::mesh::setTransfiniteCurve(g18, meshGir);
  gmsh::model::mesh::setTransfiniteCurve(g28, meshGir);
  gmsh::model::mesh::setTransfiniteCurve(g38, meshGir);
  gmsh::model::mesh::setTransfiniteCurve(g19, meshGir);
  gmsh::model::mesh::setTransfiniteCurve(g29, meshGir);
  gmsh::model::mesh::setTransfiniteCurve(g39, meshGir);
  gmsh::model::mesh::setTransfiniteCurve(g110, meshGir);
  gmsh::model::mesh::setTransfiniteCurve(g210, meshGir);
  gmsh::model::mesh::setTransfiniteCurve(g310, meshGir);
  gmsh::model::mesh::setTransfiniteCurve(g111, meshGir);
  gmsh::model::mesh::setTransfiniteCurve(g211, meshGir);
  gmsh::model::mesh::setTransfiniteCurve(g311, meshGir);
  gmsh::model::mesh::setTransfiniteCurve(g112, meshGir);
  gmsh::model::mesh::setTransfiniteCurve(g212, meshGir);
  gmsh::model::mesh::setTransfiniteCurve(g312, meshGir);
  gmsh::model::mesh::setTransfiniteCurve(g41, meshGir);
  gmsh::model::mesh::setTransfiniteCurve(g51, meshGir);
  gmsh::model::mesh::setTransfiniteCurve(g61, meshGir);
  gmsh::model::mesh::setTransfiniteCurve(g42, meshGir);
  gmsh::model::mesh::setTransfiniteCurve(g52, meshGir);
  gmsh::model::mesh::setTransfiniteCurve(g62, meshGir);
  gmsh::model::mesh::setTransfiniteCurve(g43, meshGir);
  gmsh::model::mesh::setTransfiniteCurve(g53, meshGir);
  gmsh::model::mesh::setTransfiniteCurve(g63, meshGir);
  gmsh::model::mesh::setTransfiniteCurve(g44, meshGir);
  gmsh::model::mesh::setTransfiniteCurve(g54, meshGir);
  gmsh::model::mesh::setTransfiniteCurve(g64, meshGir);
  gmsh::model::mesh::setTransfiniteCurve(g45, meshGir);
  gmsh::model::mesh::setTransfiniteCurve(g55, meshGir);
  gmsh::model::mesh::setTransfiniteCurve(g65, meshGir);
  gmsh::model::mesh::setTransfiniteCurve(g46, meshGir);
  gmsh::model::mesh::setTransfiniteCurve(g56, meshGir);
  gmsh::model::mesh::setTransfiniteCurve(g66, meshGir);
  gmsh::model::mesh::setTransfiniteCurve(g47, meshGir);
  gmsh::model::mesh::setTransfiniteCurve(g57, meshGir);
  gmsh::model::mesh::setTransfiniteCurve(g67, meshGir);
  gmsh::model::mesh::setTransfiniteCurve(g48, meshGir);
  gmsh::model::mesh::setTransfiniteCurve(g58, meshGir);
  gmsh::model::mesh::setTransfiniteCurve(g68, meshGir);
  gmsh::model::mesh::setTransfiniteCurve(g49, meshGir);
  gmsh::model::mesh::setTransfiniteCurve(g59, meshGir);
  gmsh::model::mesh::setTransfiniteCurve(g69, meshGir);
  gmsh::model::mesh::setTransfiniteCurve(g410, meshGir);
  gmsh::model::mesh::setTransfiniteCurve(g510, meshGir);
  gmsh::model::mesh::setTransfiniteCurve(g610, meshGir);
  gmsh::model::mesh::setTransfiniteCurve(g411, meshGir);
  gmsh::model::mesh::setTransfiniteCurve(g511, meshGir);
  gmsh::model::mesh::setTransfiniteCurve(g611, meshGir);
  gmsh::model::mesh::setTransfiniteCurve(g412, meshGir);
  gmsh::model::mesh::setTransfiniteCurve(g512, meshGir);
  gmsh::model::mesh::setTransfiniteCurve(g612, meshGir);
  gmsh::model::mesh::setTransfiniteCurve(g71, meshGir);
  gmsh::model::mesh::setTransfiniteCurve(g72, meshGir);
  gmsh::model::mesh::setTransfiniteCurve(g73, meshGir);
  gmsh::model::mesh::setTransfiniteCurve(g74, meshGir);
  gmsh::model::mesh::setTransfiniteCurve(g75, meshGir);
  gmsh::model::mesh::setTransfiniteCurve(g76, meshGir);
  gmsh::model::mesh::setTransfiniteCurve(g77, meshGir);
  gmsh::model::mesh::setTransfiniteCurve(g78, meshGir);
  gmsh::model::mesh::setTransfiniteCurve(g79, meshGir);
  gmsh::model::mesh::setTransfiniteCurve(g710, meshGir);
  gmsh::model::mesh::setTransfiniteCurve(g711, meshGir);
  gmsh::model::mesh::setTransfiniteCurve(g712, meshGir);

  // genrate 1D mesh
  gmsh::model::mesh::generate(1);

  // ---- query the nodes ----
  std::vector<size_t> nodeTags;
  std::vector<double> unshapedNodeCoords, __;
  std::vector<std::vector<double>> nodeCoords;
  gmsh::model::mesh::getNodes(nodeTags, unshapedNodeCoords, __);
  reshapeNodeCoords(unshapedNodeCoords, nodeCoords);
  // ---- query the elements
  // columns
  std::vector<int> listCol = {
      c11,  c21,  c31,  c41,  c12,  c22,  c32,  c42,  c13,  c23,  c33,  c43,
      c14,  c24,  c34,  c44,  c15,  c25,  c35,  c45,  c16,  c26,  c36,  c46,
      c17,  c27,  c37,  c47,  c51,  c61,  c71,  c81,  c52,  c62,  c72,  c82,
      c53,  c63,  c73,  c83,  c54,  c64,  c74,  c84,  c55,  c65,  c75,  c85,
      c56,  c66,  c76,  c86,  c57,  c67,  c77,  c87,  c91,  c101, c111, c121,
      c92,  c102, c112, c122, c93,  c103, c113, c123, c94,  c104, c114, c124,
      c95,  c105, c115, c125, c96,  c106, c116, c126, c97,  c107, c117, c127,
      c131, c141, c151, c161, c132, c142, c152, c162, c133, c143, c153, c163,
      c134, c144, c154, c164, c135, c145, c155, c165, c136, c146, c156, c166,
      c137, c147, c157, c167};

  std::vector<size_t> elemTagsCol;
  std::vector<std::vector<size_t>> elemNodeTagsCol;

  getLineElementInfo(listCol, elemTagsCol, elemNodeTagsCol);
  // beams
  std::vector<int> listBeam = {
      l11, l21, l31, l12,  l22,  l32,  l13,  l23,  l33,  l14,  l24,  l34,
      l15, l25, l35, l16,  l26,  l36,  l17,  l27,  l37,  l18,  l28,  l38,
      l19, l29, l39, l110, l210, l310, l111, l211, l311, l112, l212, l312,
      l41, l51, l61, l42,  l52,  l62,  l43,  l53,  l63,  l44,  l54,  l64,
      l45, l55, l65, l46,  l56,  l66,  l47,  l57,  l67,  l48,  l58,  l68,
      l49, l59, l69, l410, l510, l610, l411, l511, l611, l412, l512, l612,
      l71, l72, l73, l74,  l75,  l76,  l77,  l78,  l79,  l710, l711, l712};

  std::vector<size_t> elemTagsBeam;
  std::vector<std::vector<size_t>> elemNodeTagsBeam;

  getLineElementInfo(listBeam, elemTagsBeam, elemNodeTagsBeam);

  // girdersr
  std::vector<int> listGir = {
      g11, g21, g31, g12,  g22,  g32,  g13,  g23,  g33,  g14,  g24,  g34,
      g15, g25, g35, g16,  g26,  g36,  g17,  g27,  g37,  g18,  g28,  g38,
      g19, g29, g39, g110, g210, g310, g111, g211, g311, g112, g212, g312,
      g41, g51, g61, g42,  g52,  g62,  g43,  g53,  g63,  g44,  g54,  g64,
      g45, g55, g65, g46,  g56,  g66,  g47,  g57,  g67,  g48,  g58,  g68,
      g49, g59, g69, g410, g510, g610, g411, g511, g611, g412, g512, g612,
      g71, g72, g73, g74,  g75,  g76,  g77,  g78,  g79,  g710, g711, g712};

  std::vector<size_t> elemTagsGir;
  std::vector<std::vector<size_t>> elemNodeTagsGir;

  getLineElementInfo(listGir, elemTagsGir, elemNodeTagsGir);

  // ---- get the floors nodes
  std::vector<size_t> IFloorNodes, IIFloorNodes, IIIFloorNodes, IVFloorNodes,
      VFloorNodes, VIFloorNodes, VIIFloorNodes, baseFloorNodes;
  std::vector<double> _dummy;

  gmsh::model::mesh::getNodesForPhysicalGroup(0, nodeFloorIPG, IFloorNodes,
                                              _dummy);
  gmsh::model::mesh::getNodesForPhysicalGroup(0, nodeFloorIIPG, IIFloorNodes,
                                              _dummy);
  gmsh::model::mesh::getNodesForPhysicalGroup(0, nodeFloorIIIPG, IIIFloorNodes,
                                              _dummy);
  gmsh::model::mesh::getNodesForPhysicalGroup(0, nodeFloorIVPG, IVFloorNodes,
                                              _dummy);
  gmsh::model::mesh::getNodesForPhysicalGroup(0, nodeFloorVPG, VFloorNodes,
                                              _dummy);
  gmsh::model::mesh::getNodesForPhysicalGroup(0, nodeFloorVIPG, VIFloorNodes,
                                              _dummy);
  gmsh::model::mesh::getNodesForPhysicalGroup(0, nodeFloorVIIPG, VIIFloorNodes,
                                              _dummy);
  gmsh::model::mesh::getNodesForPhysicalGroup(0, nodeBasePG, baseFloorNodes,
                                              _dummy);

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
  size_t masterTag1 = 10001;
  size_t masterTag2 = 10002;
  size_t masterTag3 = 10003;
  size_t masterTag4 = 10004;
  size_t masterTag5 = 10005;
  size_t masterTag6 = 10006;
  size_t masterTag7 = 10007;

  std::vector<double> masterCoordsI = {0.0, h1, 0.0};
  std::vector<double> masterCoordsII = {0.0, h2, 0.0};
  std::vector<double> masterCoordsIII = {0.0, h3, 0.0};
  std::vector<double> masterCoordsIV = {0.0, h4, 0.0};
  std::vector<double> masterCoordsV = {0.0, h5, 0.0};
  std::vector<double> masterCoordsVI = {0.0, h6, 0.0};
  std::vector<double> masterCoordsVII = {0.0, h7, 0.0};

  nodeWriter.addNode(masterTag1, masterCoordsI);
  nodeWriter.addNode(masterTag2, masterCoordsII);
  nodeWriter.addNode(masterTag3, masterCoordsIII);
  nodeWriter.addNode(masterTag4, masterCoordsIV);
  nodeWriter.addNode(masterTag5, masterCoordsV);
  nodeWriter.addNode(masterTag6, masterCoordsVI);
  nodeWriter.addNode(masterTag7, masterCoordsVII);

  bcWriter.addFix(masterTag1, {0, 1, 0, 1, 0, 1});
  bcWriter.addFix(masterTag2, {0, 1, 0, 1, 0, 1});
  bcWriter.addFix(masterTag3, {0, 1, 0, 1, 0, 1});
  bcWriter.addFix(masterTag4, {0, 1, 0, 1, 0, 1});
  bcWriter.addFix(masterTag5, {0, 1, 0, 1, 0, 1});
  bcWriter.addFix(masterTag6, {0, 1, 0, 1, 0, 1});
  bcWriter.addFix(masterTag7, {0, 1, 0, 1, 0, 1});

  // ---- Set RigidDiaphram
  size_t dir = 2;

  bcWriter.addRigidDiaphram(dir, masterTag1, IFloorNodes);
  bcWriter.addRigidDiaphram(dir, masterTag2, IIFloorNodes);
  bcWriter.addRigidDiaphram(dir, masterTag3, IIIFloorNodes);
  bcWriter.addRigidDiaphram(dir, masterTag4, IVFloorNodes);
  bcWriter.addRigidDiaphram(dir, masterTag5, VFloorNodes);
  bcWriter.addRigidDiaphram(dir, masterTag6, VIFloorNodes);
  bcWriter.addRigidDiaphram(dir, masterTag7, VIIFloorNodes);

  // ---- Fix Base Nodes

  bcWriter.addFix(baseFloorNodes, {1, 1, 1, 1, 1, 1});

  // ---- Define Elastic Section
  // material properties
  double E = 210000.;
  double nu = 0.3;
  double G = E / (2. * (1. + nu));
  double J = 1.00e10;

  // column section: W27x114
  double AgCol, IzCol, IyCol;
  AgCol = 216.00e2;
  IzCol = 170000.00e4;
  IyCol = 6620.00e4;
  // beam section: W24x94
  double AgBeam, IzBeam, IyBeam;
  AgBeam = 171.71e2;
  IzBeam = 112382.48e4;
  IyBeam = 4536.92e4;
  // girder section: W24x94
  double AgGirder, IzGirder, IyGirder;
  AgGirder = 171.71e2;
  IzGirder = 112382.48e4;
  IyGirder = 4536.92e4;

  // tags
  size_t colSecTag = 1;
  size_t beamSecTag = 2;
  size_t girderSecTag = 3;

  sectionWriter.addElasticSection(colSecTag, E, AgCol, IzCol, IyCol, G, J);
  sectionWriter.addElasticSection(beamSecTag, E, AgBeam, IzBeam, IyBeam, G, J);
  sectionWriter.addElasticSection(girderSecTag, E, AgGirder, IzGirder, IyGirder,
                                  G, J);

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

  // Compute gravity loads

  double Qdlcol, Qlbeam, Qlgir;

  Qdlcol = 169.3 * 0.00981;
  Qlbeam = 140.3 * 0.00981;
  Qlgir = 140.3 * 0.00981;

  double gammaConc = 2.45e-6;  // gamma concrete
  double Tslab = 50.00;        // slab thickness
  double Lslab = lgird * 0.5;  // slab len

  double Qlslab = gammaConc * Tslab * Lslab;
  double Qdlbeam = (Qlbeam + Qlslab);  // dead load distributed beam
  double Qdlgir = Qlgir;               // dead load girders

  double WeightCol = Qdlcol * hcol;     // total Column weight
  double WeightBeam = Qdlbeam * lbeam;  // total Beam weight
  double WeightGird = Qdlgir * lgird;   // total Beam weight

  int numCol = 12;
  double gravity = 9810.;

  double MassFloor = (WeightCol + WeightBeam + WeightGird) / (numCol * gravity);
  double MassTop =
      ((WeightCol * 0.5 + WeightBeam + WeightGird) / (numCol * gravity));

  // Add masses

  nodeWriter.addMass(IFloorNodes, {MassFloor, 0., MassFloor, 0., 0., 0.});
  nodeWriter.addMass(IIFloorNodes, {MassFloor, 0., MassFloor, 0., 0., 0.});
  nodeWriter.addMass(IIIFloorNodes, {MassFloor, 0., MassFloor, 0., 0., 0.});
  nodeWriter.addMass(IVFloorNodes, {MassFloor, 0., MassFloor, 0., 0., 0.});
  nodeWriter.addMass(VFloorNodes, {MassFloor, 0., MassFloor, 0., 0., 0.});
  nodeWriter.addMass(VIFloorNodes, {MassFloor, 0., MassFloor, 0., 0., 0.});

  nodeWriter.addMass(VIIFloorNodes, {MassTop, 0., MassTop, 0., 0., 0.});

  // Define a Linear TimeSeries
  size_t timeSeriesTag = 101;
  timeSeriesWriter.addLinearTimeSeries(timeSeriesTag);

  // Define Element Load Patterns
  size_t colLoadPat = 201;
  size_t beamLoadPat = 202;
  size_t girdLoadPat = 203;

  std::vector<double> colLoad = {0., 0., -Qdlcol};
  std::vector<double> beamLoad = {-Qlbeam, 0., 0.};
  std::vector<double> girdLoad = {-Qlgir, 0., 0.};

  loadPatternWriter.addPlainPatternElementLoad(colLoadPat, timeSeriesTag,
                                               elemTagsCol, colLoad);

  loadPatternWriter.addPlainPatternElementLoad(beamLoadPat, timeSeriesTag,
                                               elemTagsBeam, beamLoad);

  loadPatternWriter.addPlainPatternElementLoad(girdLoadPat, timeSeriesTag,
                                               elemTagsGir, girdLoad);

  // Define the recorders
  std::string fileNamePVD = "/home/master/TCLgenerator/out/recorder.pvd";
  std::vector<std::string> recorder = {"disp", "eigen", "5"};

  RecorderWriter recordWriter(cfg);
  recordWriter.addPVDRecorder(fileNamePVD, recorder);

  // Modal Analysis
  size_t mode = 5;
  analysisWriter.addModalAnalysis(mode);
  analysisWriter.wipeAnalysis();

  // Define the Analysis
  // Gravity
  analysisWriter.addConstraints("Penalty", 1.00e10, 1.00e10);
  analysisWriter.addNumberer("RCM");
  analysisWriter.addSystem("UmfPack");
  analysisWriter.addTest("NormDispIncr", 1.00e-3, 100);
  analysisWriter.addAlgorithm("Newton");

  size_t NstepGravity = 10;
  double DGravity = 1. / NstepGravity;

  analysisWriter.addLoadControl(DGravity);
  analysisWriter.addAnalysis("Static");
  analysisWriter.addStaticAnalysis(10);

  // analysisWriter.loadConst();

  return 0;
}