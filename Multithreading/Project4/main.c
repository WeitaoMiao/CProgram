#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>



#define Length 50000000

typedef struct
{
    int first;
    int last;
    int result;
} MY_ARG;

int *Array;

void *MyFcn(void *arg);



int main(void)
{
    pthread_t th1;	// Define sub thread
    pthread_t th2;
    int i;
    int s1, s2;


    // Initial Array
    Array = (int *)malloc(sizeof(int)*Length);
    for(i=0; i<Length; i++)
    {
    	Array[i] = rand()%5;
    }
    s1 = 0;
    s2 = 0;
    MY_ARG arg1 = {0, Length/2, 0};
    MY_ARG arg2 = {Length/2, Length, 0};


	/* ---------------------------------------------- */
    // Creat new sub thread to run define function
    pthread_create(&th1, NULL, MyFcn, &arg1);
    pthread_create(&th2, NULL, MyFcn, &arg2);
    // End sub thread
    pthread_join(th1, NULL);
    pthread_join(th2, NULL);
    //
    s1 = arg1.result;
    s2 = arg2.result;
    printf("s1 = %d\n", s1);
    printf("s2 = %d\n", s2);
    printf("s1 + s2 = %d\n", s1+s2);
	/* ---------------------------------------------- */


    return 0;
}

void *MyFcn(void *arg)
{
    int i;
    MY_ARG *my_arg;
    int first;
    int last;
    int s;


    // Initial
    my_arg = (MY_ARG *)arg;
    first = my_arg->first;
    last = my_arg->last;
    s = 0;
    for(i=first; i<last; i++)
    {
        s = s + Array[i];
    }
    my_arg->result = s;


    return NULL;
}

