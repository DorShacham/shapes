#include "shape.h"

shape::shape() : space(*(new std::array<std::array<std::array<vec, Z>, Y>, X>))
{
   
}


shape::shape(const shape &source) : space(*(new std::array<std::array<std::array<vec, Z>, Y>, X>))
{
    for (int x = 0; x < X; x++)
        for (int y = 0; y < Y; y++)
            for (int z = 0; z < Z; z++)
                space[x][y][z] = source.space[x][y][z];
}
shape &shape::operator=(const shape &source)
{
    for (int x = 0; x < X; x++)
        for (int y = 0; y < Y; y++)
            for (int z = 0; z < Z; z++)
                space[x][y][z] = source.space[x][y][z];
}

screen shape::screen_projection() const
{
    // The screen plain is y-z therfore the normal is (1,0,0)
    vec normal(1, 0, 0);
    screen screen;
    for (int y = 0; y < Y; y++)
        for (int z = 0; z < Z; z++)
        {
            for (int x = X - 1; x >= 0; x--)
            {
                if (!space[x][y][z].is_zero())
                {
                    double product = space[x][y][z] * normal; // may need to divaide by r^2
                    // if((product < 1) && (product > 0))
                    // {
                    //     std::cout << "hello";
                    // }
                   
                    if (product < 0)
                        product = 0;

                    screen.matrix[y][z] = product;
                    screen.max_val = (product > screen.max_val) ? product : screen.max_val;
                   
                    break;
                }
            }
        }
    return screen;
}

shape shape::rotate(double degree, axis w) const
{
    // move shape to center
    shape new_shape;

    for (int x = 0; x < X; x++)
        for (int y = 0; y < Y; y++)
            for (int z = 0; z < Z; z++)
            {
                if (!space[x][y][z].is_zero())
                {
                    vec new_position = (vec(x, y, z) - center).rotate(degree, w) + center;
                    vec new_normal = space[x][y][z].rotate(degree, w);

                    if (new_position.in_space())
                        new_shape.space[round(new_position.array[0])][round(new_position.array[1])][round(new_position.array[2])] = new_normal;
                }
            }
    return new_shape;
}

shape shape::rotateX(double degree) const
{
    return rotate(degree,x);
}
shape shape::rotateY(double degree) const
{
    return rotate(degree,y);
}
shape shape::rotateZ(double degree) const
{
    return rotate(degree,z);
}