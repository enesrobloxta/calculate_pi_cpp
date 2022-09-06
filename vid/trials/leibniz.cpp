/*

in 1 repear is compatible until 265 + 4(must be 3 ) 
in 5 repeat is still 265 + 5(must be 3)
3 repeat same as 5  

this method is bad

*/
#include <iostream>
#include <limits>
#include <cmath>

using namespace std;

int imin = std::numeric_limits<int>::min(); // minimum value
int imax = std::numeric_limits<int>::max(); // maximum value (2147483647)

typedef numeric_limits< double > dbl;

long long x=1000000000;//max 19 digits

int main(){
    
    long double sum=0;
    long double sign=1;
    int j=0,a;

    cout << "How many repeats:" << endl;
    cin >> a;

    while(j < a){

    for(int i=0;i < imax;i++){
        
        if(i%2==0)
            sum+=4/sign;
        else
            sum-=4/sign;

        sign+=2;
  
    }
    j++;    
    }

    cout.precision(dbl::max_digits10);
    cout << fixed <<  sum * x<< endl;
    cout << "3.14159265358979323846264338327950288419716939937510" << endl;
}