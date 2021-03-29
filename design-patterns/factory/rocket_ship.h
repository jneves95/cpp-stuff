#pragma once

#include "ship.h"

class RocketShip : public Ship {
public:
    RocketShip(std::string name) : Ship(name, 15) {}
    void display() override;
    void shoot() override;
};