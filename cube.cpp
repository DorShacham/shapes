#include "cube.h"

cube::cube(double init_len)
{
    int hlen = round(init_len / 2);

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

