#ifndef _SCREEN
#define _SCREEN
#endif

#include "header.h"


class screen
{
    public:
    std::array<std::array<double,Z>,Y> &matrix;
    screen();
    screen(const screen& source);
    screen& operator=(const screen& source);
    ~screen() {delete &matrix;}
    double max_val=0;
    double min_val=0;
    char symbol_table[SYMBOL] = {'.',',','-','~',':',';','=','!','*','#','$','@'};
    void show() const;
    char bright2char(double bright) const;
    screen smooth() const;
};