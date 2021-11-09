#include "./compound_shape.h"
#include "./shape.h"
#include "./circle.h"
#include "./square.h"
#include "./iterator.h"

void SelectShapeVisitor::visitCompoundShape(CompoundShape* cs) {
    Iterator* it = cs->createIterator();
    for (it->first(); !it->isDone(); it->next()) {
        it->currentItem()->accept(this);
    }
}

void SelectShapeVisitor::visitCircle(Circle* c) {
    if (_constraint) {
        if (_constraint(c)) {
            _result = c;
        }
    }
    else if (c->area() > 20.0 && c->area() < 30.0) {
        _result = c;
    }
}

void SelectShapeVisitor::visitSquare(Square* s) {
    if (_constraint) {
        if (_constraint(s)) {
            _result = s;
        }
    }
    else if (s->area() > 20.0 && s->area() < 30.0) {
        _result = s;
    }
}

Shape* SelectShapeVisitor::getShape() {
    return _result;
}