#ifndef _CUBE
#define _CUBE



#include "header.h"
#include "vec.h"
#include "screen.h"
#include "shape.h"

class cube : public shape
{

public:
    cube(double init_len);
    cube(const shape& source) : shape(source) {};
    ~cube() {};
};

#endif
