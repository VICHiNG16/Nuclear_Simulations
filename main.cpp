#include <iostream>
#include <vector>
#include "Nucleus.h"
#include "Reactor.h"
#include "Menu.h"

int main() {
    std::vector<Nucleus> nuclei;
    Reactor reactor;

    // Load nuclei from file
    loadNucleiFromFile("nuclei.txt", nuclei);

    // Start role selection loop
    roleSelection(reactor, nuclei);

    return 0;
}
