#include "rocket_ship.h"
#include <iostream>

void RocketShip::display() {
    std::cout << getName() << " is a rocket ship." << std::endl;
}

void RocketShip::shoot() {
    std::cout << getName() << " shoots a rocket for an explosive " << getDamage() << " damage!" << std::endl;
}
