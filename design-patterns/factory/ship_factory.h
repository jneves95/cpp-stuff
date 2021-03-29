#pragma once

#include "ship.h"

class ShipFactory {
public:
    virtual Ship* createShip(std::string name, double damage = 0) = 0;
};