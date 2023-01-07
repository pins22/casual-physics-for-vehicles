#include "common.h"
#include "core/Vector3.h"

extern "C"
{
    DLL_EXPORT cpv::Vector3 *Vector3_new()
    {
        return new cpv::Vector3();
    }

    DLL_EXPORT cpv::Vector3 *Vector3_newData(double x, double y, double z)
    {
        return new cpv::Vector3(x, y, z);
    }

    DLL_EXPORT void Vector3_delete(cpv::Vector3 *vector3)
    {
        delete vector3;
    }

    DLL_EXPORT double Vector3_getX(cpv::Vector3 *vector3)
    {
        if (vector3)
        {
            return vector3->getX();
        }

        return 0.0;
    }

    DLL_EXPORT double Vector3_getY(cpv::Vector3 *vector3)
    {
        if (vector3)
        {
            return vector3->getY();
        }

        return 0.0;
    }

    DLL_EXPORT double Vector3_getZ(cpv::Vector3 *vector3)
    {
        if (vector3)
        {
            return vector3->getZ();
        }

        return 0.0;
    }

    DLL_EXPORT void Vector3_setX(cpv::Vector3 *vector3, double x)
    {
        if (vector3)
        {
            vector3->setX(x);
        }
    }

    DLL_EXPORT void Vector3_setY(cpv::Vector3 *vector3, double y)
    {
        if (vector3)
        {
            vector3->setY(y);
        }
    }

    DLL_EXPORT void Vector3_setZ(cpv::Vector3 *vector3, double z)
    {
        if (vector3)
        {
            vector3->setZ(z);
        }
    }

    DLL_EXPORT double Vector3_getMagnitude(cpv::Vector3 *vector3)
    {
        if (vector3)
        {
            return vector3->getMagnitude();
        }

        return 0.0;
    }

    DLL_EXPORT cpv::Vector3 *Vector3_add(cpv::Vector3 *vector3, cpv::Vector3 *other)
    {
        if (vector3 && other)
        {
            return new cpv::Vector3(*vector3 + *other);
        }

        return nullptr;
    }

    DLL_EXPORT cpv::Vector3 *Vector3_subtract(cpv::Vector3 *vector3, cpv::Vector3 *other)
    {
        if (vector3 && other)
        {
            return new cpv::Vector3(*vector3 - *other);
        }

        return nullptr;
    }

    DLL_EXPORT cpv::Vector3 *Vector3_multiply(cpv::Vector3 *vector3, double scalar)
    {
        if (vector3)
        {
            return new cpv::Vector3(*vector3 * scalar);
        }

        return nullptr;
    }

    DLL_EXPORT bool Vector3_equals(cpv::Vector3 *vector3, cpv::Vector3 *other)
    {
        if (vector3 && other)
        {
            return *vector3 == *other;
        }

        return false;
    }
}
