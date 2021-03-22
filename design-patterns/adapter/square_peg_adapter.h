#pragma once

#include <math.h>
#include "round_peg.h"
#include "square_peg.h"

class SquarePegAdapter : public RoundPeg {
    SquarePeg peg;

public:
    SquarePegAdapter(SquarePeg peg) : RoundPeg(), peg(peg) {}

    virtual double getRadius() override {
        int width = peg.getWidth();
        return std::sqrt(width * width * 2) / 2;
    }
};

