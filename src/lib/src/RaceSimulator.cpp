#include "RaceLib/RaceSimulator.h"

namespace RaceLib {

RaceSimulator::RaceSimulator(std::unique_ptr<Race> race, double distance)
    : m_race(std::move(race)), m_distance(distance) {}

bool RaceSimulator::registerVehicle(std::unique_ptr<Vehicle> vehicle) {
    if (!m_race->canRegister(*vehicle)) {
        return false;
    }
    m_race->registerVehicle(std::move(vehicle));
    return true;
}

std::vector<std::pair<std::string, double>> RaceSimulator::startRace() {
    if (m_race->m_vehicles.size() < 2) {
        return {};
    }
    return m_race->runRace(m_distance);
}

}
