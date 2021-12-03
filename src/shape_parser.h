#pragma once

#include <string>
#include "./shape.h"
#include "./shape_builder.h"
#include "./compound_shape.h"
#include "./circle.h"
#include "./square.h"
#include "./scanner.h"
#include "./mock_scanner.h"

class ShapeParser {
    public:
        ShapeParser(ShapeBuilder* builder, Scanner* scanner): _builder(builder), _scanner(scanner) {}

        ~ShapeParser() {
            delete _builder;
            delete _scanner;
        }

        Shape* parse() {
            while (!_scanner->isDone()) {
                std::string token = _scanner->nextToken();
                if (token == "circle") {
                    _builder->buildCircle(_scanner->nextDouble());
                }
                else if (token == "square") {
                    _builder->buildSquare(_scanner->nextDouble());
                }
                else if (token == "compound") {
                    _scanner->nextToken(); // ignore {
                    _builder->buildCompoundBegin();
                }
                else if (token == "}") {
                    _builder->buildCompoundEnd();
                }
            }
            return _builder->getShape();
        }

    private:
        ShapeBuilder* _builder;
        Scanner* _scanner;
};