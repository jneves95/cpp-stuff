#include <iostream>
#include "round_hole.h"
#include "round_peg.h"
#include "square_peg.h"
#include "square_peg_adapter.h"

/**
 * Let's say we have a round hole with a specific radius, but we want a square peg to be able to fit in the round hole.
 * We can create an adapter for the square peg to act as a round peg.
 */
int main() {
    RoundHole hole(5);
    RoundPeg roundPeg(4);
    SquarePeg squarePeg(6);
    SquarePegAdapter adapter(squarePeg);

    // To take advantage of polymorphism without using pure virtual methods, we pass pointers to the objects we want.
    // Otherwise, if using a Base class reference, we would get Base class behavior (static linking).

    RoundPeg *test = &roundPeg;
    std::cout << "Does the round peg fit the round hole? " << (hole.fits(test) ? "Yes." : "No.") << std::endl;

    // hole.fits(squarePeg) woudln't work for our hole method, so we need to feed it an adapter that wraps the square peg.

    test = &adapter;
    std::cout << "Does the square peg fit the round hole? " << (hole.fits(test) ? "Yes." : "No.") << std::endl;
}