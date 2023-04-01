#ifndef VECTOR3D_H_INCLUDED
#define VECTOR3D_H_INCLUDED

#include <iostream>
#include <cmath>
#include <iomanip>
#include "colors.h"

struct Vector3D
{
    float x, y, z;

    Vector3D() = default;

    Vector3D(float a, float b, float c)
    {
        x = a;
        y = b;
        z = c;
    }

    float& operator[](int i)
    {
        return ((&x)[i]);
    }

    const float& operator[](int i) const
    {
        return ((&x)[i]);
    }

    Vector3D& operator*=(float s)
    {
        x *= s;
        y *= s;
        z *= s;
        return *this;
    }

    Vector3D& operator/=(float s)
    {
        s = 1.0F / s;
        x *= s;
        y *= s;
        z *= s;
    }

};

inline Vector3D operator*(const Vector3D& v, float s)
{
    return Vector3D(v.x * s, v.y * s, v.z * s);
}

inline Vector3D operator/(const Vector3D& v, float s)
{
    s = 1.0F / s;
    return Vector3D(v.x * s, v.y * s, v.z * s);
}

inline Vector3D operator-(const Vector3D& v)
{
    return v * -1;
}

inline Vector3D operator+(const Vector3D& a, const Vector3D& b)
{
    return Vector3D(a.x + b.x, a.y + b.y, a.z + b.z);
}

inline Vector3D operator-(const Vector3D& a, const Vector3D& b)
{
    return Vector3D(a.x - b.x, a.y - b.y, a.z - b.z);
}

inline float vector_3d_magnitude(const Vector3D& v)
{
    return std::sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
}

inline Vector3D vector_3d_normalize(const Vector3D& v)
{
    return v / vector_3d_magnitude(v);
}

// note: a.b = |a|*|b|*cos(O)
// computationally cheap way to determine how much two vectors are
// parallel to each other or perpendicular to each other.
// if a and b are unit vectors then a.b is in the range [-1, 1]
// a.b = largest positive value when a and b are parallel and point in the same direction
// a.b = largest negative value when a and b are parallel but point in the opposite direction
// a.b = 0 when a is perpendicular to b
// a.b > 0 when angle < 90
// a.b < 0 when angle > 90
inline float vector_3d_dot(const Vector3D& a, const Vector3D& b)
{
    return (a.x * b.x + a.y * b.y + a.z * b.z);
}

inline Vector3D vector_3d_cross(const Vector3D& a, const Vector3D& b)
{
    return Vector3D(a.y * b.z - a.z * b.y,
                    a.z * b.x - a.x * b.z,
                    a.x * b.y - a.y * b.x);
}

inline void debug_vector_3d_print(const Vector3D& v)
{
    std::cout << hue::red;
    std::cout << std::setprecision(3) << "|" << std::setw(12) << std::setfill('0') << v.x << "|" << std::endl;
    std::cout << std::setprecision(3) << "|" << std::setw(12) << std::setfill('0') << v.y << "|" << std::endl;
    std::cout << std::setprecision(3) << "|" << std::setw(12) << std::setfill('0') << v.z << "|" << std::endl;
    std::cout << std::endl;
    std::cout << hue::reset;
}

#endif // VECTOR3D_H_INCLUDED
