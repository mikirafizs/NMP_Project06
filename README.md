# Fitting tabulated data using singular values decomposition (SVD)

This project fits a polynomial to tabulated data of the function y(x) = x·cos(x) on the interval [0, 3π]. The overdetermined system of linear equations with a Vandermonde matrix is solved in the least-squares sense using the singular value decomposition (SVD) computed with LAPACKE. The influence of the number of data points and the polynomial degree on the quality of the fit is examined for (m, n) = (8, 6), (30, 10) and (30, 20).

**Author:** Michal Sikora
**Subject:** Numerical Methods in Physics
**Major and Faculty:** Computer Physics, Faculty of Physics and Applied Computer Science, AGH

## Structure of the project:
- 'src/' - source code (main.cpp, svd.hpp)
- 'data/' - solutions of the project
- 'plots/' - graphs and script for plotting the data (PNG, PDF)
- 'report/' - report of a project (PDF)

## Requirements:
- g++ with C++20 support (tested with GCC 15)
- LAPACK (header `lapacke.h`, linked with `-llapacke`);
- Ubuntu/Debian: `sudo apt install liblapack-dev`
- Python 3.8+ (tested with 3.14)
- matplotlib: `sudo apt install python3-matplotlib` or `pip install matplotlib`
- numpy: `sudo apt install python3-numpy` or `pip install numpy`

## System
- OS: Ubuntu 26.04.1 LTS, Linux 7.0.0-38-generic (aarch64)
- Virtualization: QEMU virtual machine
- CPU: 4 cores, 1 thread per core, 64-bit ARM (aarch64), vendor ID reported as Apple
- RAM: 3.3 GiB (plus 3.8 GiB swap)
- Compiler: g++ (Ubuntu 15.2.0-16ubuntu1) 15.2.0
- Python: <3.14.4>
- matplotlib: <3.10.7+dfsg1>
- BLAS: OpenBLAS <0.3.32+ds-5>
- LAPACK: liblapack3 <3.12.1>

## Build and run

From the `src/` directory:

    g++ -std=c++20 -O2 -Wall -Wextra main.cpp -o main -llapacke


The program writes the norm files to `../data/`, so run it from `src/`
and make sure the `data/` directory exists.

## Plots

From the project root:

    python3 plots/plots.py