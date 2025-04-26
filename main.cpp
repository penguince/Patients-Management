#include "Hospital.hpp"
#include <iostream>
#include <string>

void displayMenu() {
    std::cout << "\n===== Hospital Management System =====\n";
    std::cout << "Commands:\n";
    std::cout << "a <name> <priority> - Admit a patient\n";
    std::cout << "b <OR>             - Attend to patient in specified Operating Room\n";
    std::cout << "c                  - Display current patients\n";
    std::cout << "d                  - Show this help menu\n";
    std::cout << "e                  - Quit the program\n";
    std::cout << "===================================\n";
}

int main() {
    Hospital hospital;
    char command;
    std::string name;
    int priority, OR;

    std::cout << "Welcome to the Hospital Management System\n";
    displayMenu();

    while (true) {
        std::cout << "\nEnter command: ";
        std::cin >> command;
        
        command = tolower(command);

        if (command == 'a') { 
            std::cin >> name >> priority;
            if (priority < 1 || priority > 10) {
                std::cout << "Invalid priority. Must be between 1 and 10.\n";
            } else {
                hospital.admitPatient(name, priority);
            }
        } 
        else if (command == 'b') { 
            std::cin >> OR;
            hospital.attendPatient(OR);
        } 
        else if (command == 'c') { 
            hospital.displayPatients();
        } 
        else if (command == 'd') { 
            displayMenu();
        } 
        else if (command == 'e') { 
            std::cout << "Exiting program. Goodbye!\n";
            return 0;
        } 
        else {
            std::cout << "Invalid command. Type 'd' for help.\n";
        }
    }

    return 0;
}