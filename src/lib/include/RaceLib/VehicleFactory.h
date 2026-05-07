#pragma once
#include "Vehicle.h"
#include "RaceLibExport.h"
#include <memory>
#include <vector>
#include <string>

namespace RaceLib {

class RACELIB_API VehicleFactory {
public:
    static std::vector<std::string> getAllVehicleNames();
    static std::unique_ptr<Vehicle> createVehicle(const std::string& name);
};

}
