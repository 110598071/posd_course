#include "../src/utility.h"
#include "../src/circle.h"
#include "../src/square.h"
#include "../src/shape.h"
#include "../src/shape_visitor.h"
#include "../src/select_shape_visitor.h"

typedef bool (*ShapeConstraint)(Shape*);

TEST(CaseVisitor, SelectShapeOnCompoundShape) {
    Shape* c1 = new Circle(1.0);
    Shape* c2 = new Circle(1.0);
    Shape* s = new Square(5.0);
    Shape* shapes[3] = {c1, c2, s};
    CompoundShape cs(shapes, 3);

    ShapeVisitor* visitor = new SelectShapeVisitor<ShapeConstraint>([](Shape* shape) {
        return shape->area() > 20.0 && shape->area() < 30.0;
    });

    // ShapeVisitor* visitor = new SelectShapeVisitor<ShapeConstraint>();
    cs.accept(visitor);
    Shape* result = visitor->getShape();

    ASSERT_EQ(s, result);
}

TEST(CaseVisitor, SelectShapeOnCircleFailed) {
    Circle* c1 = new Circle(1.0);

    ShapeVisitor* visitor = new SelectShapeVisitor<ShapeConstraint>([](Shape* shape) {
        return shape->area() > 20.0 && shape->area() < 30.0;
    });
    c1->accept(visitor);

    visitor->visitCircle(c1);
    Shape* result = visitor->getShape();

    ASSERT_EQ(nullptr, result);
}

TEST(CaseVisitor, SelectShapeOnCircle) {
    Circle* c1 = new Circle(3.0);

    ShapeVisitor* visitor = new SelectShapeVisitor<ShapeConstraint>([](Shape* shape) {
        return shape->area() > 20.0 && shape->area() < 30.0;
    });
    c1->accept(visitor);

    visitor->visitCircle(c1);
    Shape* result = visitor->getShape();

    ASSERT_EQ(c1, result);
}

TEST(CaseVisitor, SelectShapeByInstance) {
    Shape* c1 = new Circle(1.0);
    Shape* c2 = new Circle(1.0);
    Shape* s = new Square(5.0);
    Shape* shapes[3] = {c1, c2, s};
    CompoundShape cs(shapes, 3);

    ShapeVisitor* visitor = new SelectShapeVisitor([c2](Shape* shape) {
        return c2 == shape;
    });
    cs.accept(visitor);
    Shape* result = visitor->getShape();

    ASSERT_EQ(c2, result);
}