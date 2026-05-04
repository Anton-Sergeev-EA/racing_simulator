#pragma once
#include "Race.h"

namespace RaceLib {

class GroundRace : public Race {
public:
    bool canRegister(const Vehicle& vehicle) const override;
    RaceType getType() const override { return RaceType::Ground; }
};

}
