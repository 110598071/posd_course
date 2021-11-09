#ifndef SHAPE_H
#define SHAPE_H

class Iterator;
class ShapeVisitor;

class Shape {
    public:
        virtual double area() const {return 0.0;}
        virtual double perimeter() const {return 0.0;}
        virtual Iterator* createIterator() const = 0;
        virtual void accept(ShapeVisitor* visitor) = 0;
};

#endif