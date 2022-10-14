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
        cube cube1 = source.rotateZ(deg*(counter++)).rotateY(deg*(counter++));
        cube1.screen_projection().show();
        sleep(1/sleep_time);
    }
    return 0;
}

// int main()
// {
//     system("clear");
//     cube source(L/2);
//     source.rotateZ(30).screen_projection().show();
   
//     return 0;
// }