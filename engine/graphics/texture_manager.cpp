#include "texture_manager.hpp"
#include "../core/engine.hpp"

TextureManager* TextureManager::instance = nullptr;

bool TextureManager::load_tex(std::string id, std::string filename)
{
    SDL_Surface* surface = IMG_Load(filename.c_str());
    if (surface == nullptr)
    {
        std::cout << "Failed to load texture " << filename << SDL_GetError() << std::endl;
        return false;
    }

    SDL_Texture* tex = SDL_CreateTextureFromSurface(Engine::get_instance()->getRenderer(), surface);
    if (tex == nullptr)
    {
        std::cout << "Failed to create texture from surface" << SDL_GetError() << std::endl;
        return false;
    }

    texMap[id] = tex;
    return true;
}

void TextureManager::draw(std::string id, int x, int y, int width, int height, SDL_RendererFlip flip)
{
    SDL_Rect src = {0, 0, width, height};
    SDL_Rect dst = {x, y, width, height};
    SDL_RenderCopyEx(Engine::get_instance()->getRenderer(), texMap[id], &src, &dst, 0, nullptr, flip);
}

void TextureManager::draw_frame(std::string id, int x, int y, int w, int h, int row, int frame, SDL_RendererFlip flip)
{
    SDL_Rect src = {w*frame, h*row, w, h};
    SDL_Rect dst = {x, y, w, h};
    SDL_RenderCopyEx(Engine::get_instance()->getRenderer(), texMap[id], &src, &dst, 0, nullptr, flip);
}

void TextureManager::drop(std::string id)
{
    SDL_DestroyTexture(texMap[id]);
    texMap.erase(id);
}

void TextureManager::clean()
{
    std::map<std::string, SDL_Texture*>::iterator it;
    for (it = texMap.begin(); it != texMap.end(); it++)
        SDL_DestroyTexture(it->second);
    
    texMap.clear();
    std::cout << "INFO: Texture Map Cleaned" << std::endl;
}