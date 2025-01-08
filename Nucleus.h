#ifndef NUCLEUS_H
#define NUCLEUS_H

#include <string>

class Nucleus {
private:
    std::string name;
    int protons;
    int neutrons;
    double mass;
    double bindingEnergy;

public:
    Nucleus(std::string n, int p, int nn, double m, double e);
    std::string getName() const;
    int getProtons() const;
    int getNeutrons() const;
    double getMass() const;
    double getBindingEnergy() const;
};

#endif // NUCLEUS_H
