#ifndef UTILS_H
#define UTILS_H

#include <filesystem>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>
#include <string>
#include <vector>

#include "gmsh.h"

#ifdef _WIN32
#include <direct.h>  // per _mkdir su Windows

#include <cstdlib>  // per _getcwd su Window
#else
#include <sys/stat.h>  // per mkdir su Linux/Unix/Mac
#include <unistd.h>    // per getcwd su Linux/Unix/Mac
#endif

void checkAndCreateDirectory(const std::string &dirPath);

void reshapeNodeCoords(const std::vector<double> &nodeCoords,
                       std::vector<std::vector<double>> &reshapedCoords);

void reshapeNodeTags(const std::vector<std::vector<std::size_t>> &nodeTags,
                     std::vector<std::vector<std::size_t>> &reshapedTags,
                     std::size_t nodes);

void sortNodeTagsByCoordinate(std::vector<std::size_t> &nodeTags,
                              char direction);

void sortNodeTagsAndCoordinatesByDirection(
    std::vector<std::size_t> &nodeTags,
    std::vector<std::vector<double>> &coordinates, char direction);

void getLineElementInfo(const std::vector<int> list,
                        std::vector<std::size_t> &elemTags,
                        std::vector<std::vector<size_t>> &elemNodeTags);

// get the current path function
std::string getCurrentDirectory();

#endif