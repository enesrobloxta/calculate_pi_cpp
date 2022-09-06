#include <iostream>
#include <limits>

using namespace std;

typedef numeric_limits< double > dbl;

long x= INT32_MAX;

int main(){
     double sum=3;
     double n=2;
     double sign=1;

    for(long i=0;i< x;i++){
        sum=sum+(sign*(4/((n)*(n+1)*(n+2))));
       
       sign=sign*(-1) ;
       
       n=n+2;
    }

    cout.precision(dbl::max_digits10);

    cout << fixed << sum<< endl;;
    cout << fixed <<"3.1415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679"<< endl;
}