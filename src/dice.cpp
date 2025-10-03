#include "dice.h"

Dice::Dice(unsigned max, unsigned seed) 
    : max(max), dstr(1, max), reng(seed) {}

unsigned Dice::roll() {
    return dstr(reng);
}

ThreeDicePool::ThreeDicePool(unsigned max, unsigned seed1, unsigned seed2, unsigned seed3)
    : dice1(max, seed1), dice2(max, seed2), dice3(max, seed3) {}

unsigned ThreeDicePool::roll() {
    return dice1.roll() + dice2.roll() + dice3.roll();
}