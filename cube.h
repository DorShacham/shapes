#ifndef _CUBE
#define _CUBE
#endif



#include "header.h"
#include "vec.h"
#include "screen.h"

class cube
{
private:
    std::array<std::array<std::array<vec,Z>,Y>,X> &space;
    double len;
    int center_x = round(X / 2);
    int center_y = round(Y / 2);
    int center_z = round(Z / 2);
    vec center = vec(center_x, center_y, center_z);

public:
    cube(double init_len);
    cube(std::array<std::array<std::array<vec,Z>,Y>,X> &space,double len);
    cube(const cube &source);
    cube& operator=(const cube &source);
    ~cube() {delete &space;};
    screen screen_projection() const;
    cube rotate(double degree,axis w) const;
    cube rotateX(double degree) const;
    cube rotateY(double degree) const;
    cube rotateZ(double degree) const;
};

