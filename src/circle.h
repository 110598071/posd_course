#ifndef CIRCLE_H
#define CIRCLE_H

#include <cmath>
#include "shape.h"
#include "./iterator.h"
#include "./null_iterator.h"
#include "./shape_visitor.h"

class Circle: public Shape {
    public:
        Circle(double radius): _radius(radius){}

        double area() const override {
            return pow(_radius, 2) * M_PI;
        } 

        double perimeter() const override {
            return 2*M_PI*_radius;
        }

        Iterator* createIterator() const override {
            return new NullIterator();
        }

        void accept(ShapeVisitor* visitor) override {
            visitor->visitCircle(this);
        }

    private:
        double _radius;
};

#endif