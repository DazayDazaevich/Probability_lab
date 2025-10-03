#ifndef UTILITIES_H
#define UTILITIES_H

#include "rollable.h"  
#include <vector>
#include <string>

double expected_value(Rollable& dice, unsigned number_of_rolls = 1000);
double value_probability(unsigned value, Rollable& dice, unsigned number_of_rolls = 10000);
void print_histogram(Rollable& dice, unsigned min_val, unsigned max_val, 
                    const std::string& name, unsigned num_rolls = 10000);

#endif