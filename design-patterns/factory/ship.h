#pragma once

#include <string>

class Ship {
private:
    std::string name;
    double damage;

public:
    Ship(std::string name, double damage = 0) : name(name), damage(damage) {}

    void setName(std::string name) { this->name = name; }
    std::string getName() { return name; }
    void setDamage(double damage) { this->damage = damage; }
    double getDamage() { return damage; }

    virtual void display() = 0;
    virtual void shoot() = 0;
};