
// Header file shapes
#ifndef SHAPES_H
#define SHAPES_H

class Shape
{
private:
public:
    
    virtual double area() = 0;
    virtual double perimeter() = 0;
    virtual double height() = 0;
    virtual double width() = 0;
    virtual void rotate() = 0;
};


class Rectangle : public Shape
{
private:
    /* data */
 
public:
    double y;
    double x;
    Rectangle(double, double);
    double area();
    double perimeter();
    double height();
    double width();
    void rotate();
    ~Rectangle();
};

class Square : public Rectangle // square is a rectangle tbh
{
private:
    /* data */
public:
    Square(double);
    ~Square();
};






class Circle : public Shape
{
private:
    int radius;
public:
    double area();
    double perimeter();
    double height();
    double width();
    void rotate();
    Circle(double);
    ~Circle();
};

#endif