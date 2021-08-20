cmake_minimum_required(VERSION 3.5)

project(05.homework)

add_executable(random_shuffle random_shuffle.cpp)
set_target_properties(random_shuffle PROPERTIES CXX_STANDARD 17 CXX_STANDARD_REQUIRED ON)

add_executable(chrono_example chrono_example.cpp)
set_target_properties(chrono_example PROPERTIES CXX_STANDARD 17 CXX_STANDARD_REQUIRED ON)

add_executable(statistics src/statistics.cpp src/min.cpp include/min.h src/min.cpp include/min.h main.cpp include/statistics.h src/max.cpp include/max.h src/average.cpp include/average.h src/std.cpp include/std.h src/pct.cpp include/pct.h src/pct90.cpp include/pct90.h src/pct95.cpp include/pct95.h)
target_include_directories(statistics PRIVATE include)
set_target_properties(statistics PROPERTIES CXX_STANDARD 17 CXX_STANDARD_REQUIRED ON)

