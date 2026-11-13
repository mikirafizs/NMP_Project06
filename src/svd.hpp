#pragma once

#include <iostream>
#include <cmath>
#include <numbers>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>

const double x_a = 0;
const double x_b = 3*std::numbers::pi;

inline std::vector <double> x_v(std::size_t m){
    std::vector <double> x (m, 0.0);
    for(std::size_t i = 0; i < m; i++){
        x[i] = x_a + i*(x_b-x_a)/(m-1);
    }
    return x;
}

inline std::vector <double> y_v(const std::vector <double> &x, std::size_t m){
    std::vector <double> y (m, 0.0);
    for(std::size_t i = 0; i < m; i++){
        y[i] = x[i]*std::cos(x[i]);
    }
    return y;
}

inline std::vector <double> A_population(const std::vector <double> &x, std::size_t m, std::size_t n){
    std::vector <double> A(n*m, 0.0);
    std::size_t ldA = n;
    for(std::size_t j = 0; j < m; j++){
        for(std::size_t i = 0; i < n; i++){
            A[i+ldA*j] = std::pow(x[j], static_cast <double>(i));
        }
    }
    return A;
}

inline void matrix_to_file(std::vector <double> &A, std::string name_of_file, std::size_t m, std::size_t n, std::size_t ldA){
    std::ostringstream path;
    path << "../data/" << name_of_file <<".csv";
    std::ofstream pfile(path.str());
    if(!pfile.is_open()){
        std::cerr << "Cannot open file. \n";
    }

    for(std::size_t j = 0; j < m; j++){
        for(std::size_t i = 0; i < n; i++){
            pfile << A[i+ldA*j] << "\n";
        }
    }
    pfile.close();
}

inline std::vector <double> A_reconstruction(std::vector <double> &s, std::vector <double> &u, std::vector <double> vt, std::size_t m, std::size_t n){
    std::vector <double> reconstructed(m*n, 0.0);
    std::size_t ldA = n;

    for(std::size_t j = 0; j < m; j++){
        for(std::size_t i = 0; i < n; i++){
            for(std:: size_t k = 0; k < n; k++){
                reconstructed[i+ldA*j] += s[k] * u[ldA*j + k] * vt[k*ldA + i];
            }
        }
    }
    return reconstructed;
}

