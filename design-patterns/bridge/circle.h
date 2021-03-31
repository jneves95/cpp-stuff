#pragma once

#include "shape.h"
#include <string>

class Circle : public Shape {
public:
    Circle(Color* color) : Shape(1, color) {}

    std::string getShape() override { return "circle"; }
};