#include "RaceLib/Race.h"
#include <algorithm>

namespace RaceLib {

void Race::registerVehicle(std::unique_ptr<Vehicle> vehicle) {
    const std::string& name = vehicle->getName();
    if (!m_registeredNames[name]) {
        m_registeredNames[name] = true;
        m_vehicles.push_back(std::move(vehicle));
    }
}

std::vector<std::pair<std::string, double>> Race::runRace(double distance) const {
    std::vector<std::pair<std::string, double>> results;
    results.reserve(m_vehicles.size());
    
    for (const auto& vehicle : m_vehicles) {
        double time = vehicle->computeTime(distance);
        results.emplace_back(vehicle->getName(), time);
    }
    
    std::sort(results.begin(), results.end(),
              [](const auto& a, const auto& b) { return a.second < b.second; });
    
    return results;
}

}
