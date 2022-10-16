#ifndef ENGINE_HPP
#define ENGINE_HPP

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>

class Engine 
{
public:
    static Engine* get_instance(){
        return instance = (instance != nullptr) ? instance : new Engine();
    }

    void init(int w, int h, const std::string& title);
    void clear(float r, float g, float b, float a);
    void render();
    void events();
    void quit();

    inline bool isRunning(){return running;}
    inline SDL_Renderer* getRenderer(){return renderer;}
private:
    Engine(){}
    bool running;

    SDL_Window* window;
    SDL_Renderer* renderer;
    static Engine* instance;
    int width, height;
};

#endif // ENGINE_HPP