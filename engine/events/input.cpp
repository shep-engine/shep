#include "../core/engine.hpp"
#include "input.hpp"

Input* Input::instance = nullptr;

Input::Input()
{
    key_states = SDL_GetKeyboardState(nullptr);
}

void Input::listen()
{
    SDL_Event event;
    while (SDL_PollEvent(&event))
    {
        switch(event.type)
        {
            case SDL_QUIT:
                Engine::get_instance()->quit();
                break;
            case SDL_KEYDOWN:
                key_down();
                break;
            case SDL_KEYUP:
                key_up();
                break;
        }
    }
}

bool Input::get_key_down(SDL_Scancode key)
{
    return (key_states[key] == 1);
}

void Input::key_up()
{
    key_states = SDL_GetKeyboardState(nullptr);
}

void Input::key_down()
{
    key_states = SDL_GetKeyboardState(nullptr);
}