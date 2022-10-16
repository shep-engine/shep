#ifndef FRIZARD_HPP
#define FRIZARD_HPP

#include <ecs/entity.hpp>
#include <physics/rigidbody.hpp>
#include <SDL2/SDL.h>

class Frizard : public Entity
{
public:
    Frizard(Properties* props);

    void draw();
    void update(float dt);
    void clean();
private:
    int row, frame_count, anim_speed, frame;
    std::string texID;
    SDL_RendererFlip flip;
    RigidBody* rb;
};

#endif //FRIZARD_HPP
