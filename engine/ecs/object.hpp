#ifndef OBJECT_HPP
#define OBJECT_HPP

class Object
{
public:
    virtual void draw()=0;
    virtual void update(float dt)=0;
    virtual void clean()=0;
};

#endif //OBJECT_HPP
