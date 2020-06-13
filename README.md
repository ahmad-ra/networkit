
# Windows 10 native support for NetworKit .

this is an unofficial Development clone , and will be added to NetworKit original Dev branch when work is done, the original NetworKit repo : https://github.com/networkit/networkit

## Motivation
adding native windows support for NetworKit without the need for a virtual machine or WSL which may produce additional hassle

## 
NetworKit is an open-source tool suite for high-performance
network analysis. Its aim is to provide tools for the analysis of large
networks in the size range from thousands to billions of edges. For this
purpose, it implements efficient graph algorithms, many of them parallel to
utilize multicore architectures. These are meant to compute standard measures
of network analysis. NetworKit is focused on scalability and comprehensiveness.
NetworKit is also a testbed for algorithm engineering and
contains novel algorithms from recently published research (see list of publications below).

NetworKit is a Python module. High-performance algorithms are written in C++ and exposed to Python
via the Cython toolchain. Python in turn gives us the ability to work interactively and a
rich environment of tools for data analysis and scientific computing.
Furthermore, NetworKit's core can be built and used as a native library if needed.

## Requirements

additional to the original requirements :

- Install cmake 64 bit installer (Networkit supports only x64 bit builds)
https://github.com/Kitware/CMake/releases/download/v3.18.0-rc1/cmake-3.18.0-rc1-win32-x86.msi

- Install mingw-w64 : http://mingw-w64.org/doku.php/download/mingw-builds

follow the steps here, BUT check the POSIX thread option not win32 ** : https://www.eclipse.org/4diac/documentation/html/installation/minGW.html (only installation section)

- Build system: MSBuild

 Must have visual studio tool chain installed , and have an environment variable for msbuild 
 

## Install

    git clone https://github.com/ahmad-ra/networkit
    
    py setup.py build_ext 
    
   OR (depending on your environment)
    
    python3 setup.py build_ext
         
    pip3 install -e .

- no modification nor test was done to `ninja`


## notes
- If you want to build with make instead of MSBuild , you can rename "mingw32-make.exe" to "make.exe" in mingw-w64 installation path (make.exe is same for 32 and 64 bit builds)  , then you have to manually edit setup.py ,to set cmake to produce makefile rather than .sln

- This is not a stable version yet , and still contains build errors , and is still under active development



