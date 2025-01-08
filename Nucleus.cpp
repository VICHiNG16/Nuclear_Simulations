#include "Nucleus.h"

Nucleus::Nucleus(std::string n, int p, int nn, double m, double e)
    : name(n), protons(p), neutrons(nn), mass(m), bindingEnergy(e) {}

std::string Nucleus::getName() const { return name; }
int Nucleus::getProtons() const { return protons; }
int Nucleus::getNeutrons() const { return neutrons; }
double Nucleus::getMass() const { return mass; }
double Nucleus::getBindingEnergy() const { return bindingEnergy; }
