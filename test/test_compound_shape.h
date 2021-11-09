#include "../src/compound_shape.h"
#include "../src/circle.h"
#include "../src/square.h"
#include "../src/utility.h"
#include "../src/iterator.h"

TEST(CaseCompoundShape, Creation) {
    Shape* c1 = new Circle(1.0);
    Shape* c2 = new Circle(1.0);
    Shape* s = new Square(5.0);
    
    Shape* shapes[3] = {c1, c2, s};
    CompoundShape cs(shapes,3);

    EXPECT_EQ(3, cs.count());
    EXPECT_NEAR(31.283, cs.area(), 0.001);
}

TEST(CaseCompoundShape, CreationWithCompoundShape) {
    Shape* c1 = new Circle(1.0);
    Shape* c2 = new Circle(1.0);

    Shape* shapes[2] = {c1, c2};
    CompoundShape* cs1 = new CompoundShape(shapes,2);

    Shape* s = new Square(5.0);
    Shape* shapes2[2] = {cs1, s};
    CompoundShape cs2(shapes2, 2);

    EXPECT_EQ(2, cs2.count());
    EXPECT_NEAR(31.283, cs2.area(), 0.001);
}

TEST(CaseCompoundShape, SelectByFirstArea) {
    Shape* c1 = new Circle(1.0);
    Shape* c2 = new Circle(1.0);
    Shape* s = new Square(5.0);

    Shape* shapes[3] = {c1, c2, s};
    CompoundShape cs(shapes,3);

    Shape* t = cs.selectFirstByArea(20.0, 30.0);
    EXPECT_NEAR(25, t->area(), 0.0001);

    Shape* t2 = cs.selectFirstByArea(3.0, 5.0);
    EXPECT_EQ(c1, t2);
}

TEST(CaseCompoundShape, SelectByFirstAreaFunction) {
    Shape* c1 = new Circle(1.0);
    Shape* c2 = new Circle(1.0);
    Shape* s = new Square(5.0);

    Shape* shapes[3] = {c1, c2, s};
    CompoundShape cs(shapes,3);

    Shape* t = selectFirstByArea(&cs, 20.0, 30.0);
    EXPECT_EQ(s, t);
}

TEST(CaseCompoundShape, SelectByFirstAreaFunctionOnShape) {
    Shape* c1 = new Circle(1.0);
    Shape* c2 = new Circle(1.0);
    Shape* s = new Square(5.0);

    Shape* shapes[3] = {c1, c2, s};
    Shape* cs = new CompoundShape(shapes,3);

    Shape* t = selectFirstByArea(cs, 20.0, 30.0);
    EXPECT_EQ(s, t);
}

// TEST(CaseCompoundShape, SelectByFirstAreaFunctionOnCircle) {
//     Shape* c = new Circle(1.0);
//     try {
//         Shape* t = selectFirstByArea(c, 20.0, 30.0);
//         FAIL();
//     }catch(std::string e) {
//         ASSERT_EQ("method not allowed", e);
//     }
// }

TEST(CaseCompoundShape, SelectFirstByAreaIterator) {
    Shape* c1 = new Circle(1.0);
    Shape* c2 = new Circle(1.0);
    Shape* s = new Square(5.0);

    Shape* shapes[3] = {c1, c2, s};
    CompoundShape cs(shapes,3);

    Shape* t = selectFirstByArea(cs.createIterator(), 20.0, 30.0);
    EXPECT_EQ(s, t);
}

TEST(CaseCompoundShape, Iterator) {
    Shape* c1 = new Circle(1.0);
    Shape* c2 = new Circle(1.0);
    Shape* s = new Square(5.0);

    Shape* shapes[3] = {c1, c2, s};
    CompoundShape cs(shapes,3);

    Iterator* it = cs.createIterator();

    it->first();
    EXPECT_EQ(c1, it->currentItem());

    it->next();
    EXPECT_EQ(c2, it->currentItem());

    it->next();
    EXPECT_EQ(s, it->currentItem());

    it->next();
    EXPECT_TRUE(it->isDone());
}