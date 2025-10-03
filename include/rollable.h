#ifndef ROLLABLE_H
#define ROLLABLE_H

class Rollable {
public:
    virtual unsigned roll() = 0;
    virtual ~Rollable() = default;  // ДОБАВЬ виртуальный деструктор
};

#endif