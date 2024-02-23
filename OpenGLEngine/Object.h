#pragma once
#include "../Maths/Matrix4x4.h"
#include "../Maths/Vector3.h"

class Object
{
public:
    Vector3 position{0, 0, 0};
    Vector3 rotation{ 0, 0, 0 };
    Vector3 scale{ 1, 1, 1};

    virtual void Update()
    {
        
    }

    Matrix4x4 calculateModelMatrix()
    {
        return Matrix4x4::Translation(position) * Matrix4x4::Rotation(rotation) * Matrix4x4::Scale(scale);
    }
};