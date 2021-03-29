#pragma once

#include "ship_factory.h"
#include "rocket_ship.h"

class RocketShipFactory : public ShipFactory {
public:
    Ship* createShip(std::string name, double damage = 0) override { return new RocketShip(name); }
};