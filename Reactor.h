#ifndef REACTOR_H
#define REACTOR_H

#include "Nucleus.h"
#include <vector>
#include <string>

class Reactor {
private:
    double totalEnergy;
    std::vector<std::string> reactionHistory;

public:
    Reactor();
    void addFission(const Nucleus& nucleus);
    void addFusion(const Nucleus& nucleus1, const Nucleus& nucleus2);
    void displayTotalEnergy() const;
    void displayReactionHistory() const;
};

#endif // REACTOR_H
