#include <iostream>
#include <cmath>
#include <limits>

using namespace std;

typedef numeric_limits< double > dbl;

int main(){
    long double pi = 2* acos(0.0);
    long double pi2 = 2*asin(1.0);

    cout.precision(dbl::max_digits10);
    cout << fixed <<"acos:" << pi*100000 << endl;
    cout << fixed <<"acos:" << pi*100000 << endl;
    cout << fixed <<"atan:" << atan(1)*400000<< endl;
    cout << "3.14159265358979323846264338327950288419716939937510" << endl;

}
// zortttt