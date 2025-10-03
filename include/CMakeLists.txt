cmake_minimum_required(VERSION 3.10)
project(ProbabilityLab)

set(CMAKE_CXX_STANDARD 11)

include_directories(include)

add_executable(probability_lab
    src/main.cpp
    src/dice.cpp
    src/penalty_bonus.cpp
    src/double_dice.cpp
    src/utilities.cpp
)