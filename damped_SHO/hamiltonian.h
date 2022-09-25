#ifndef HAM
#define HAM

/* 
    Calculating Hamiltonian
*/
double hamiltonian(complex<double> A[n][n], complex<double> B[n][n])
{
    complex <double> H[n][n] = {0}, A2[n][n] = {}, A3[n][n] = {}, A4[n][n] = {}, B2[n][n] = {}, B3[n][n] = {}, B4[n][n] = {};
    double sum=0, p2=0, p=0, x=0, a=0, a2=0, a3=0, a4=0, b=0, b2=0, b3=0, b4=0, m=1, omega=1;

    matrix(A,A2,A3,A4,a,a2,a3,a4);
    matrix(B,B2,B3,B4,b,b2,b3,b4);

    sum = b2/(2*m) + (1/2)*m*omega*a2 - 5/m;

    return sum;

}
#endif
