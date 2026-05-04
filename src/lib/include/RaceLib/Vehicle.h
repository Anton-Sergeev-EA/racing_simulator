#pragma once
#include <string>
#include <memory>

namespace RaceLib {

class Vehicle {
public:
    virtual ~Vehicle() = default;
    [[nodiscard]] virtual std::string getName() const = 0;
    [[nodiscard]] virtual double computeTime(double distance) const = 0;
    [[nodiscard]] virtual bool isGround() const = 0;
    [[nodiscard]] virtual bool isAir() const = 0;
};

}
