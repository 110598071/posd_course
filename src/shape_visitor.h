#pragma once

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

typedef bool (*ShapeConstraint)(Shape*); //pointer to function
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