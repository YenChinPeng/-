#include <stdio.h>
#include <stdlib.h>
#include <time.h>
struct A
{
    int photo;
    int number;
};
int create_matrix2();
int load_blocks( struct A **B,int step,int round,int width, int height);


int random1 (struct A **C,int step,int round,int DISPLAY_WIDTH,int DISPLAY_HEIGHT) /*int step is cheng add*/
{
    srand(time(NULL));
    int i,j;




    /* struct A **Arr;*/
    /* Arr=create_matrix2();*/


 //   while(1) /*cheng*/
  //  {

        for(i=0; i<1; i=i+1) /*�d�X�Ĥ@�ƦӤw cheng*/
        {
            for(j=0; j<=9; j=j+1)
            {
                C[i][j].photo=rand()%2;
                if(C[i][j].photo==1)
                {
                    C[i][j].number=rand()%4+1;
                }
                else
                {
                    C[i][j].number=0;
                }

            }
        }



        for(i=step; i>=0; i=i-1) //���U���A�쥻��m�M�šA�ѤW���U�� cheng
        {
            for(j=0; j<9; j=j+1)
            {
                C[i+1][j].number=C[i][j].number;
            }
        }



        for(i=1; i<=step+1; i=i+1) /*�q�ĤG�ƶ}�l�L�A�Ĥ@�Ʒ��U�ܼƿ�ܰ�*/
        {
            for(j=0; j<9; j=j+1)
            {
                printf("%d\t",C[i][j].number);
            }
            printf("\n");
        }


        load_blocks(C,step,round,DISPLAY_WIDTH,DISPLAY_HEIGHT);




    //};
    system("pause");

    return C;
}


