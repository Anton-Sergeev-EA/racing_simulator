#include "RaceLib/AirRace.h"

namespace RaceLib {

bool AirRace::canRegister(const Vehicle& vehicle) const {
    return vehicle.isAir();
}

}
