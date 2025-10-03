#include "dice.h"
#include "penalty_bonus.h"
#include "double_dice.h"  
#include "utilities.h"
#include <iostream>
#include <string>  



int main() {
    // задание 1

    std::cout << "\n\nЗАДАНИЕ 1\n";
    Dice d6(6, 42);
    std::cout << "одна кость \n";
    std::cout << "один бросок: " << d6.roll() << "\n";
    std::cout << "среднее за 1000 бросков: " << expected_value(d6, 1000) << "\n";
    std::cout << "теоретическое среднее: " << (1+2+3+4+5+6)/6. << "\n\n";
    
    ThreeDicePool threeD6(6, 42, 43, 44);
    std::cout << "три кости:\n";
    std::cout << "один бросок: " << threeD6.roll() << "\n";
    std::cout << "среднее за 10000 бросков: " << expected_value(threeD6, 10000) << "\n";
    std::cout << "теоретическое среднее: " << ((1+2+3+4+5+6)/6. * 3) << "\n";

    // задание 2
    std::cout << "\n\nЗАДАНИЕ 2\n";
    Dice d100(100, 123);
    PenaltyDice penalty_d100(d100);
    BonusDice bonus_d100(d100);

    std::cout << "один бросок: " << d100.roll() << "\n";
    std::cout << "штраф: " << penalty_d100.roll() << "\n";
    std::cout << "преимущество: " << bonus_d100.roll() << "\n";

    print_histogram(d100, 1, 100, "1 бросок D100");
    print_histogram(penalty_d100, 1, 100, "D100 со штрафом");
    print_histogram(bonus_d100, 1, 100, "D100 с преимуществом");

    PenaltyDice penalty_threeD6(threeD6);
    BonusDice bonus_threeD6(threeD6);

    std::cout << "3 броска: " << threeD6.roll() << "\n";
    std::cout << "штраф: " << penalty_threeD6.roll() << "\n";
    std::cout << "преимущество: " << bonus_threeD6.roll() << "\n";

    print_histogram(threeD6, 3, 18, "3 броска");
    print_histogram(penalty_threeD6, 3, 18, "3 броска со штрафом");
    print_histogram(bonus_threeD6, 3, 18, "3 броска с преимуществом");

    // задание 3
    std::cout << "\n\nЗАДАНИЕ 3\n";
    
    DoubleDice double_dice_mi(d100);
    std::cout << "множественное наследование\n";
    std::cout << "один бросок: " << double_dice_mi.roll() << "\n";
    std::cout << "среднее за 10000 бросков: " << expected_value(double_dice_mi, 10000) << "\n";
    
    DoubleDiceWithoutMI double_dice_no_mi(d100);
    std::cout << "\nDoubleDice без множественного наследования\n";
    std::cout << "один бросок DoubleDice: " << double_dice_no_mi.roll() << "\n";
    std::cout << "среднее за 10000: " << expected_value(double_dice_no_mi, 10000) << "\n";
    
    std::cout << "\nгистограмма DoubleDice ---\n";
    print_histogram(double_dice_mi, 2, 200, "DoubleDice (множественное наследование)");

    return 0;
}