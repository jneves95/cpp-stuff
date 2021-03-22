#pragma once

#include "round_peg.h"

class RoundHole {
    double radius;

public:
    RoundHole(double radius) : radius(radius) {}

    double getRadius() { return radius; }

    bool fits(RoundPeg *peg) {
        return peg->getRadius() <= radius;
    }
};