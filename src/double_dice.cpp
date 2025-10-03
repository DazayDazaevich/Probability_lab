#include "double_dice.h"

DoubleDice::DoubleDice(Rollable& dice) 
    : PenaltyDice(dice), BonusDice(dice) {}

unsigned DoubleDice::roll() {
    return PenaltyDice::roll() + BonusDice::roll();
}

DoubleDiceWithoutMI::DoubleDiceWithoutMI(Rollable& dice) 
    : penalty_dice(dice), bonus_dice(dice) {}

unsigned DoubleDiceWithoutMI::roll() {
    return penalty_dice.roll() + bonus_dice.roll();
}