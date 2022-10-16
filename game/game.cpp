#include "game.hpp"
#include <events/input.hpp>

Game::Game(int w, int h, const std::string& title)
{
    Engine::get_instance()->init(w,h,title);
    TextureManager::get_instance()->load_tex("frizard", "../res/frizard_idle.png");

    frizard = new Frizard(new Properties("frizard", 100, 200, 124, 124));
}

void Game::run()
{
    while (Engine::get_instance()->isRunning())
    {
        Engine::get_instance()->clear(124, 228, 254, 255);
        Engine::get_instance()->events();
        update(0);
        render();
        Engine::get_instance()->render();
    }
}

void Game::update(float dt)
{
    frizard->update(dt);
}

void Game::render()
{
    frizard->draw();
}

Game::~Game()
{
    TextureManager::get_instance()->clean();
    frizard->clean();
}