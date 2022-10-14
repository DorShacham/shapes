#include "header.h"
#include "cube.h"

int main()
{
    system("clear");
    cube source(L/2);

    double deg = 1;
    unsigned int sleep_time = 100; //microsecond
    int counter=0;
    while(true)
    {
        cube cube1 = source.rotateY(deg*(counter++)).rotateZ(deg*(counter++));
        cube1.screen_projection().show();
        sleep(1/sleep_time);
    }
    return 0;
}

// int main()
// {
//     system("clear");
//     cube source(L/2);
//     source.rotateX(30).screen_projection().smooth().show();
   
//     return 0;
// }