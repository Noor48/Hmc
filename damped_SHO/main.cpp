#include<box.h>
#include<force.h>
#include<molecular.h>
#include<matrix.h>
#include<partition.h>
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
    ofstream file("part.dat");
    double hi, hf, s=0, s2=0, r, c=0,p=0,q=0,x=0,f,t=0,z=0,H=0, sum=0, sum2=0,C[10000]= {0};
    const int n=10;
    //x=0;
    complex<double> A[n][n] = {0}, A0[n][n] = {0},B[n][n] = {0}, B0[n][n] = {0};


    //generating random value for x
    for(int i=0; i<n; i+=1)
    {
        for(int j=0; j<n; j+=1)
        {   
            p=(double)rand()/(double)RAND_MAX;
            q=(double)rand()/(double)RAND_MAX;
            A[i][j] = complex(p,q);
        }
    }

    //metropolis test
    //# pragma omp parallel for
    for(int i=1; i<10000; i+=1)
    {   
        t +=1;
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

        s2 += hamiltonian(A,B);
        //file << i << "  " << x << "  " << f << endl;

        C[i] = s;
        fout << i << "  " << (double)s/(double)i << "  " << (double)s2/(double)i << endl;
        x += exp(-s/(298*1.38E-23));
        p += s*exp(-s/(298*1.38E-23));
        file << i << "  " << p/x << endl;
    }

    return 0;
}