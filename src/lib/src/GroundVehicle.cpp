#include "RaceLib/GroundVehicle.h"
#include <cmath>

namespace RaceLib {

GroundVehicle::GroundVehicle(std::string name, double speed, double moveDuration, std::vector<double> restPattern)
    : m_name(std::move(name)), m_speed(speed), m_moveDuration(moveDuration), m_restPattern(std::move(restPattern)) {}

double GroundVehicle::computeTime(double distance) const {
    double pureTravelTime = distance / m_speed;
    
    if (pureTravelTime <= m_moveDuration) {
        return pureTravelTime;
    }
    
    // Количество полных отрезков движения до отдыха.
    double remainingTime = pureTravelTime;
    int restCount = 0;
    
    remainingTime -= m_moveDuration;
    restCount = 1;
    
    while (remainingTime > m_moveDuration) {
        remainingTime -= m_moveDuration;
        ++restCount;
    }
    
    // Суммирую время отдыха.
    double totalRest = 0.0;
    for (int i = 0; i < restCount; ++i) {
        if (i < m_restPattern.size()) {
            totalRest += m_restPattern[i];
        } else {
            totalRest += m_restPattern.back();
        }
    }
    
    return pureTravelTime + totalRest;
}

}
