cmake_minimum_required(VERSION 3.10)

project(AccountSimulation)

# Add source files
add_executable(AccountSimulation
    Account.cpp
    main.cpp
    Utils.cpp
)

# Include header files
target_include_directories(AccountSimulation PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
