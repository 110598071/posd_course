#ifndef COMPOUND_SHAPE_H
#define COMPOUND_SHAPE_H

#include "shape.h"
#include "./iterator.h"
#include "./compound_iterator.h"

class CompoundShape: public Shape {
    public:
        CompoundShape(Shape* shapes[], int count): _count(count) {
            _shapes = new Shape*[_count];
            for (int i = 0; i < _count; i++){
                _shapes[i] = shapes[i]; //shallow copy
            }
        };

        double area() const override {
            double result = 0;
            for (int i = 0; i < _count; i++) {
                result += _shapes[i]->area();
            }
            return result;
        }

        Shape* selectFirstByArea(double min, double max) const {
            for (int i = 0; i < _count; i++) {
                if (min < _shapes[i]->area() && _shapes[i]->area() < max) {
                    return _shapes[i];
                }
            }
            return nullptr;
        }

        Iterator* createIterator() const override {
            return new CompoundIterator(_shapes, _shapes + _count);
        }

        Shape** shapes() const {
            return _shapes;
        }

        int count() const {
            return _count;
        }

        ~CompoundShape() {
            delete [] _shapes;
        }

    private:
        int _count;
        Shape** _shapes;
};

#endif