#pragma once

class Shape;
class Circle;
class Square;
class CompoundShape;

class ShapeVisitor {
    public:
        virtual ~ShapeVisitor(){}
        virtual void visitCompoundShape(CompoundShape* cs) = 0;
        virtual void visitCircle(Circle* c) = 0;
        virtual void visitSquare(Square* c) = 0;
        virtual Shape* getShape() = 0;
    protected:
        ShapeVisitor(){}
};