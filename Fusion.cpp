#include "Fusion.h"
#include <iostream>

double Fusion::simulateFusion(const Nucleus& nucleus1, const Nucleus& nucleus2) {
    double releasedEnergy = (nucleus1.getBindingEnergy() + nucleus2.getBindingEnergy()) * 0.85;
    std::cout << "Fusion of nuclei " << nucleus1.getName() << " and " << nucleus2.getName()
        << " released " << releasedEnergy << " MeV.\n";
    return releasedEnergy;
}
