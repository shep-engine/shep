#ifndef FRIZARD_HPP
#define FRIZARD_HPP

#include <ecs/entity.hpp>
#include <physics/rigidbody.hpp>

class Frizard : public Entity
{
public:
    Frizard(Properties* props);

    void draw();
    void update(float dt);
    void clean();
private:
    int row, frame_count, anim_speed, frame;
    RigidBody* rb;
};

#endif //FRIZARD_HPP
