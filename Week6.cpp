#include <iostream>
#include <string>
#include <math.h>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

class Fraction {
    private:
        // Internal representation of a fraction as two integers
        int numerator;
        int denominator;
        void simplify(void){

        }
    public:
        // Class constructor
        Fraction(int n, int d){
            this->numerator = n;
            this->denominator = d;
        }
        // Methods to update the fraction
        void add(Fraction f){
            cout << "add called" << endl;

            //finding least common denominator
            int counterA = 1;
            int counterB = 1;
            while(true){
                if(counterA * this->denominator == counterB * f.denominator){
                    break;
                }
                else if(counterA * this->denominator < counterB * f.denominator){
                    counterA++;
                }
                else if(counterA * this->denominator > counterB * f.denominator){
                    counterB++;
                }
            }
            //adding
            this->numerator = this->numerator * counterA + counterB * f.numerator;
            this->denominator = this->denominator * counterA;

        }

        void mult(Fraction f){

        }
        void div(Fraction f){

        }
        // Display method
        void display(void){
            cout << this->numerator << " / " << this->denominator << endl;
        }
};

int main(int argc, char const *argv[])
{
    Fraction a(1, 6);
    Fraction b(1, 8);
    a.add(b);
    a.display();
    return 0;
}


