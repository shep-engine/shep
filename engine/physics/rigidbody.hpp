#ifndef RIGIDBODY_HPP
#define RIGIDBODY_HPP

#include "vec2.hpp"

#define UNIT_MASS 1.0f
#define GRAVITY 9.8f

#define FORWARD 1
#define BACKWARD -1
#define UPWARD 1
#define DOWNWARD -1

class RigidBody
{
public:
    RigidBody() {
        mass = UNIT_MASS;
        gravity = GRAVITY;
    };

    inline void set_mass(float m) {mass = m;} 
    inline void set_gravity(float g) {gravity = g;}
    inline void apply_force(Vec2 f) {force = f;}
    inline void apply_force_x(float x) {force.x = x;}
    inline void apply_force_y(float y) {force.y = y;}
    inline void unset_force() {force = Vec2(0, 0);}
    inline void apply_friction(Vec2 f){friction = f;}
    inline void unset_friction(){friction = Vec2(0,0);}

    inline float get_mass(){return mass;}
    inline Vec2 get_pos(){return position;}
    inline Vec2 get_vel(){return velocity;}
    inline Vec2 get_accel(){return acceleration;}
    

    void update(float dt) {
        acceleration.x = (force.x + friction.x)/mass;
        acceleration.y = gravity + force.y/mass;
        velocity = acceleration*dt;
        position = velocity*dt;
    }

private:
    float mass;
    float gravity;

    Vec2 force;
    Vec2 friction;
    Vec2 position;
    Vec2 velocity;
    Vec2 acceleration;
};

#endif //RIGIDBODY_HPP
