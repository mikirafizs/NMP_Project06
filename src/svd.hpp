#pragma once

#include <iostream>
#include <cmath>
#include <numbers>
#include <vector>


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

