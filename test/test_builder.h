#include "../src/compound_shape.h"
#include "../src/shape_builder.h"

class CaseBuilder: public ::testing::Test {
    protected:
        const double delta = 0.001;

        void SetUp() override {}

        void TearDown() override {} 
};

TEST_F(CaseBuilder, BuildCircle) {
    ShapeBuilder* builder = new ShapeBuilder();
    builder->buildCircle(1.0);
    Shape* result = builder->getShape();

    ASSERT_NEAR(1*1*M_PI, result->area(), delta);
    delete builder;
}

TEST_F(CaseBuilder, BuildCompound) {
    ShapeBuilder* builder = new ShapeBuilder();

    builder->buildCompoundBegin();
    builder->buildCircle(1.0);
    builder->buildCircle(2.0);
    builder->buildCompoundEnd();

    Shape* result = builder->getShape();

    ASSERT_NEAR(1*1*M_PI + 2*2*M_PI, result->area(), delta);
    delete builder;
}

TEST_F(CaseBuilder, BuildComplexCompound) {
    ShapeBuilder* builder = new ShapeBuilder();

    builder->buildCompoundBegin();
    builder->buildCompoundBegin();
    builder->buildCircle(1.0);
    builder->buildCircle(2.0);
    builder->buildCompoundEnd();
    builder->buildSquare(3.0);
    builder->buildCompoundEnd();

    Shape* result = builder->getShape();

    Iterator *it = result->createIterator();

    ASSERT_NEAR(1*1*M_PI + 2*2*M_PI, it->currentItem()->area(), delta);

    it->next();
    ASSERT_NEAR(9, it->currentItem()->area(), delta);
    delete builder;
}