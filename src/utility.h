#pragma once

#include "./compound_shape.h"
#include "./iterator.h"

Shape* selectFirstByArea(Shape* cs, double min, double max) {
    Iterator* it = cs->createIterator();
    Shape* result = nullptr;
    for (it->first(); !it->isDone(); it->next()) {
        if (min < it->currentItem()->area() && it->currentItem()->area() < max) {
            result = it->currentItem();
            break;
        }
    }
    delete it;
    return result;
}

Shape* selectFirstByArea(Iterator* it, double min, double max) {
    for (it->first(); !it->isDone(); it->next()) {
        if (min < it->currentItem()->area() && it->currentItem()->area() < max) {
            return it->currentItem();
        }
    }
    return nullptr;
}

template<class ShapeConstraint>
Shape* selectShape(Shape* shape, ShapeConstraint constraint) {
    Iterator* it = shape->createIterator();
    Shape* result = nullptr;
    for (it->first(); !it->isDone(); it->next()) {
        if (constraint(it->currentItem())) {
            result = it->currentItem();
            break;
        }
    }
    delete it;
    return result;
}