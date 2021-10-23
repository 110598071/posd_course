#pragma once

#include "./compound_shape.h"
#include "./iterator.h"

Shape* selectFirstByArea(CompoundShape* cs, double min, double max) {
    for (int i = 0; i < cs->count(); i++) {
        if (min < cs->shapes()[i]->area() && cs->shapes()[i]->area() < max) {
            return cs->shapes()[i];
        }
    }
    return nullptr;
}

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