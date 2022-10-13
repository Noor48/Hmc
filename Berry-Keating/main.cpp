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

double fact(double x)
{
    double s=1;
    for(int i=1; i<=x; i+=1)
    {
        s *= i*(i+1);
    }

    return s;
}

int main()
{
    srand(time(NULL));
    ofstream fout("main.dat");
    ofstream file("part.dat");
    double hi, hf, s=0, s2=0, r, c=0,p,q,C[10000]={},x=0,a=0;
    long double x1=0, x2, y1=0, y2=0;
    const int n=10;
    //x=0;
    complex<double> A[n][n] = {0}, A0[n][n] = {0},B[n][n] = {0},B0[n][n] = {0};

    //#pragma omp parallel for
    //for(int t=1; t<=10000; t+=100)
    //{   
        //generating random value for x
        for(int i=0; i<n; i+=1)
        {
            for(int j=0; j<n; j+=1)
            {   
                p=(double)rand()/(double)RAND_MAX;
                q=(double)rand()/(double)RAND_MAX;
                A[i][j]=complex(p,q);
            }
        }

       // #pragma omp parallel for
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
            s2 += hamiltonian(A,B);
            C[i] = s;
            fout << i << "  " << (double)s/(double)i << "  " << (double)s2/(double)(i) << endl;

            //x = exp(-s/(298*1.38E-23));
            //file << i << " "  << x << endl;
        }

        
        for(int i=1; i<10000; i+=1)
        {
            y1 += exp(-C[i]/298);

            //file << i << "  " << y1 << endl;
        }

        for(int i=1; i<10000; i+=1)
        {
            y2 = (298);
            x1 += C[i]*exp(-C[i]/298);

            file << i << "  " << x1/y1 << endl;
        }
   // }
    return 0;
}