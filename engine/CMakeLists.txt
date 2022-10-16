add_library(
    engine
    core/engine.cpp
    core/engine.hpp
    events/input.cpp
    events/input.hpp
    graphics/texture_manager.cpp
    graphics/texture_manager.hpp
    physics/transform.hpp
    physics/vec2.hpp
    ecs/entity.hpp
    ecs/object.hpp
    ecs/game_object.hpp
)

target_link_libraries(${PROJECT_NAME} SDL2 SDL2_image)