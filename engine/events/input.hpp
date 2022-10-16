#ifndef INPUT_HPP
#define INPUT_HPP

#include <SDL2/SDL.h>

class Input
{
public:
    static Input* get_instance()
    {
        return instance = (instance != nullptr) ? instance : new Input();
    }

    void listen();
    bool get_key_down(SDL_Scancode key);

private:
    Input();
    void key_up();
    void key_down();

    const Uint8* key_states;

    static Input* instance;
};


#endif //INPUT_HPP
