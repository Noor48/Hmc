#include<box.h>
#include<force.h>
#include<molecular.h>
#include<matrix.h>
#include<iostream>
#include<cmath>
#include<fstream>
#include<cstdlib>
#include<complex>
#include<ctime>
using namespace std;

int main()
{
    srand(time(NULL));
    ofstream fout("main.dat");
    double hi, hf, s=0, s2=0, r, c=0,p,q;
    const int n=10;
    //x=0;
    complex<double> A[n][n] = {0}, A0[n][n] = {0},B[n][n] = {0};


    //generating random value for x
    for(int i=0; i<n; i+=1)
    {
        for(int j=0; j<n; j+=1)
        {   
            Box(p,q);
            A[i][j] = complex(p/sqrt(2),q/sqrt(2));
        }
    }

    //generating random value for p
    for(int i=0; i<n; i+=1)
    {
        for(int j=0; j<n; j+=1)
        {   
            Box(p,q);
            B[i][j] = complex(p/sqrt(2),q/sqrt(2));
        }
    }

    //metropolis test
    for(int i=1; i<10000; i+=1)
    {
        for(int j=0; j<n; j+=1)
        {
            for(int k=0; k<n; k+=1)
            {   
                //x0=x
                A0[j][k] = A[j][k];
            }
        }
        
        molecular(A,B,hi,hf);
        r = (double)rand()/(double)RAND_MAX;
        if(exp(hi-hf)>r)
        {
            c+=1;
        }

        else
        {
            for(int j=0; j<n; j+=1)
            {
                for(int k=0; k<n; k+=1)
                {
                    A[j][k] = A0[j][k];
                }
            }
        }

        s = hamiltonian(A,B);
        fout << i << "  " << (double)s/(double)(i*n*n) << endl;
    }

    return 0;
}