#include <iostream>
#include <fstream>
#include <vector>
#include "Menu.h"

void loadNucleiFromFile(const std::string& filename, std::vector<Nucleus>& nuclei) {
    std::ifstream file(filename);
    if (!file) {
        std::cerr << "Error: Cannot open file " << filename << "\n";
        return;
    }

    std::string name;
    int protons, neutrons;
    double mass, bindingEnergy;

    while (file >> name >> protons >> neutrons >> mass >> bindingEnergy) {
        nuclei.push_back(Nucleus(name, protons, neutrons, mass, bindingEnergy));
    }
    file.close();
}

void adminMenu(Reactor& reactor, std::vector<Nucleus>& nuclei) {
    while (true) {
        std::cout << "\nAdmin Menu:\n";
        std::cout << "1. Add new nucleus\n";
        std::cout << "2. Simulate fission\n";
        std::cout << "3. Simulate fusion\n";
        std::cout << "4. View total energy\n";
        std::cout << "5. View reaction history\n";
        std::cout << "6. Switch user\n";
        std::cout << "7. Exit\n";
        std::cout << "Enter your choice: ";

        int option;
        std::cin >> option;

        switch (option) {
        case 1: {
            std::string name;
            int protons, neutrons;
            double mass, bindingEnergy;

            std::cout << "Enter nucleus name: ";
            std::cin >> name;
            std::cout << "Enter number of protons: ";
            std::cin >> protons;
            std::cout << "Enter number of neutrons: ";
            std::cin >> neutrons;
            std::cout << "Enter mass (u): ";
            std::cin >> mass;
            std::cout << "Enter binding energy (MeV): ";
            std::cin >> bindingEnergy;

            nuclei.push_back(Nucleus(name, protons, neutrons, mass, bindingEnergy));
            std::cout << "Nucleus " << name << " added successfully.\n";
            break;
        }
        case 2: {
            if (nuclei.empty()) {
                std::cout << "No nuclei available for fission.\n";
            }
            else {
                std::cout << "Select a nucleus for fission:\n";
                for (size_t i = 0; i < nuclei.size(); ++i) {
                    std::cout << i + 1 << ". " << nuclei[i].getName() << "\n";
                }

                int choice;
                std::cin >> choice;

                if (choice > 0 && choice <= nuclei.size()) {
                    reactor.addFission(nuclei[choice - 1]);
                }
                else {
                    std::cout << "Invalid choice.\n";
                }
            }
            break;
        }
        case 3: {
            if (nuclei.size() < 2) {
                std::cout << "Not enough nuclei for fusion.\n";
            }
            else {
                std::cout << "Select two nuclei for fusion:\n";
                for (size_t i = 0; i < nuclei.size(); ++i) {
                    std::cout << i + 1 << ". " << nuclei[i].getName() << "\n";
                }

                int choice1, choice2;
                std::cout << "Enter the index of the first nucleus: ";
                std::cin >> choice1;
                std::cout << "Enter the index of the second nucleus: ";
                std::cin >> choice2;

                if (choice1 > 0 && choice1 <= nuclei.size() && choice2 > 0 && choice2 <= nuclei.size()) {
                    reactor.addFusion(nuclei[choice1 - 1], nuclei[choice2 - 1]);
                }
                else {
                    std::cout << "Invalid choices.\n";
                }
            }
            break;
        }
        case 4:
            reactor.displayTotalEnergy();
            break;
        case 5:
            reactor.displayReactionHistory();
            break;
        case 6:
            return; // Return to role selection
        case 7:
            std::cout << "Exiting program.\n";
            exit(0); // Exit the program
        default:
            std::cout << "Invalid option. Try again.\n";
        }
    }
}

void userMenu(const Reactor& reactor) {
    while (true) {
        std::cout << "\nUser Menu:\n";
        std::cout << "1. View total energy\n";
        std::cout << "2. View reaction history\n";
        std::cout << "3. Switch user\n";
        std::cout << "4. Exit\n";
        std::cout << "Enter your choice: ";

        int option;
        std::cin >> option;

        switch (option) {
        case 1:
            reactor.displayTotalEnergy();
            break;
        case 2:
            reactor.displayReactionHistory();
            break;
        case 3:
            return; // Return to role selection
        case 4:
            std::cout << "Exiting program.\n";
            exit(0); // Exit the program
        default:
            std::cout << "Invalid option. Try again.\n";
        }
    }
}

void roleSelection(Reactor& reactor, std::vector<Nucleus>& nuclei) {
    while (true) {
        std::string role;
        std::cout << "\nEnter role (admin/user): ";
        std::cin >> role;

        if (role == "admin") {
            std::string password;
            std::cout << "Enter password: ";
            std::cin >> password;

            if (password == "admin123") {
                adminMenu(reactor, nuclei);
            }
            else {
                std::cout << "Invalid password.\n";
            }
        }
        else if (role == "user") {
            userMenu(reactor);
        }
        else {
            std::cout << "Invalid role. Please enter 'admin' or 'user'.\n";
        }
    }
}
