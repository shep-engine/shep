#ifndef ENTITY_HPP
#define ENTITY_HPP

#include "game_object.hpp"

class Entity : public GameObject
{
public:
    Entity(Properties* props) : GameObject(props) {}

    virtual void draw()=0;
    virtual void update(float dt)=0;
    virtual void clean()=0;    
};

#endif //ENTITY_HPP
