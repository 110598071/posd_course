#ifndef CIRCLE_H
#define CIRCLE_H

#include <cmath>
#include "shape.h"
#include "./iterator.h"
#include "./null_iterator.h"

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

    private:
        double _radius;
};

#endif