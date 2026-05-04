#pragma once
#include "Vehicle.h"
#include <memory>
#include <vector>

namespace RaceLib {

class VehicleFactory {
public:
    static std::vector<std::string> getAllVehicleNames();
    static std::unique_ptr<Vehicle> createVehicle(const std::string& name);
};

}
