#pragma once

#include "color.h"
#include <iostream>
#include <string>

class RedColor : public Color {
public:
    RedColor() {}
    std::string getColor() override { return "red"; }

    void doColoredThings() override {
        std::cout << "Doing angry red things!" << std::endl;
    }
};