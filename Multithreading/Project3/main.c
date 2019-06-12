#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define Length 50000000

typedef struct
{
    int first;
    int last;
    int id;
} MY_ARG;

int *Array;
int result[2];

void *MyFcn(void *arg);



int main(void)
{
    pthread_t th1;	// Define sub thread
    pthread_t th2;
    int i;


    // Initial
    Array = (int *)malloc(sizeof(int)*Length);
    for(i=0; i<Length; i++)
    {
    	Array[i] = rand()%5;
    }
    result[0] = 0;
    result[1] = 0;
    MY_ARG arg1 = {0, Length/2, 0};
    MY_ARG arg2 = {Length/2, Length, 1};


	/* ---------------------------------------------- */
    // Creat new sub thread to run define function
    pthread_create(&th1, NULL, MyFcn, &arg1);
    pthread_create(&th2, NULL, MyFcn, &arg2);
    // End sub thread
    pthread_join(th1, NULL);
    pthread_join(th2, NULL);
    //
    printf("s1 = %d\n", result[0]);
    printf("s2 = %d\n", result[1]);
    printf("result = %d\n", result[0]+result[1]);
	/* ---------------------------------------------- */


    return 0;
}

void *MyFcn(void *arg)
{
    int i;
    MY_ARG *my_arg;
    int first;
    int last;
    int id;


    // Initial
    my_arg = (MY_ARG *)arg;
    first = my_arg->first;
    last = my_arg->last;
    id = my_arg->id;
	// Sum
    for(i=first; i<last; i++)
    {
        result[id] = result[id] + Array[i];
    }


    return NULL;
}

