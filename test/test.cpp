#include <gtest/gtest.h>

#include "test_square.h"
#include "test_circle.h"
#include "test_shape.h"
#include "test_compound_shape.h"
#include "test_iterator.h"
#include "test_utility.h"
#include "test_visitor.h"

#include <stdlib.h>
#include <iostream>

int main(int argc,char** argv){
    std::cout<< "Hello world!" << std::endl;
    std::cout<< "Testing!" << std::endl;
    testing::InitGoogleTest(&argc,argv);
    return RUN_ALL_TESTS();
}

/*
TEST(Sanity, First){
    ASSERT_TRUE(true);
}
*/