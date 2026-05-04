#include "RaceLib/GroundRace.h"

namespace RaceLib {

bool GroundRace::canRegister(const Vehicle& vehicle) const {
    return vehicle.isGround();
}

}
