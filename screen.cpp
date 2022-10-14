#include "screen.h"

using namespace std;
class screen;


screen::screen() : matrix(*(new std::array<std::array<double,Z>,Y>)) 
{
    for (int y = 0; y < Y; y++)
            for (int z = 0; z < Z; z++)
                matrix[y][z] = 0;
}

screen::screen(const screen& source) : matrix(*(new std::array<std::array<double, Z>, Y>))
 {
    for (int y = 0; y < Y; y++)
            for (int z = 0; z < Z; z++)
                matrix[y][z] = source.matrix[y][z];
 }
screen& screen::operator=(const screen& source) 
 {
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
    // moving the cursor to the beginning of the screen
    char commant_str[BUFFER] = {0};
    sprintf(commant_str, "echo -en \"\033[%dA\033[%dD\"",Z+1,Y);
    system(commant_str);
    for (int z = 0; z < Z; z++)
    {
        for (int y = 0; y < Y; y++)
        {
            cout << bright2char(matrix[y][z]) << ' ';
        }
        cout << endl;
    }
}