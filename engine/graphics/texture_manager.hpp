#ifndef TEXTURE_MANAGER_HPP
#define TEXTURE_MANAGER_HPP

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>
#include <iostream>
#include <map>

class TextureManager
{
public:
    static TextureManager* get_instance()
    {
        return instance = (instance != nullptr) ? instance : new TextureManager(); 
    }

    bool load_tex(std::string id, std::string filename);
    void drop(std::string id);
    void draw(std::string id, int x, int y, int width, int height, SDL_RendererFlip flip=SDL_FLIP_NONE);
    void draw_frame(std::string id, int x, int y, int w, int h, int row, int frame, SDL_RendererFlip flip=SDL_FLIP_NONE);
    void clean();
private:
    TextureManager() {}
    std::map<std::string, SDL_Texture*> texMap;
    static TextureManager* instance;
};

#endif //TEXTURE_MANAGER_HPP
