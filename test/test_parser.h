#include <string>

#include "../src/shape_parser.h"
#include "../src/shape_scanner.h"
#include "../src/mock_scanner.h"
#include "../src/shape.h"

TEST(CaseParser, ParseCompound) {
    std::string input = "compound {\n circle 1.0\n circle 2.0\n}";

    ShapeParser* parser = new ShapeParser(new ShapeBuilder(),new MockScanner());
    Shape* result = parser->parse();

    ASSERT_NEAR(1*1*M_PI + 2*2*M_PI, result->area(), 0.001);
}

TEST(CaseParser, ParseComplexCompound){
    std::string input = "compound {\n compound {\n circle 1.0\n circle 2.0\n }\n square 3.0\n }";
    ShapeParser* parser = new ShapeParser(new ShapeBuilder(), new ShapeScanner(input));
    Shape* result = parser->parse();

    ASSERT_NEAR(1*1*M_PI + 2*2*M_PI + 9, result->area(), 0.01);
}
