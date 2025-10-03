#ifndef PENALTY_BONUS_H
#define PENALTY_BONUS_H

#include "rollable.h"  
#include <algorithm>

class PenaltyDice : virtual public Rollable {
private:
    Rollable& dice;
    
public:
    PenaltyDice(Rollable& dice);
    unsigned roll() override;
};

class BonusDice : virtual public Rollable {
private:
    Rollable& dice;
    
public:
    BonusDice(Rollable& dice);
    unsigned roll() override;
};

#endif