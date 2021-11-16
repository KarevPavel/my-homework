cmake_minimum_required(VERSION 3.5)

project(homework_6)

add_executable(homework_6 main.cpp list.hpp container.hpp)

set_target_properties(homework_6 PROPERTIES
        CXX_STANDARD 17
        CXX_STANDARD_REQUIRED ON
)