#include "Fission.h"
#include <iostream>

double Fission::simulateFission(const Nucleus& nucleus) {
    double releasedEnergy = nucleus.getBindingEnergy() * 0.75;
    std::cout << "Fission of nucleus " << nucleus.getName()
        << " released " << releasedEnergy << " MeV.\n";
    return releasedEnergy;
}
