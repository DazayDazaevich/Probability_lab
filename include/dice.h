#ifndef DICE_H
#define DICE_H

#include "rollable.h" 
#include <random>

class Dice : public Rollable {
private:
    unsigned max;
    std::uniform_int_distribution<unsigned> dstr;
    std::default_random_engine reng;
    
public:
    Dice(unsigned max, unsigned seed);
    unsigned roll() override;
};

class ThreeDicePool : public Rollable {
private:
    Dice dice1, dice2, dice3;
    
public:
    ThreeDicePool(unsigned max, unsigned seed1, unsigned seed2, unsigned seed3);
    unsigned roll() override;
};

#endif