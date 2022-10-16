#ifndef VEC2_HPP
#define VEC2_HPP

#include <iostream>
#include <string>

class Vec2
{
public:
    int x, y;
    Vec2(float x=0, float y=0) : x(x), y(y) {}
    inline Vec2 operator+(const Vec2& v2) const
    {
        return Vec2(x + v2.x, y + v2.y);
    }
    inline Vec2 operator-(const Vec2& v2) const
    {
        return Vec2(x - v2.x, y - v2.y);
    }
    inline Vec2 operator*(const float scalar) const 
    {
        return Vec2(x*scalar, y*scalar);
    }
    void log(std::string msg = "")
    {
        std::cout << "msg" << "(x, y) = (" << x << ", " << y << ")" << std::endl;
    }
private:
};

#endif //VEC2_HPP
