#include "RaceLib/AirVehicle.h"

namespace RaceLib {

AirVehicle::AirVehicle(std::string name, double speed, ReductionFunction reductionFunc)
    : m_name(std::move(name)), m_speed(speed), m_reductionFunc(std::move(reductionFunc)) {}

double AirVehicle::computeTime(double distance) const {
    double reduction = m_reductionFunc(distance);
    double effectiveDistance = distance * (1.0 - reduction / 100.0);
    return effectiveDistance / m_speed;
}

}
