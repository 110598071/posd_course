#pragma once

#include "./iterator.h"

class CompoundIterator : public Iterator{
    public:
        CompoundIterator(Shape** begin, Shape** end): _begin(begin), _end(end) {}

        void first() override {
            _current = _begin;
        }

        void next() override {
            _current++;
        }

        bool isDone() const override {
            return _current == _end;
        }

        Shape* currentItem() const override {
            return *_current;
        }

    private:
        Shape** _current;
        Shape** _begin;
        Shape** _end;
};