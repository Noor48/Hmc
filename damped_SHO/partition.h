#ifndef PARTITION
#define PARTITION

#include<hamiltonian.h>

double partition(comlex<double> A[n][n], complex<double> B[n][n])
{
    ofstream fout("part.dat");
    double x=0, p=0, dx,dp;

    for(int i=0; i<10000; i+=1)
    {
        dx = 0.01, dp 0.01;
        for(int j=0; j<n; j+=1)
        {
            for(int k=0; k<n; k+=1)
            {
                A[i][j] += dx;
            }
        }

        for(int j=0; j<n; j+=1)
        {
            for(int k=0; k<n; k+=1)
            {
                B[i][j] += dx;
            }
        }
        
        p = hamiltonian(A,B);
        x += exp(-p/(298*1.38E-23));

        fout << i << "  " << x << endl;
    }

    return 0;
}

#endif