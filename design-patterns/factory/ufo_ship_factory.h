#pragma once

#include "ship_factory.h"
#include "ufo_ship.h"

class UFOShipFactory : public ShipFactory {
public:
    Ship* createShip(std::string name, double damage = 0) { return new UFOShip(name); }
};