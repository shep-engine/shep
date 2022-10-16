cmake_minimum_required(VERSION 3.22.1)

project(shep)

add_executable(
    ${PROJECT_NAME}
    main.cpp
    game/frizard.cpp
    game/frizard.hpp
    game/game.cpp
    game/game.hpp
)

add_subdirectory(engine)

target_include_directories(${PROJECT_NAME} PRIVATE engine/)
target_link_directories(${PROJECT_NAME} PRIVATE engine/)
target_link_libraries(${PROJECT_NAME} engine SDL2 SDL2_image)