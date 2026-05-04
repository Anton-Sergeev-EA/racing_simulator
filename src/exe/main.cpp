#include <iostream>
#include <memory>
#include "RaceLib/Race.h"
#include "RaceLib/GroundRace.h"
#include "RaceLib/AirRace.h"
#include "RaceLib/MixedRace.h"
#include "RaceLib/RaceSimulator.h"
#include "RaceLib/VehicleFactory.h"

using namespace RaceLib;

void printVehicles() {
    std::cout << "\nДоступные ТС:\n";
    for (const auto& name : VehicleFactory::getAllVehicleNames()) {
        std::cout << "- " << name << "\n";
    }
}

int main() {
    bool exitProgram = false;
    
    while (!exitProgram) {
        std::cout << "\n=== СИМУЛЯТОР ГОНОК ===\n";
        std::cout << "Выберите тип гонки:\n";
        std::cout << "1. Только наземные\n";
        std::cout << "2. Только воздушные\n";
        std::cout << "3. Наземные и воздушные\n";
        std::cout << "> ";
        
        int raceTypeChoice;
        std::cin >> raceTypeChoice;
        
        std::unique_ptr<Race> race;
        RaceType type;
        
        switch (raceTypeChoice) {
            case 1:
                race = std::make_unique<GroundRace>();
                type = RaceType::Ground;
                std::cout << "Создана наземная гонка.\n";
                break;
            case 2:
                race = std::make_unique<AirRace>();
                type = RaceType::Air;
                std::cout << "Создана воздушная гонка.\n";
                break;
            case 3:
                race = std::make_unique<MixedRace>();
                type = RaceType::Mixed;
                std::cout << "Создана смешанная гонка.\n";
                break;
            default:
                std::cout << "Неверный выбор.\n";
                continue;
        }
        
        std::cout << "Введите дистанцию гонки (км): ";
        double distance;
        std::cin >> distance;
        
        RaceSimulator simulator(std::move(race), distance);
        
        bool raceInProgress = true;
        while (raceInProgress) {
            std::cout << "\n1. Зарегистрировать транспорт\n";
            std::cout << "2. Старт гонки\n";
            std::cout << "> ";
            
            int action;
            std::cin >> action;
            
            if (action == 1) {
                printVehicles();
                std::cout << "Введите название ТС: ";
                std::string vehicleName;
                std::cin.ignore();
                std::getline(std::cin, vehicleName);
                
                auto vehicle = VehicleFactory::createVehicle(vehicleName);
                if (!vehicle) {
                    std::cout << "Ошибка: неизвестное ТС.\n";
                    continue;
                }
                
                if (simulator.registerVehicle(std::move(vehicle))) {
                    std::cout << "ТС '" << vehicleName << "' зарегистрировано!\n";
                } else {
                    std::cout << "Ошибка: ТС '" << vehicleName << "' не соответствует типу гонки или уже зарегистрировано.\n";
                }
            } 
            else if (action == 2) {
                auto results = simulator.startRace();
                if (results.empty()) {
                    std::cout << "Невозможно начать гонку: зарегистрировано меньше 2 ТС.\n";
                    continue;
                }
                
                std::cout << "\n=== РЕЗУЛЬТАТЫ ГОНКИ ===\n";
                for (const auto& [name, time] : results) {
                    std::cout << name << " -> " << time << " часов\n";
                }
                raceInProgress = false;
            }
            else {
                std::cout << "Неверный выбор.\n";
            }
        }
        
        std::cout << "\n1. Провести ещё одну гонку\n";
        std::cout << "2. Выйти\n";
        std::cout << "> ";
        int choice;
        std::cin >> choice;
        if (choice != 1) exitProgram = true;
    }
    
    return 0;
}
