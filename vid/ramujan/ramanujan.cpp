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

mpf wall=1000000000;

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
};

int main(){

    ofstream write;

    cout.precision(dbl::max_exponent10);

    mpf C(0.25,1024);
    mpf pi(0,1024);
    mpf sum(0,1024);
    mpf x(0,1024);
    mpf y(0,1024);

    write.open("data.txt");

    for(mpf k(0.0,1024);k < 100000;k++){

        x=1*power(combin(2.0*k,k),2.0);// üstleri çarp
        write << fixed << "x:"<<x<< endl; 
        y=power(16.0,k)*(k+1.0);
        write << fixed <<"y:"<<y<< endl; 
        sum=x/y;
        write << fixed <<"sum:" << sum<< endl;
        pi+=sum;
        write << fixed <<"pi:" << pi<< endl;


    }

    pi=C*pi;// * 0.25
    pi=1.0/pi;
    
    cout << fixed << pi*power(wall,4) << endl;
    cout << fixed <<"31415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679"<< endl;

    write.close();
}