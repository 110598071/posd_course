#pragma once

#include "./shape.h"

class Iterator {
    public:
        Iterator(){}

        virtual ~Iterator(){}

        virtual void first() {};

        virtual void next() {}

        virtual bool isDone() const = 0;

        virtual Shape* currentItem() const {
            return nullptr;
        }
};