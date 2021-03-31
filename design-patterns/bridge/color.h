#pragma once

#include <string>

class Color {
public:
    virtual ~Color() {}
    virtual std::string getColor() = 0;
    virtual void doColoredThings() = 0;
};