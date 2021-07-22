cmake_minimum_required(VERSION 3.5)

project(03.homework)

add_executable(
        game
        main.cpp
        constants.h
        argument.cpp
        argument.h
        game.cpp
        game.h
        constants.cpp
        file_storage.cpp
        file_storage.h
        user_input.cpp
        user_input.h
        records)


set(RESOURCE_FILES
        records
        records)

set_target_properties(game PROPERTIES RESOURCE "${RESOURCE_FILES}")

