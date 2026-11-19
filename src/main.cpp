#include "svd.hpp"
#include <iostream>
#include <lapacke.h>
#include <fstream>

size_t m = 8;
size_t n = 6;

int main(){
    std::vector <double> x = x_v(m);
    std::vector <double> y = y_v(x, m);
    std::vector <double> A = A_population(x, m, n);
    std::vector <double> A_original = A;
    matrix_to_file(A_original, "original_a86", m, n, n);

    std::vector <double> s(n);
    std::vector <double> u(m*n);
    std::vector <double> vt(n*n);
    std::vector <double> superb(n);

    if(!LAPACKE_dgesvd(LAPACK_ROW_MAJOR, 'S', 'S', m, n, A.data(), n, s.data(), u.data(), n, vt.data(), n, superb.data())){
        std::cout << "SVD performed succesfully \n";
    }
    vector_to_file(s, "svd_solution86");

    std::vector <double> A_reconstructed = A_reconstruction(s, u, vt, m, n);
    matrix_to_file(A_reconstructed, "reconstructed_a86", m, n, n);

    std::vector <double> c = coefficients(s, u, vt, y, m, n);
    vector_to_file(c, "coefficients86");
    return 0;
}