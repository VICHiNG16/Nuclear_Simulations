#ifndef MENU_H
#define MENU_H

#include <vector>
#include "Nucleus.h"
#include "Reactor.h"

void loadNucleiFromFile(const std::string& filename, std::vector<Nucleus>& nuclei);
void adminMenu(Reactor& reactor, std::vector<Nucleus>& nuclei);
void userMenu(const Reactor& reactor);
void roleSelection(Reactor& reactor, std::vector<Nucleus>& nuclei);

#endif // MENU_H
