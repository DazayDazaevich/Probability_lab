#include "penalty_bonus.h"

PenaltyDice::PenaltyDice(Rollable& dice) : dice(dice) {}

unsigned PenaltyDice::roll() {
    unsigned roll1 = dice.roll();
    unsigned roll2 = dice.roll();
    return std::min(roll1, roll2);
}

BonusDice::BonusDice(Rollable& dice) : dice(dice) {}

unsigned BonusDice::roll() {
    unsigned roll1 = dice.roll();
    unsigned roll2 = dice.roll();
    return std::max(roll1, roll2);
}