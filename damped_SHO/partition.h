#ifndef PARTITION
#define PARTITION

#include<hamiltonian.h>

double partition(complex<double> A[n][n], complex<double> B[n][n], double& x, int i, double& f,double t)
{
    double  p=0, dx,dp;

    f = 0;
    x = 0;
    dx = 0.01, dp = 0.01;

    p = hamiltonian(A,B);
    x += exp(-i*p/(t*1.38E-23));
    f += -(1.38E-23)*t*log(x);

    return 0;
}

#endif