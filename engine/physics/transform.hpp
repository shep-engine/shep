#ifndef TRANSFORM_HPP
#define TRANSFORM_HPP

#include "vec2.hpp"

class Transform
{
public:
    float x, y;
    Transform(float x=0, float y=0) : x(x), y(y) {}

    void log(std::string msg = "")
    {
        std::cout << "msg" << "(x, y) = (" << x << ", " << y << ")" << std::endl;
    }
public:
    inline void translate_x(float x) {this->x += x;}
    inline void translate_y(float y) {this->y += y;}
    inline void translate(Vec2 v) {this->x += v.x; this->y += v.y;}
};

#endif //TRANSFORM_HPP
