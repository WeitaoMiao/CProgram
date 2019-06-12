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

int Array[Length];

void *MyFcn(void *arg);



int main(void)
{
    pthread_t th1;	// Define sub thread
    pthread_t th2;
    pthread_t th3;
    pthread_t th4;
    int i;
    int s1, s2, s3, s4;


    // Initial Array
    s1 = 0;
    s2 = 0;
    s3 = 0;
    s4 = 0;
    for(i=0; i<Length; i++)
    {
        Array[i] = rand()%5;
    }
    MY_ARG arg1 = {0, Length/4, 0};
    MY_ARG arg2 = {Length/4, Length/2, 0};
    MY_ARG arg3 = {Length/2, 3*Length/4, 0};
    MY_ARG arg4 = {3*Length/4, Length, 0};


	/* ---------------------------------------------- */
    // Creat new sub thread to run define function
    pthread_create(&th1, NULL, MyFcn, &arg1);
    pthread_create(&th2, NULL, MyFcn, &arg2);
    pthread_create(&th3, NULL, MyFcn, &arg3);
    pthread_create(&th4, NULL, MyFcn, &arg4);
    // End sub thread
    pthread_join(th1, NULL);
    pthread_join(th2, NULL);
    pthread_join(th3, NULL);
    pthread_join(th4, NULL);
    //
    s1 = arg1.result;
    s2 = arg2.result;
    s3 = arg3.result;
    s4 = arg4.result;
    printf("s1 = %d\n", s1);
    printf("s2 = %d\n", s2);
    printf("s3 = %d\n", s3);
    printf("s4 = %d\n", s4);
    printf("s1 + s2 + s3 + s4 = %d\n", s1+s2+s3+s4);
	/* ---------------------------------------------- */


    return 0;
}

void *MyFcn(void *arg)
{
    int i;
    int first;
    int last;
    MY_ARG *my_arg;
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

