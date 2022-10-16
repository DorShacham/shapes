#include "header.h"
#include "cube.h"
#include "torus.h"

int main()
{
    system("clear");
    torus source(L*0.35,L*0.12);

    double deg = 1;
    unsigned int sleep_time = 5; //microsecond
    int counter=0;
    while(true)
    {
        torus torus1 = source.rotateY(2*deg*(counter++)).rotateZ(deg*(counter++));
        torus1.screen_projection().continues().show();
        usleep(sleep_time);
    }
    return 0;
}

// int main()
// {
//     system("clear");
//     torus source(L/4,L/6);
//     source.rotateY(90).screen_projection().show();
//     // source.rotateX(30).screen_projection().smooth().show();
   
//     return 0;
// }