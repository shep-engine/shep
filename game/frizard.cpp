#include <SDL2/SDL.h>
#include "frizard.hpp"
#include <graphics/texture_manager.hpp>

Frizard::Frizard(Properties* props) : Entity(props)
{
    row = 0;
    frame_count = 4;
    anim_speed = 200;
    rb = new RigidBody();
}

void Frizard::draw()
{
    TextureManager::get_instance()->draw_frame(texID, transform->x, transform->y, width, height, row, frame, SDL_FLIP_HORIZONTAL);
}

void Frizard::update(float dt)
{
    // rb->update(1);
    transform->translate_x(rb->get_pos().x);
    transform->translate_y(rb->get_pos().y);
    frame = (SDL_GetTicks()/anim_speed) % frame_count;
}

void Frizard::clean()
{
    TextureManager::get_instance()->clean();
}