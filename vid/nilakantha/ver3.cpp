//#include<bits/stdc++.h> 
#include <iostream>
#include <limits.h>
#include <fstream>
//ostream for write to file 
//istream to read from file
#include <gmpxx.h>

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

    ofstream write;

    write.open("data.txt");

    mpf_class sum(3,1024);
    mpf_class sign(1,1024);
    mpf_class n(2,1024);   

    int j;
    cout << "How many repats"<< endl;
    cin >> j;

    for(int i=0;i<j;i++){
    
    for(long long  i=0;i< wall;i++){

        sum=sum+(sign*(4/((n)*(n+1)*(n+2))));

        sign=sign*(-1);

        n=n+2;
        }   
        
    }

    cout.precision(dbl::max_digits10);
    write.precision(dbl::max_digits10);

    cout << fixed << sum << endl;   
    write << fixed << sum << endl;
    cout << fixed << sum*power(x,5) << endl;
    write << fixed <<sum*power(x,5) << endl;
    cout << fixed <<"31415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679"<< endl;
    write << "31415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679" << endl << endl << "******" << endl << endl;

    write.close();
}