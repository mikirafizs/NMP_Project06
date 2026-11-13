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
    matrix_to_file(A, "original_a", m, n, n);

    std::vector <double> s(n);
    std::vector <double> u(m*n);
    std::vector <double> vt(n*n);
    std::vector <double> superb(n);

    LAPACKE_dgesvd(LAPACK_ROW_MAJOR, 'S', 'S', m, n, A.data(), n, s.data(), u.data(), n, vt.data(), n, superb.data()); 
    matrix_to_file(A, "svd_solution", m, n, n);

    std::vector <double> A_reconstructed = A_reconstruction(s, u, vt, m, n);
    matrix_to_file(A, "reconstructed_a", m, n, n);


    return 0;
}