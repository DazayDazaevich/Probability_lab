#ifndef DOUBLE_DICE_H
#define DOUBLE_DICE_H

#include "penalty_bonus.h"  

class DoubleDice : public PenaltyDice, public BonusDice {
public:
    DoubleDice(Rollable& dice);
    unsigned roll() override;
};

class DoubleDiceWithoutMI : public Rollable {
private:
    PenaltyDice penalty_dice;
    BonusDice bonus_dice;
    
public:
    DoubleDiceWithoutMI(Rollable& dice);
    unsigned roll() override;
};

#endif