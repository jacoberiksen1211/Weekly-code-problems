#include "Shapes.h"
#define _USE_MATH_DEFINES
#include <math.h>


using namespace std;

//rectangle
Rectangle::Rectangle(){
    //huhuhu
};
Rectangle::Rectangle(double x, double y){
    this->x = x;
    this->y = y;
}
double Rectangle::height(){
    return this->y;
}
double Rectangle::width(){
    return this->x;
}
double Rectangle::area(){
    return this->x * this->y;
}
double Rectangle::perimeter(){
    return this->x * 2 + this->y * 2; 
}
void Rectangle::rotate(){
    double tempx = this->x;
    this->x = this->y;
    this->y = tempx; 
}


Square::Square(double x) : Rectangle(){
    this->x = x;
    this->y = y;
}

//Circle implementation
Circle::Circle(double r){
    this->radius = r;
}
void Circle::rotate(){
    //do nothing for this
}
double Circle::area(){
    return M_PI * this->radius * this->radius;
}

double Circle::height(){
    return this->radius;
}
double Circle::width(){
    return this->radius;
}
double Circle::perimeter(){
    return this->radius*2 * M_PI;
}
