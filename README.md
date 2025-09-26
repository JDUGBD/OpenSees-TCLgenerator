# OpenSees-TCLgenerator  

[![Status](https://img.shields.io/badge/status-under%20development-orange)]()  
[![Made with C++](https://img.shields.io/badge/made%20with-C++17-blue)]()  
[![License: MIT](https://img.shields.io/badge/License-MIT-green.svg)](LICENSE)  

A **C++ tool** to automatically generate **TCL input files** for [OpenSees](https://opensees.berkeley.edu/).  
The project is designed to **simplify the workflow** of structural modeling and is fully compatible with **ParaView** and **Gmsh**.  

---

## 🚀 Features
- **Immediate syntax** for OpenSees users:
  - Use `add...` methods to define nodes, elements, loads, boundary conditions, etc.  
  - Use `addAdditional...` methods to extend a model after the first analysis (e.g., add new load patterns or recorders).
- Automatic generation of TCL files ready to run in OpenSees.
- Support for **3D frames** (nodes, beam-column elements, rigid diaphragms, etc.).
- Fiber section definition for steel wide-flange (W) sections.
- Output organized in folders (e.g. `output/recorder.pvd`) for direct visualization in **ParaView**.
- Easy integration with **pre-processors** like [Gmsh](https://gmsh.info) and **post-processors** like [ParaView](https://www.paraview.org).

---

## 📂 Project structure
OpenSees-TCLgenerator/
│── include/ # Header files
│── src/ # Source files
│── examples/ # Example C++ files to generate TCL models
│── output/ # Generated TCL and recorder files
│── CMakeLists.txt # Build configuration
│── README.md # Project documentation



👉 **Check the `examples/` folder for usage.**  
It contains sample C++ files showing how to define models and generate TCL scripts.  
This folder will be **expanded over time** to cover more cases and workflows.  

---

## ⚙️ Build instructions
Make sure you have **CMake** and a C++17 compiler installed.

```bash
# Clone the repository
git clone https://github.com/JDUGBD/OpenSees-TCLgenerator.git
cd OpenSees-TCLgenerator

# Create a build directory
mkdir build && cd build

# Configure and build
cmake ..
make

