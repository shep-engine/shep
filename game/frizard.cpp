#include "frizard.hpp"
#include <graphics/texture_manager.hpp>
#include <SDL2/SDL.h>
#include <events/input.hpp>

Frizard::Frizard(Properties* props) : Entity(props)
{
    row = 0;
    frame_count = 4;
    anim_speed = 150;
    flip = SDL_FLIP_NONE;
    texID = "frizard_idle";
    rb = new RigidBody();
}

void Frizard::draw()
{
    TextureManager::get_instance()->draw_frame(texID, transform->x, transform->y, width, height, row, frame, flip);
}

void Frizard::update(float dt)
{
    rb->update(1);
    if (Input::get_instance()->get_key_down(SDL_SCANCODE_A))
    {
        rb->apply_force_x(2*BACKWARD);
        texID = "frizard_run";
        frame_count = 6;
        anim_speed = 100;
        flip = SDL_FLIP_NONE;
    }
    else if (Input::get_instance()->get_key_down(SDL_SCANCODE_D))
    {
        rb->apply_force_x(2*FORWARD);
        texID = "frizard_run";
        frame_count = 6;
        anim_speed = 100;
        flip = SDL_FLIP_HORIZONTAL;
    }
    else
    {
        texID = "frizard_idle";
        frame_count = 4;
        anim_speed = 150;
        rb->apply_force_x(0);
    }

    transform->translate_x(rb->get_pos().x);
    // transform->translate_y(rb->get_pos().y);
    frame = (SDL_GetTicks()/anim_speed) % frame_count;
}

void Frizard::clean()
{
    TextureManager::get_instance()->clean();
}