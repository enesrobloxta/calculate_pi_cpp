#include <iostream>
#include <gmpxx.h>
#include <fstream>
#include <cmath>

typedef long long ll;
typedef long double ld;
typedef mpf_class mpf;
typedef mpq_class mpq;
typedef mpz_class mpz;

using namespace std;
typedef numeric_limits< double > dbl;

mpf wall=INT32_MAX;

void ull2mpz(mpz_t z, unsigned long long ull)
{
    mpz_import(z, 1, -1, sizeof ull, 0, 0, &ull);
}

mpf fact(mpf i){
	if (i <= 1) return 1;
  	else return i*fact(i-1);
}

mpf power(mpf base,mpf top){
    mpf tmp=1;
    while(top--){
        tmp*=base;
    }
    return tmp;
}

mpf mpfsqrt(mpf num) {
 
    mpf temp, sqrt;
    mpf number;
    number = num;
    sqrt = number / 2.0;
    temp = 0;
 
    while(sqrt != temp){

        temp = sqrt;

        sqrt = ( number/temp + temp) / 2;
    }
    return sqrt;

}

int main(){

    ofstream write;
    write.open("data.txt");
    cout.precision(1000);
    write.precision(1000);

    mpf_t QA;
    mpz_t QZ;

    mpz_init2(QZ,1024);
    mpf_init2(QA,1024);
    ull2mpz(QZ,262537412640768000);
    mpf_set_z(QA,QZ);

    mpf X(1,1024),C(0,1024),M(1,1024),L(13591409,1024),K(-6,1024),SUM(0,2048),PI(0,2048);

    mpf A(power(640320,3),1024);
    A=-A;
    cout << A << endl;

    C=426880*sqrt(10005);
    write << "C:" << C << endl;
    for(mpf k(0,1024);k<10000;k++){

        if(k!=0)    
            K+=12;
        write << "K:" << K << endl;
        if(k!=0)
            M=(power(K,3)*(-16*K))/power(k+1,3);
        write << "M:" <<M << endl;
        if(k!=0)
            L=545140134*k+13591409;
        write << "L:" <<L << endl;
        if(k!=0)    
            X=power(A,k);
        write << "X:" <<X << endl;

        SUM+=(M*L)/X;

        write << "SUM:" <<SUM << endl;
        write << k << endl;

    }

    SUM=1/SUM;
    PI=C*SUM;
    
    cout << fixed <<PI<< endl;
    cout << fixed << "3.1415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679"<< endl;
    write << fixed <<  PI << endl;
    write << fixed << "3.1415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679"<< endl;

    write.close();
}
