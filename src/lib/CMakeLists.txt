project(RaceLib)

add_library(RaceLib SHARED
    src/GroundVehicle.cpp
    src/AirVehicle.cpp
    src/GroundRace.cpp
    src/AirRace.cpp
    src/MixedRace.cpp
    src/RaceSimulator.cpp
    src/VehicleFactory.cpp
    src/Race.cpp
)

target_include_directories(RaceLib 
    PUBLIC 
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
    PRIVATE 
        ${CMAKE_CURRENT_SOURCE_DIR}/src
)

if(WIN32)
    target_compile_definitions(RaceLib PRIVATE RACE_LIB_EXPORTS)
endif()

target_compile_features(RaceLib PUBLIC cxx_std_20)

