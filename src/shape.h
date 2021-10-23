#ifndef SHAPE_H
#define SHAPE_H

class Iterator;

class Shape {
    public:
        virtual double area() const {return 0.0;}
        virtual double perimeter() const {return 0.0;}
        virtual Iterator* createIterator() const = 0;
};

#endif