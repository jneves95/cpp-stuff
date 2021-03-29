#pragma once

#include "ship.h"

class UFOShip : public Ship {
public: 
    UFOShip(std::string name) : Ship(name, 50) {}
    void display() override;
    void shoot() override;
};