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
#include<random>
using namespace std;

int main()
{
    srand(time(NULL));
    ofstream fout("main.dat");
    ofstream file("part.dat");
    random_device rd;
    mt19937 mt(rd());
    uniform_real_distribution<double> r1(0, 1); 
    double hi, hf, s=0, s2=0, r, c=0,p,q,C[10000]={},x=0,a=0, D[10000][10]={};
    long double x1=0, x2=0, y1=0, y2=0;
    const int n=100;
    //x=0;
    complex<double> A[n][n] = {0}, A0[n][n] = {0},B[n][n] = {0},B0[n][n] = {0};

    //generating random value for x
    for(int i=0; i<n; i+=1)
    {
        for(int j=0; j<n; j+=1)
        {   
            p=r1(mt);
            q=r1(mt);
            A[i][j]=complex(p,q);
        }
    }

    #pragma omp parallel for
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
        r = r1(mt);
        a = hf-hi;
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
        C[i] = s2;
        //fout << i << "  " << (double)s/(double)i << "  " << (double)s2/(double)(i) << endl;
    }
    double t = 298;
    for(int l=0; l<10; l+=1)
    {   
        cout << t << endl;
        //calculating partition function
        y1=0, x1=0;
        for(int i=1; i<10000; i+=1)
        {
            y1 += exp(-C[i]/t);
        }

        // sum of <H>*exp(-\beta H)/Z 
        for(int i=1; i<10000; i+=1)
        {
            x1 += C[i]*exp(-C[i]/t);
            D[i][l] = x1/y1;
        }

        t*=10;
    }

    //output of file
    for(int i=1; i<10000; i+=1)
    {   
        file << i << " ";
        for(int l=0; l<10; l+=1)
        {
            file << "  " << D[i][l] << " "; 
        }

        fout << i << "  " << C[i]/i << endl;
        file << endl;
    }
    return 0;
}