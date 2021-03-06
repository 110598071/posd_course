#include "../src/square.h"
#include <algorithm>

TEST(CaseSquare, Creation) {
    Square s(10.0);
    ASSERT_NEAR(10,s.sideLength(),0.0001);
}

TEST(CaseSquare, Area) {
    Square s(10.0);
    ASSERT_NEAR(100, s.area(), 0.0001);
}

TEST(CaseSquare, Perimeter) {
    Square s(10.0);
    ASSERT_NEAR(40, s.perimeter(), 0.0001);
}

TEST(CaseSquare, SortIncreasing) {
    Square squares[2] = {Square(10.0), Square(2.0)};
    std::sort(squares, squares+2,
                [](Square s1, Square s2) {return s1.area() < s2.area();} //lambda
                );
    ASSERT_NEAR(4, squares[0].area(), 0.0001);
    ASSERT_NEAR(100, squares[1].area(), 0.0001);
}