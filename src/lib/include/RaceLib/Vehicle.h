#pragma once
#include <string>
#include <memory>
#include "RaceLibExport.h"

namespace RaceLib {

class RACELIB_API Vehicle {
public:
    virtual ~Vehicle() = default;

    [[nodiscard]] virtual std::string getName() const = 0;
    [[nodiscard]] virtual double computeTime(double distance) const = 0;
    [[nodiscard]] virtual bool isGround() const = 0;
    [[nodiscard]] virtual bool isAir() const = 0;
};

}
