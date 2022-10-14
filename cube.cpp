#include "cube.h"

cube::cube(double init_len) : space(*(new std::array<std::array<std::array<vec, Z>, Y>, X>))
{
    len = init_len;
    int hlen = round(len / 2);
    int center_x = round(X / 2);
    int center_y = round(Y / 2);
    int center_z = round(Z / 2);
    center = vec(center_x, center_y, center_z);

    // upper side
    do
    {
        double normal_array[3] = {0, 0, 1};
        vec normal(normal_array);
        int z = center_z + hlen;
        for (int x = center_x - hlen; x < center_x + hlen; x++)
            for (int y = center_y - hlen; y < center_y + hlen; y++)
                space[x][y][z] = normal;
    } while (0);

    // lower side
    do
    {
        double normal_array[3] = {0, 0, -1};
        vec normal(normal_array);
        int z = center_z - hlen;
        for (int x = center_x - hlen; x < center_x + hlen; x++)
            for (int y = center_y - hlen; y < center_y + hlen; y++)
                space[x][y][z] = normal;
    } while (0);

    // right side
    do
    {
        double normal_array[3] = {0, 1, 0};
        vec normal(normal_array);
        int y = center_y + hlen;
        for (int x = center_x - hlen; x < center_x + hlen; x++)
            for (int z = center_z - hlen; z < center_z + hlen; z++)
                space[x][y][z] = normal;
    } while (0);

    // left side
    do
    {
        double normal_array[3] = {0, -1, 0};
        vec normal(normal_array);
        int y = center_y - hlen;
        for (int x = center_x - hlen; x < center_x + hlen; x++)
            for (int z = center_z - hlen; z < center_z + hlen; z++)
                space[x][y][z] = normal;
    } while (0);

    // front side
    do
    {
        double normal_array[3] = {1, 0, 0};
        vec normal(normal_array);
        int x = center_x + hlen;
        for (int y = center_y - hlen; y < center_y + hlen; y++)
            for (int z = center_z - hlen; z < center_z + hlen; z++)
                space[x][y][z] = normal;
    } while (0);

    // back side
    do
    {
        double normal_array[3] = {-1, 0, 0};
        vec normal(normal_array);
        int x = center_x - hlen;
        for (int y = center_y - hlen; y < center_y + hlen; y++)
            for (int z = center_z - hlen; z < center_z + hlen; z++)
                space[x][y][z] = normal;
    } while (0);
}

cube::cube(std::array<std::array<std::array<vec, Z>, Y>, X> &space, double len) : space(space), len(len)
{
}

cube::cube(const cube &source) : space(*(new std::array<std::array<std::array<vec, Z>, Y>, X>))
{
    len = source.len;
    for (int x = 0; x < X; x++)
        for (int y = 0; y < Y; y++)
            for (int z = 0; z < Z; z++)
                space[x][y][z] = source.space[x][y][z];
}
cube &cube::operator=(const cube &source)
{
    len = source.len;
    for (int x = 0; x < X; x++)
        for (int y = 0; y < Y; y++)
            for (int z = 0; z < Z; z++)
                space[x][y][z] = source.space[x][y][z];
}

screen cube::screen_projection() const
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

cube cube::rotate(double degree, axis w) const
{
    // move cube to center
    std::array<std::array<std::array<vec, Z>, Y>, X> &new_space = *new std::array<std::array<std::array<vec, Z>, Y>, X>;

    for (int x = 0; x < X; x++)
        for (int y = 0; y < Y; y++)
            for (int z = 0; z < Z; z++)
            {
                if (!space[x][y][z].is_zero())
                {
                    vec new_position = (vec(x, y, z) - center).rotate(degree, w) + center;
                    vec new_normal = space[x][y][z].rotate(degree, w);

                    if (new_position.in_space())
                        new_space[round(new_position.array[0])][round(new_position.array[1])][round(new_position.array[2])] = new_normal;
                }
            }
    return cube(new_space,len);
}

cube cube::rotateX(double degree) const
{
    return rotate(degree,x);
}
cube cube::rotateY(double degree) const
{
    return rotate(degree,y);
}
cube cube::rotateZ(double degree) const
{
    return rotate(degree,z);
}