#pragma once

#include "shape.h"
#include <string>

class Square : public Shape {
public:
    Square(Color* color) : Shape(4, color) {}

    std::string getShape() override { return "square"; }
};