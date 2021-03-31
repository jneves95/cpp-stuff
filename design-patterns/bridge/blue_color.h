#pragma once

#include "color.h"
#include <iostream>
#include <string>

class BlueColor : public Color {
public:
    BlueColor() {}
    std::string getColor() override { return "blue"; }
    
    void doColoredThings() override {
        std::cout << "Doing sad blue things..." << std::endl;
    }
};