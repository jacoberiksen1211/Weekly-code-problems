
// Header file shapes
#ifndef SHAPES_H
#define SHAPES_H

class Shape
{
private:
public:
    ~Shape();
    virtual double area();
    virtual double perimiter();
    virtual double height();
    virtual double width();
    virtual void rotate();
};


class Rectangle : public Shape
{
private:
    /* data */
 
public:
    double y;
    double x;
    Rectangle();
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