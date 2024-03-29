#pragma once
#include <corecrt_math.h>
class Vector3
{
public:
    float x, y, z;
    Vector3(float x, float y, float z) : x{ x }, y{ y }, z{ z } { }

    bool operator==(const Vector3& other) const {
        return x == other.x && y == other.y && z == other.z;
    }

    bool operator!=(const Vector3& other) const {
        return !(*this == other);
    }

    Vector3 operator-() const {
        return Vector3(-x, -y, -z);
    }

    Vector3 operator*(float a) const {
        return Vector3(x * a, y * a, z * a);
    }

    Vector3 operator/(float a) const {
        return Vector3(x / a, y / a, z / a);
    }

    Vector3 operator+(const Vector3& other) const {
        return Vector3(x + other.x, y + other.y, z + other.z);
    }

    Vector3 operator-(const Vector3& other) const {
        return Vector3(x - other.x, y - other.y, z - other.z);
    }

    float Magnitude() const {
        return sqrt(x * x + y * y + z * z);
    }


    Vector3 Normalize() const {
        return Vector3(x, y, z) / Magnitude();
    }

    float SquareMagnitude() const {
        return sqrt(sqrt(x * x + y * y + z * z));
    }

    static float DotProduct(Vector3& vec1, Vector3& vec2) {
        return vec1.x * vec2.x + vec1.y * vec2.y + vec1.z * vec2.z;
    }
};