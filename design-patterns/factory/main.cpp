#include "ship_factory.h"
#include "rocket_ship_factory.h"
#include "ufo_ship_factory.h"
#include "ship.h"
#include <iostream>

int main() {
    ShipFactory* factory = new RocketShipFactory();
    Ship* shipA = factory->createShip("USS Rico");


    factory = new UFOShipFactory();
    Ship* shipB = factory->createShip("USS Mendoza");
    
    shipA->display();
    shipA->shoot();
    shipB->display();
    shipB->shoot();

    delete factory;
    delete shipA;
    delete shipB;
}