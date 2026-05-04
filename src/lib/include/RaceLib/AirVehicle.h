#pragma once
#include "Vehicle.h"
#include <functional>

namespace RaceLib {

class AirVehicle : public Vehicle {
public:
    using ReductionFunction = std::function<double(double)>;
    
    AirVehicle(std::string name, double speed, ReductionFunction reductionFunc);
    [[nodiscard]] double computeTime(double distance) const override;
    [[nodiscard]] bool isGround() const override { return false; }
    [[nodiscard]] bool isAir() const override { return true; }
    [[nodiscard]] std::string getName() const override { return m_name; }

private:
    std::string m_name;
    double m_speed;
    ReductionFunction m_reductionFunc;
};

}
