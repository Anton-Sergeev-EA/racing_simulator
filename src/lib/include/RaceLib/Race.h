#pragma once
#include "Vehicle.h"
#include "RaceLibExport.h"
#include <memory>
#include <vector>
#include <unordered_map>
#include <string>

namespace RaceLib {

enum class RaceType { Ground, Air, Mixed };

class RACELIB_API Race {
public:
    virtual ~Race() = default;
    virtual bool canRegister(const Vehicle& vehicle) const = 0;
    virtual RaceType getType() const = 0;
    
    void registerVehicle(std::unique_ptr<Vehicle> vehicle);
    std::vector<std::pair<std::string, double>> runRace(double distance) const;
    
protected:
    std::vector<std::unique_ptr<Vehicle>> m_vehicles;
    std::unordered_map<std::string, bool> m_registeredNames;
};

}
