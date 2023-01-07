#include "common.h"
#include "core/Vector2.h"

extern "C"
{
    DLL_EXPORT cpv::Vector2 *Vector2_new()
    {
        return new cpv::Vector2();
    }

    DLL_EXPORT cpv::Vector2 *Vector2_newData(double x, double y)
    {
        return new cpv::Vector2(x, y);
    }

    DLL_EXPORT void Vector2_delete(cpv::Vector2 *vector2)
    {
        delete vector2;
    }

    DLL_EXPORT double Vector2_getX(cpv::Vector2 *vector2)
    {
        if (vector2)
        {
            return vector2->getX();
        }

        return 0.0;
    }

    DLL_EXPORT double Vector2_getY(cpv::Vector2 *vector2)
    {
        if (vector2)
        {
            return vector2->getY();
        }

        return 0.0;
    }

    DLL_EXPORT void Vector2_setX(cpv::Vector2 *vector2, double x)
    {
        if (vector2)
        {
            vector2->setX(x);
        }
    }

    DLL_EXPORT void Vector2_setY(cpv::Vector2 *vector2, double y)
    {
        if (vector2)
        {
            vector2->setY(y);
        }
    }

    DLL_EXPORT double Vector2_getMagnitude(cpv::Vector2 *vector2)
    {
        if (vector2)
        {
            return vector2->getMagnitude();
        }

        return 0.0;
    }

    DLL_EXPORT cpv::Vector2 *Vector2_add(cpv::Vector2 *vector2, cpv::Vector2 *other)
    {
        if (vector2 && other)
        {
            return new cpv::Vector2(*vector2 + *other);
        }

        return nullptr;
    }

    DLL_EXPORT cpv::Vector2 *Vector2_subtract(cpv::Vector2 *vector2, cpv::Vector2 *other)
    {
        if (vector2 && other)
        {
            return new cpv::Vector2(*vector2 - *other);
        }

        return nullptr;
    }

    DLL_EXPORT cpv::Vector2 *Vector2_multiply(cpv::Vector2 *vector2, double scalar)
    {
        if (vector2)
        {
            return new cpv::Vector2(*vector2 * scalar);
        }

        return nullptr;
    }

    DLL_EXPORT bool Vector2_equals(cpv::Vector2 *vector2, cpv::Vector2 *other)
    {
        if (vector2 && other)
        {
            return *vector2 == *other;
        }

        return false;
    }

    DLL_EXPORT bool Vector2_notEquals(cpv::Vector2 *vector2, cpv::Vector2 *other)
    {
        if (vector2 && other)
        {
            return *vector2 != *other;
        }

        return false;
    }
}
