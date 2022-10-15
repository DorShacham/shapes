#ifndef _SHAPE
#define _SHAPE
#endif



#include "header.h"
#include "vec.h"
#include "screen.h"

class shape
{
private:
    std::array<std::array<std::array<vec,Z>,Y>,X> &space;
    int center_x = round(X / 2);
    int center_y = round(Y / 2);
    int center_z = round(Z / 2);
    vec center = vec(center_x, center_y, center_z);

public:
    shape();
    shape(std::array<std::array<std::array<vec,Z>,Y>,X> &space);
    shape(const shape &source);
    shape& operator=(const shape &source);
    ~shape() {delete &space;};
    screen screen_projection() const;
    shape rotate(double degree,axis w) const;
    shape rotateX(double degree) const;
    shape rotateY(double degree) const;
    shape rotateZ(double degree) const;
};

