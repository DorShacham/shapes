#ifndef _VEC
#define _VEC

#include "header.h"

enum axis
{
    x,
    y,
    z
};

class vec{
    public:
    std::array<double,D> &array;
    vec() : array(*(new std::array<double,D>)){};
    vec(double *init);
    vec(double x, double, double z);
    vec(const vec& second_vec);
    vec& operator=(const vec& second_vec);
    ~vec() {delete &array;};
    bool is_zero();
    double operator*(const vec& second_vec);
    vec operator+(const vec& second_vec);
    vec operator-(const vec& second_vec);
    vec operator*(const double scaler);
    vec mult_matrix(const std::array<std::array<double,D>,D> &matrix) const;
    vec rotate(double degree, axis w) const;
    vec rotateX(double degree) const;
    vec rotateY(double degree) const;
    vec rotateZ(double degree) const;
    bool in_space();
    double norm() const;
};

#endif
