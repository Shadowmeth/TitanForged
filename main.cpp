#include <iostream>
#include "/include/vector3d.h"
#include "/include/matrix3d.h"

int main()
{
    Vector3D v1(5, 15, 20);
    Vector3D v2(9, 0, 3);
    Vector3D v3(6, 4, 2);
    Matrix3D M1(v1, v2, v3);

    debug_matrix_3d_print(M1);
    v1 = vector_3d_normalize(v2);
    debug_vector_3d_print(v1);

}
