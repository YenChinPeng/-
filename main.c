#include <stdio.h>
#include <stdlib.h>
struct A{
  int photo;
  int number;
};

int main()
{
    int DISPLAY_WIDTH=800,DISPLAY_HEIGHT=950;
    int i,j;

    struct A **Arr;
    Arr=create_matrix2();
    Arr=random(Arr,0,0,DISPLAY_WIDTH,DISPLAY_HEIGHT);







   free(Arr);

    return 0;
}
