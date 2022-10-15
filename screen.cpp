#include "screen.h"

using namespace std;
class screen;

screen::screen() : matrix(*(new std::array<std::array<double, Z>, Y>))
{
    for (int y = 0; y < Y; y++)
        for (int z = 0; z < Z; z++)
            matrix[y][z] = 0;
}

screen::screen(const screen &source) : matrix(*(new std::array<std::array<double, Z>, Y>))
{
    max_val = source.max_val;
    for (int y = 0; y < Y; y++)
        for (int z = 0; z < Z; z++)
            matrix[y][z] = source.matrix[y][z];
}
screen &screen::operator=(const screen &source)
{
    max_val = source.max_val;
    for (int y = 0; y < Y; y++)
        for (int z = 0; z < Z; z++)
            matrix[y][z] = source.matrix[y][z];
}

char screen::bright2char(double bright) const
{
    double nominal_val = max_val ? bright / max_val * (SYMBOL - 1) : 0;
    return symbol_table[int(round(nominal_val))];
}

void screen::show() const
{
    char *print_string = new char[Y * Z * 4];
    int counter = 0;
    // moving the cursor to the beginning of the screen
    printf("\033[%dA\033[%dD", Z + 5, Y);
    for (int z = 0; z < Z; z++)
    {
        for (int y = 0; y < Y; y++)
        {
            counter += sprintf(print_string + counter, "%c ", bright2char(matrix[y][z]));
        }
        counter += sprintf(print_string + counter, "\n");
    }
    printf("%s", print_string);
    delete[] print_string;
}

screen screen::smooth() const
{
    screen smooth_screen;
    int r = 1; // smooth radius
    double local_sum = 0;
    for (int y = r; y < Y - r; y++)
        for (int z = r; z < Z - r; z++)
        {
            local_sum = 0;
            for (int i = y - r; i <= y + r; i++)
                for (int j = z - r; j <= z + r; j++)
                    local_sum += matrix[i][j];
            smooth_screen.matrix[y][z] = local_sum / ((1 + 2 * r) * (1 + 2 * r));
            smooth_screen.max_val = (smooth_screen.matrix[y][z] > smooth_screen.max_val) ? smooth_screen.matrix[y][z] : smooth_screen.max_val;
        }
    return smooth_screen;
}

screen screen::continues() const
{
    screen smooth_screen(*this);
    int r = 1; // smooth radius
    double local_sum = 0;
    for (int y = r; y < Y - r; y++)
        for (int z = r; z < Z - r; z++)
        {
            if ((matrix[y-r][z] == matrix[y+r][z]) && (matrix[y][z+r] == matrix[y][z-r] && (matrix[y-r][z] == matrix[y][z+r])))
                smooth_screen.matrix[y][z] = matrix[y-r][z];
        }
        return smooth_screen;
}