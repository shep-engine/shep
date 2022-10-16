#include "engine.hpp"
#include "../events/input.hpp"

Engine* Engine::instance = nullptr;

void Engine::init(int w, int h, const std::string& title)
{
    this->width = w;
    this->height = h;

    if (!SDL_Init(SDL_INIT_EVERYTHING) && !IMG_Init(IMG_INIT_PNG | IMG_INIT_JPG))
    {
        SDL_Log("Failed to init SDL2");
    }

    window = SDL_CreateWindow(
        title.c_str(),
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        w,
        h,
        0
    );

    renderer = SDL_CreateRenderer(
        window, 
        -1, 
        SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC
    );

    if (window == nullptr)
        SDL_Log("Failed to init window");
    if (renderer == nullptr)
        SDL_Log("Failed to init renderer.");

    running = true;
}

void Engine::clear(float r, float g, float b, float a)
{
    SDL_SetRenderDrawColor(renderer, r, g, b, a);
    SDL_RenderClear(renderer);
}

void Engine::render()
{
    SDL_RenderPresent(renderer);
}

void Engine::events()
{
    Input::get_instance()->listen();
}

void Engine::quit()
{
    running = false;
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    IMG_Quit();
    SDL_Quit();
}