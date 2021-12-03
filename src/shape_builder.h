#pragma once

#include <stack>
#include <list>

#include "./shape.h"
#include "./circle.h"
#include "./square.h"
#include "./compound_shape.h"

class ShapeBuilder {
    public:
        void buildCircle(double radius) {
            _shapes.push(new Circle(radius));
        }

        void buildSquare(double sideLength) {
            _shapes.push(new Square(sideLength));
        }

        void buildCompoundBegin() {
            _shapes.push(new CompoundShape());
        }

        void buildCompoundEnd() {
            std::list<Shape*> components;
            // while (typeid(*_shapes.top()) != typeid(CompoundShape) || 
            //     (typeid(*_shapes.top()) == typeid(CompoundShape) && !_shapes.top()->createIterator()->isDone())){
            //     components.push_back(_shapes.top());
            //     _shapes.pop();
            // }

            while (!(typeid(*_shapes.top()) == typeid(CompoundShape) && _shapes.top()->createIterator()->isDone())){
                components.push_back(_shapes.top());
                _shapes.pop();
            }
            Shape* compound = _shapes.top();

            for (auto it = components.rbegin(); it != components.rend(); it++) {
                compound->add(*it);
            }
        }

        Shape* getShape() {
            return _shapes.top();
        }

    private:
        Shape* _result;
        std::stack<Shape*> _shapes;
};