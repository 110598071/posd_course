#ifndef SQUARE_H
#define SQUARE_H

#include "shape.h"
#include "./iterator.h"

class Square: public Shape {
    public:
        Square(double sideLength): _sideLength(sideLength){}
        double sideLength() const {
            return _sideLength;
        }
        double area() const override {
            return _sideLength*_sideLength;
        }
        double perimeter() const override {
            return _sideLength*4;
        }
        Iterator* createIterator() const override {
            throw std::string("method not allowed");
        }
    private:
        double _sideLength;
};

#endif