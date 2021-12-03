#pragma once

#include "./iterator.h"

template<class ShapePtrPtr>
class CompoundIterator : public Iterator{
    public:
        // CompoundIterator(Shape** begin, Shape** end): _begin(begin), _end(end) {}
        CompoundIterator(ShapePtrPtr begin, ShapePtrPtr end): _begin(begin), _end(end) {
            first();
        }

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
        ShapePtrPtr _current;
        ShapePtrPtr _begin;
        ShapePtrPtr _end;
};