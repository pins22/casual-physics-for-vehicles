#include "CpvFunctionCurve2.h"
#include "CpvFunctionCurve3.h"

#include "CpvVector2.h"
#include "CpvVector3.h"

#include <iostream>

int main(int argc, char const *argv[])
{
    cpv::CpvVector2 v2(1, 2);
    cpv::CpvVector2 v1(1, 2);

    const auto v3 = v1 + v2;

    std::cout << v3.getX() << " " << v3.getY() << std::endl;
    return 0;
}
