#include "Reactor.h"
#include "Fission.h"
#include "Fusion.h"
#include <iostream>

Reactor::Reactor() : totalEnergy(0) {}

void Reactor::addFission(const Nucleus& nucleus) {
    double energy = Fission::simulateFission(nucleus);
    totalEnergy += energy;
    reactionHistory.push_back("Fission of " + nucleus.getName() + ": " + std::to_string(energy) + " MeV");
}

void Reactor::addFusion(const Nucleus& nucleus1, const Nucleus& nucleus2) {
    double energy = Fusion::simulateFusion(nucleus1, nucleus2);
    totalEnergy += energy;
    reactionHistory.push_back("Fusion of " + nucleus1.getName() + " and " + nucleus2.getName() + ": " + std::to_string(energy) + " MeV");
}

void Reactor::displayTotalEnergy() const {
    std::cout << "Total energy generated in the reactor: " << totalEnergy << " MeV\n";
}

void Reactor::displayReactionHistory() const {
    std::cout << "Reaction history:\n";
    for (const auto& reaction : reactionHistory) {
        std::cout << " - " << reaction << "\n";
    }
}
