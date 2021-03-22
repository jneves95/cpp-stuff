#pragma once

class RoundPeg {
    double radius;

public:
    RoundPeg(double radius = 0) : radius(radius) {}

    virtual double getRadius() { return radius; }
};