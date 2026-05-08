#pragma once
#include "Race.h"
#include "RaceLibExport.h"

namespace RaceLib {

class RACELIB_API GroundRace : public Race {
public:
    bool canRegister(const Vehicle& vehicle) const override;
    RaceType getType() const override { return RaceType::Ground; }
};

}
