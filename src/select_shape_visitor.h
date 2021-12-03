#pragma once

#include "./shape.h"
#include "./shape_visitor.h"
#include "./compound_shape.h"
#include "./circle.h"
#include "./square.h"
#include "./iterator.h"
#include "./select_shape_visitor.h"

// typedef bool (*ShapeConstraint)(Shape*); //pointer to function
template<class ShapeConstraint>
class SelectShapeVisitor: public ShapeVisitor {
    public:
        SelectShapeVisitor():_result(nullptr), _constraint(nullptr) {}
        SelectShapeVisitor(ShapeConstraint constraint):_result(nullptr), _constraint(constraint) {}
        void visitCompoundShape(CompoundShape* cs);
        void visitCircle(Circle* c);
        void visitSquare(Square* c);
        Shape* getShape();
    private:
        Shape* _result;
        ShapeConstraint _constraint;
};

template<typename ShapeConstraint>
void SelectShapeVisitor<ShapeConstraint>::visitCompoundShape(CompoundShape* cs) {
    // ToDo: check if the sought after shape is a compoundshape
    Iterator* it = cs->createIterator();
    for (it->first(); !it->isDone(); it->next()) {
        it->currentItem()->accept(this);
    }
}

template<typename ShapeConstraint>
void SelectShapeVisitor<ShapeConstraint>::visitCircle(Circle* c) {
    if (_constraint(c)) {
        _result = c;
    }
}

template<typename ShapeConstraint>
void SelectShapeVisitor<ShapeConstraint>::visitSquare(Square* s) {
    if (_constraint(s)) {
        _result = s;
    }
}

template<typename ShapeConstraint>
Shape* SelectShapeVisitor<ShapeConstraint>::getShape() {
    return _result;
}