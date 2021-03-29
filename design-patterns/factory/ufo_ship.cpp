#include "ufo_ship.h"
#include <iostream>

void UFOShip::display() {
    std::cout << getName() << " is a UFO ship." << std::endl;
}

void UFOShip::shoot() {
    std::cout << getName() << " shoots its lasers for " << getDamage() << " damage!" << std::endl;
}
