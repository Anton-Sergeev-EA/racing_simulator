#pragma once
#include "Race.h"
#include <memory>
#include <vector>

namespace RaceLib {

class RaceSimulator {
public:
    RaceSimulator(std::unique_ptr<Race> race, double distance);
    bool registerVehicle(std::unique_ptr<Vehicle> vehicle);
    std::vector<std::pair<std::string, double>> startRace();
    
private:
    std::unique_ptr<Race> m_race;
    double m_distance;
};

}
