#include <iostream>
#include <limits>

using namespace std;

typedef numeric_limits< double > dbl;

int wall= INT32_MAX;
long long x=10000000000;// max 19 zero 

int main(){

    long double sum=3;
    long double n=2;
    long double sign=1;
    int j;
    cout << "How many repats"<< endl;
    cin >> j;

    for(int i=0;i<j;i++){
    
    for(long long  i=0;i< wall;i++){
        sum=sum+(sign*(4/((n)*(n+1)*(n+2))));
       
       sign=sign*(-1) ;
       
       n=n+2;
    }
    }

    cout.precision(dbl::max_digits10);

    cout << fixed << sum << endl;
    cout << fixed << sum*x << endl;
    cout << fixed <<"3.1415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679"<< endl;
}