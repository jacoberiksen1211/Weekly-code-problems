#include <iostream>
#include <string>
#include <math.h>

using namespace std;

double pi(int n)
{

    int divident = 1;
    double total = 0;
    for(int x = 0; x < n; x++){
        
        total += pow(-1, x) / divident ;
        
        divident += 2;
    }
    return total * 4;
}


int main(int argc, char const *argv[])
{
    int x;
    cin >> x;
    cout << pi(x);

    return 0;
}
