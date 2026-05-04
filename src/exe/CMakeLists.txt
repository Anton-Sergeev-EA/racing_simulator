project(RaceSimulatorExe)

add_executable(RaceSimulator
    main.cpp
)

target_link_libraries(RaceSimulator
    PRIVATE
        RaceLib
)

target_include_directories(RaceSimulator
    PRIVATE
        ${CMAKE_SOURCE_DIR}/src/lib/include
)

target_compile_features(RaceSimulator PUBLIC cxx_std_20)

if(WIN32)
    add_custom_command(TARGET RaceSimulator POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
            $<TARGET_FILE:RaceLib>
            $<TARGET_FILE_DIR:RaceSimulator>
    )
endif()

install(TARGETS RaceSimulator DESTINATION bin)
