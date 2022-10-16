#ifndef GAME_OBJECT_HPP
#define GAME_OBJECT_HPP

#include "object.hpp"
#include "../physics/transform.hpp"

struct Properties
{
public:
    Properties(int x, int y, int w, int h) {
        this->x = x;
        this->y = y;
        this->width = w;
        this->height = h;
    }

public:
    int width, height;
    float x, y;
};

class GameObject : public Object
{
public:
    GameObject(Properties* props) 
    : 
    width(props->width),
    height(props->height) 
    {
        transform = new Transform(props->x, props->y);
    }

    virtual void draw()=0;
    virtual void update(float dt)=0;
    virtual void clean()=0;
protected:
    Transform* transform;
    int width, height;
};

#endif //GAME_OBJECT_HPP
