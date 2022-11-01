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
            int temp = 0;
            if(this->numerator > this->denominator){
                temp = this->denominator;
            }
            else{
                temp = this->numerator;
            }
            while(temp > 1 && ( this->numerator % temp != 0 || this->denominator % temp != 0 )){
                temp--;
            }
            this->numerator = this->numerator / temp;
            this->denominator = this->denominator / temp;
        }
    public:
        // Class constructor
        Fraction(int n, int d){
            this->numerator = n;
            this->denominator = d;
        }
        // Methods to update the fraction
        void add(Fraction f){

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

            simplify();
        }

        void mult(Fraction f){
            this->numerator = this->numerator * f.numerator;
            this->denominator = this->denominator * f.denominator;
            simplify();
        }
        void div(Fraction f){
            this->numerator = this->numerator * f.denominator;
            this->denominator = this->denominator * f.numerator;
            simplify();
        }
        // Display method
        void display(void){
            cout << this->numerator << " / " << this->denominator << endl;
        }
};

int main(int argc, char const *argv[])
{
    int n1, d1, n2, d2;
    char slash = ' ';
    string op = "";
    while(true){
        //while there is more input
        cin >> n1;
        if(cin.fail()) break;
        cin >> slash;
        if(cin.fail()) break;
        cin >> d1;
        if(cin.fail()) break;
        cin >> op;
        if(cin.fail()) break;
        cin >> n2;
        if(cin.fail()) break;
        cin >> slash;
        if(cin.fail()) break;
        cin >> d2;
        if(cin.fail()) break;
        
        Fraction a(n1, d1);
        Fraction b(n2, d2);
        
        if(op.compare("*") == 0){
            a.mult(b);
            a.display();
        }
        else if(op.compare("div") == 0){
            a.div(b);
            a.display();
        }
        else if(op.compare("+") == 0){
            a.add(b);
            a.display();
        }
       

    }
    return 0;
}


