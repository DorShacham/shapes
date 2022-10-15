#ifndef _TORUS
#define _TORUS



#include "header.h"
#include "vec.h"
#include "screen.h"
#include "shape.h"

class torus : public shape
{

public:
    torus(double R, double r);
    torus(const shape& source) : shape(source) {};
    ~torus() {};
};








#endif