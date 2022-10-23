#include "vec.h"

class vec;

vec::vec(double *init) : array(*(new std::array<double, 3>))
{
    for (int i = 0; i < 3; i++)
        array[i] = init[i];
}
vec::vec(double x, double y, double z) : array(*(new std::array<double, 3>))
{
    array[0] = x;
    array[1] = y;
    array[2] = z;
}

vec::vec(const vec &second_vec) : array(*(new std::array<double, 3>))
{
    for (int i = 0; i < 3; i++)
        array[i] = second_vec.array[i];
}

vec &vec::operator=(const vec &second_vec)
{
    for (int i = 0; i < 3; i++)
        array[i] = second_vec.array[i];
    return *this;
}

bool vec::is_zero()
{
   return (norm() < 1e-20);
}

double vec::operator*(const vec &second_vec)
{
    double dot_product = 0;
    for (int d = 0; d < D; d++)
    {
        dot_product += this->array[d] * second_vec.array[d];
    }
    return dot_product;
}

vec vec::operator+(const vec &second_vec)
{
    vec new_vec = second_vec;
    for (int d = 0; d < D; d++)
    {
        new_vec.array[d] += this->array[d];
    }
    return new_vec;
}

vec vec::operator-(const vec &second_vec)
{
    vec new_vec = *this;
    for (int d = 0; d < D; d++)
    {
        new_vec.array[d] -= second_vec.array[d];
    }
    return new_vec;
}

vec vec::operator*(const double scaler)
{
    vec new_vec(*this);
    for (int i = 0; i < 3; i++)
        new_vec.array[i] = scaler * new_vec.array[i];
    return new_vec;
}

vec vec::mult_matrix(const std::array<std::array<double, D>, D> &matrix) const
{
    vec new_vec(0, 0, 0);
    for (int i = 0; i < D; i++)
        for (int j = 0; j < D; j++)
            new_vec.array[i] += (matrix[i][j] * this->array[j]);
    return new_vec;
}

vec vec::rotateX(double degree) const
{
    double rad = degree * PI / 180;
    std::array<std::array<double, D>, D> rotation_matrix =
        {{{1, 0, 0},
          {0, cos(rad), sin(rad)},
          {0, -sin(rad), cos(rad)}}};
    vec new_vec = this->mult_matrix(rotation_matrix);
    return new_vec;
}
vec vec::rotateY(double degree) const
{
    double rad = degree * PI / 180;
    std::array<std::array<double, D>, D> rotation_matrix =
        {{{cos(rad), 0, sin(rad)},
          {0, 1, 0},
          {-sin(rad), 0, cos(rad)}}};
    vec new_vec = this->mult_matrix(rotation_matrix);
    return new_vec;
}
vec vec::rotateZ(double degree) const
{
    double rad = degree * PI / 180;
    std::array<std::array<double, D>, D> rotation_matrix =
        {{{cos(rad), sin(rad), 0},
          {-sin(rad), cos(rad), 0},
          {0, 0, 1}}};
    vec new_vec = this->mult_matrix(rotation_matrix);
    return new_vec;
}
vec vec::rotate(double degree, axis w) const
{
   switch(w)
   {
    case x: return rotateX(degree); break;
    case y: return rotateY(degree); break;
    case z: return rotateZ(degree); break;
   };
}

bool vec::in_space()
{
    if ((round(array[0]) < 0) || (round(array[1]) < 0) || (round(array[2]) < 0))
        return false;
    if (((round(array[0]) >= X) || (round(array[1]) >= Y) || (round(array[2]) >= Z)))
        return false;
    return true;
}

double vec::norm() const
{
    double sum = 0;
    for(int i=0; i<D; i++)
        sum += array[i]*array[i];
    return sqrt(sum);
}
