#include "RaceLib/VehicleFactory.h"
#include "RaceLib/GroundVehicle.h"
#include "RaceLib/AirVehicle.h"
#include <cmath>

namespace RaceLib {

std::vector<std::string> VehicleFactory::getAllVehicleNames() {
    return {"Верблюд", "Верблюд-быстроход", "Кентавр", "Ботинки-вездеходы",
            "Ковёр-самолёт", "Орёл", "Метла"};
}

std::unique_ptr<Vehicle> VehicleFactory::createVehicle(const std::string& name) {
    if (name == "Верблюд") {
        return std::make_unique<GroundVehicle>("Верблюд", 10.0, 30.0, std::vector<double>{5.0, 8.0});
    }
    if (name == "Верблюд-быстроход") {
        return std::make_unique<GroundVehicle>("Верблюд-быстроход", 40.0, 10.0, std::vector<double>{5.0, 6.5, 8.0});
    }
    if (name == "Кентавр") {
        return std::make_unique<GroundVehicle>("Кентавр", 15.0, 8.0, std::vector<double>{2.0});
    }
    if (name == "Ботинки-вездеходы") {
        return std::make_unique<GroundVehicle>("Ботинки-вездеходы", 6.0, 60.0, std::vector<double>{10.0, 5.0});
    }
    if (name == "Ковёр-самолёт") {
        return std::make_unique<AirVehicle>("Ковёр-самолёт", 10.0,
            [](double dist) -> double {
                if (dist < 1000) return 0.0;
                if (dist < 5000) return 3.0;
                if (dist < 10000) return 10.0;
                return 5.0;
            });
    }
    if (name == "Орёл") {
        return std::make_unique<AirVehicle>("Орёл", 8.0, [](double) { return 6.0; });
    }
    if (name == "Метла") {
        return std::make_unique<AirVehicle>("Метла", 20.0,
            [](double dist) { return std::floor(dist / 1000.0); });
    }
    return nullptr;
}

}
