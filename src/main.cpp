#include "svd.hpp"
#include <iostream>
#include <lapacke.h>

size_t m = 8;
size_t n = 6;

int main(){
    std::vector <double> x = x_v(m);
    std::vector <double> y = y_v(x, m);
    std::vector <double> A = A_population(x, m, n);

    std::vector <double> s(n);
    std::vector <double> u(m*n);
    std::vector <double> vt(n*n);
    std::vector <double> superb(n);


    LAPACKE_dgesvd(LAPACK_ROW_MAJOR, 'S', 'S', m, n, A.data(), n, s.data(), u.data(), n, vt.data(), n, superb.data());
    return 0;
}