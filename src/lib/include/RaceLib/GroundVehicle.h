#pragma once
#include "Vehicle.h"
#include <vector>

namespace RaceLib {

class GroundVehicle : public Vehicle {
public:
    GroundVehicle(std::string name, double speed, double moveDuration, std::vector<double> restPattern);
    [[nodiscard]] double computeTime(double distance) const override;
    [[nodiscard]] bool isGround() const override { return true; }
    [[nodiscard]] bool isAir() const override { return false; }
    [[nodiscard]] std::string getName() const override { return m_name; }

private:
    std::string m_name;
    double m_speed;
    double m_moveDuration;
    std::vector<double> m_restPattern;
};

}
