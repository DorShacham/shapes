#include "torus.h"

torus::torus(double R, double r)
{
    double resulotion = (2 * PI) / 200;

    for (double theta = 0; theta < (2 * PI); theta += resulotion)
        for (double phi = 0; phi < (2 * PI); phi += resulotion)
        {
            double x = (R + r * cos(theta)) * cos(phi) + center_x;
            double y = (R + r * cos(theta)) * sin(phi) + center_y;
            double z = r * sin(theta) + center_z;
            if (vec(x, y, z).in_space())

            {
                double x_normal = (R + r * cos(theta)) * r * cos(theta) * cos(phi);
                double y_normal = (R + r * cos(theta)) * r * cos(theta) * sin(phi);
                double z_normal = (R + r * cos(theta)) * (r * sin(theta));
           
                vec normal(x_normal, y_normal, z_normal);

                space[round(x)][round(y)][round(z)] = normal;
            }
        }
}