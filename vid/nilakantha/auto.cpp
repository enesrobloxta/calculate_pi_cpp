#include <iostream>
#include <limits.h>
#include <fstream>
//ostream for write to file 
//istream to read from file
#include <cmath>
#include <gmpxx.h>
#include "timer.hpp"
/*
this version is preetty good but after a point 
3141592653589793238462643383279192076931341719.82644346417277088
it s practicly imposiible to calculate pi at least for me 
its about 12-14 minute for a digits change
and the digit change like this
loop1 314151
loop2 3141515
loop3 314152
...
but thericly we can calculate pi with this code its just too slow
:cringe: but ı am not gonna delete this line

*/

//make ramujans formula 

using namespace std;

typedef numeric_limits< double > dbl;

int wall= 1000000;
mpf_class x(1000000000,1024);// max 19 zero 

mpf_class power(mpf_class a,mpf_class b){
    mpf_class ans = 1;
    while(b--){ // how tf this loop works? 
    /* its work as a for loop until b is false(equals to 0) loop it and on each loop do b-- */
        ans *= a;
    }
    return ans;
}

int main(){

    Timer timer;//Timer = timer kinda
    ofstream write;

    write.open("data.txt");

    mpf_class sum(3,1024);
    mpf_class sign(1,1024);
    mpf_class n(2,1024);   

    int j=20;

    while(1){// enter 20 plus what u want
 
    // ı dont think so :(

    // find a way to save sum use it to new loop 

    timer.start();

    for(int i=0;i<j;i++){
    
    for(long long  i=0;i< wall;i++){

        sum=sum+(sign*(4/((n)*(n+1)*(n+2))));

        sign=sign*(-1);

        n=n+2;//if ı can use something more long than mpf_class with n it will be useful
        }
    }

    cout.precision(dbl::max_digits10);
    write.precision(dbl::max_digits10);

    write << j << endl;
    cout << fixed << "n:"<<n<< endl;
    write << fixed <<"n:"<<n<< endl;
    cout << fixed << sum*power(x,5) << endl;
    write << fixed <<sum*power(x,5) << endl;
    cout << fixed <<"31415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679"<< endl;
    write << "31415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679" << endl << endl << "******" << endl << endl;

    j=j+20;

    timer.stop();
    write << "Time:"<< timer.duration() << endl << endl;
    
    }
    write.close();
}