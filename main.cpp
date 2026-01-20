#include <iostream>
#include "ParkingSystem.h"

int main() {
    // 1. Initialize City with 5 Zones
    ParkingSystem city(5); 
    int choice;
    bool running = true;

    while (running) {
        std::cout << "\n==============================" << std::endl;
        std::cout << "   SMART PARKING SYSTEM GUI   " << std::endl;
        std::cout << "==============================" << std::endl;
        std::cout << "1. Park Vehicle" << std::endl;
        std::cout << "2. Checkout (Receipt)" << std::endl;
        std::cout << "3. View Buildings" << std::endl;
        std::cout << "4. Exit" << std::endl;
        std::cout << "Select: ";
        std::cin >> choice;

        if (choice == 1) {
            char id[20], type[10], deal[15];
            int zone;
            std::cout << "Enter ID: "; std::cin >> id;
            std::cout << "Type (Car/Bike/Jeep): "; std::cin >> type;
            std::cout << "Pref Building (1-5): "; std::cin >> zone;
            std::cout << "Deal (None/Weekly/Monthly): "; std::cin >> deal;

            ParkingRequest req(id, type, zone, deal);
            city.processRequest(req);
        }
        else if (choice == 2) {
            char id[20], type[10], deal[15];
            int hours;
            std::cout << "Enter ID: "; std::cin >> id;
            std::cout << "Enter Type (Car/Bike/Jeep): "; std::cin >> type;
            std::cout << "Enter Deal: "; std::cin >> deal;
            std::cout << "Hours: "; std::cin >> hours;

            city.generateReceipt(id, hours, type, deal);
        }
        else if (choice == 3) {
            city.showStatus();
        }
        else if (choice == 4) {
            running = false;
        }
    }
    return 0;
}