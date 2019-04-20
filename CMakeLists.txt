cmake_minimum_required(VERSION 2.8)

project(Strategy)
SET(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_STANDARD 17)
add_executable(${PROJECT_NAME} "main.cpp""strategy.cpp""tankbattle""consoleusing.cpp""weapons.h""weapons.cpp""armor.h""armor.cpp""gun.h""gun.cpp"
    "panzer.h""panzer.cpp")
