#include <iostream>
#include <limits>
#include <gmpxx.h>
#include <fstream>
#include <cmath>

typedef long long ll;
typedef long double ld;
typedef mpf_class mpf;

using namespace std;
typedef numeric_limits< double > dbl;

mpf wall=INT32_MAX;

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

mpf combin(mpf n,mpf r){
    if(n==r) return 1;
    if (r==0&&n!=0) return 1;
    else return (n*fact(n-1))/fact(n-1)*fact(n-r);
}
mpf mpfsqrt(mpf num) {
 
    mpf temp, sqrt;
    mpf number;
    number = num;
    sqrt = number / 2.0;
    temp = 0;
 
    // It will stop only when temp is the square of our number
    while(sqrt != temp){
 
        // setting sqrt as temp to save the value for modifications
        temp = sqrt;
 
        // main logic for square root of any number (Non Negative)
        sqrt = ( number/temp + temp) / 2;
    }
    return sqrt;

}

int main(){

    ofstream write;

    cout.precision(dbl::max_exponent10);

    mpf pi(0,1024);
    mpf C(1,1024);

    C=(2*sqrt(2))/power(99,2);

    mpf y(0,1024);
    mpf x(0,1024);
    mpf sum(0,1024);
    write.open("data.txt");

    for(mpf k(0.0,1024);k < 1000;k++){

        x=fact(4.0*k)*(26390.0*k+1103.0);
        write << fixed<<"x:" << x << endl;
        y=power(fact(k),4.0)*power(396.0,4.0*k);
        write <<fixed << "y:" << y << endl;
        sum+=x/y;
        write <<fixed << "sum:" << sum << endl;
    }

    pi=sum*C;//pi=1/pi
    pi=1.0/pi;

    cout << fixed << pi << endl;
    cout << fixed <<"31415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679"<< endl;

    write.close();
}