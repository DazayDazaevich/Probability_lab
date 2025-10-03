#include "utilities.h"
#include <iostream>
#include <vector>
#include <string>

double expected_value(Rollable& dice, unsigned number_of_rolls) {
    unsigned long long sum = 0;
    
    for (unsigned i = 0; i < number_of_rolls; i++) {
        sum += dice.roll();  
    }
    
    return static_cast<double>(sum) / static_cast<double>(number_of_rolls);  
}

double value_probability(unsigned value, Rollable& dice, unsigned number_of_rolls) {
    unsigned count = 0;
    
    for (unsigned i = 0; i < number_of_rolls; i++) {
        if (dice.roll() == value) {
            count++;
        }
    }
    
    return static_cast<double>(count) / static_cast<double>(number_of_rolls);
}

void print_histogram(Rollable& dice, unsigned min_val, unsigned max_val, 
                    const std::string& name, unsigned num_rolls) {
    std::cout << "\nгистограмма " << name << ":\n";
    
    std::vector<unsigned> counts(max_val - min_val + 1, 0);
    
    for (unsigned i = 0; i < num_rolls; i++) {
        unsigned result = dice.roll();
        if (result >= min_val && result <= max_val) {
            counts[result - min_val]++;
        }
    }
    
    for (unsigned i = 0; i < counts.size(); i++) {
        double prob = static_cast<double>(counts[i]) / num_rolls;
        std::cout << (i + min_val) << ": " << std::string(static_cast<int>(prob * 100), '*') 
                  << " (" << prob * 100 << "%)\n";
    }
}