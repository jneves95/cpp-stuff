#pragma once

#include "color.h"
#include <iostream>

class Shape {
    int sides;
    Color* color;
    // Our composition can be made by reference or pointer: reference can't be null by definition, so it avoids null-checking, but it cannot be reassigned, it's const
    // Pointer can be reassigned after creation, but can also be null, so we might need to do some null-checking to avoid errors
    // In this example we use a pointer because it allows us to change the color of an already created shape

public:
    Shape(int sides, Color* color) : sides(sides), color(color) {}
    virtual ~Shape() {}

    virtual std::string getShape() = 0;

    void present() { 
        std::cout << "I am a " << color->getColor() << " " << getShape() << ". ";
        std::cout << "I have " << sides << " sides." << std::endl;
        color->doColoredThings();
    }

    void setColor(Color* color) {   // Wouldn't be possible with a reference
        this->color = color;
    }
};