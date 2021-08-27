cmake_minimum_required(VERSION 3.5)

project(05.homework)

add_executable(random_shuffle random_shuffle.cpp)
set_target_properties(random_shuffle PROPERTIES CXX_STANDARD 17 CXX_STANDARD_REQUIRED ON)

add_executable(chrono_example chrono_example.cpp)
set_target_properties(chrono_example PROPERTIES CXX_STANDARD 17 CXX_STANDARD_REQUIRED ON)

add_executable(statistics
               main.cpp
               src/statistics.cpp
               src/min.cpp
               src/min.cpp
               src/max.cpp
               src/average.cpp
               src/std.cpp
               src/pct.cpp
               src/pct90.cpp
               src/pct95.cpp
               src/statistic_base.cpp)
target_include_directories(statistics PRIVATE include)
set_target_properties(statistics PROPERTIES CXX_STANDARD 17 CXX_STANDARD_REQUIRED ON)

