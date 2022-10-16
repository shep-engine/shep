#ifndef GAME_HPP
#define GAME_HPP

#include <iostream>
#include <core/engine.hpp>
#include <graphics/texture_manager.hpp> 
#include "frizard.hpp"

class Game
{
public:
    Game(int w, int h, const std::string& title);
    void run();
    ~Game();
private:
    void update(float dt);
    void render();
private:
    Frizard* frizard;
};

#endif //GAME_HPP