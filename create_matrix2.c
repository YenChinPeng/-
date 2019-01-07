#include <stdio.h>
#include <stdlib.h>
#include <math.h>
struct A{
  int photo;
  int number;
};
struct A **create_matrix2()
{
// input rows and cols
// output a pointer to 2D mat[rows][cols]
    struct A **mat = (struct A **) calloc(9,sizeof(struct A*));
    int i,j;
    for(i=0; i<9; i++)
    // Allocate array, store pointer
        mat[i] = (struct A *) calloc(9,sizeof(struct A));


    for(i=0; i<9; i++){
        for(j=0; j<9; j++){
            mat[i][j].number=0;
            mat[i][j].photo=0;
       }
    }
    return mat;
}
