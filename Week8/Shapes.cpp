#include "shapes.h"
#define _USE_MATH_DEFINES
#include <math.h>


using namespace std;

//rectangle
Rectangle::Rectangle(double height, double width){
    this->x = width;
    this->y = height;
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

Rectangle::~Rectangle(){

}


Square::Square(double x) : Rectangle(x, x){
    
}

Square::~Square(){

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
    return this->radius*2;
}
double Circle::width(){
    return this->radius*2;
}
double Circle::perimeter(){
    return this->radius*2 * M_PI;
}
Circle::~Circle(){

}
