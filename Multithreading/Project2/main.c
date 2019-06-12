#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define Length 500000000

pthread_mutex_t lock;	// Thread lock

int s = 0;

void *MyFcn(void *arg);



int main(void)
{
    pthread_t th1;	// Define sub thread
    pthread_t th2;


	/* ---------------------------------------------- */
	// Thread lock initial
	pthread_mutex_init(&lock, NULL);
    // Creat new sub thread to run define function
    pthread_create(&th1, NULL, MyFcn, NULL);
    pthread_create(&th2, NULL, MyFcn, NULL);
    // End sub thread
    pthread_join(th1, NULL);
    pthread_join(th2, NULL);
    // Print result
    printf("s = %d\n", s);
	/* ---------------------------------------------- */


    return 0;
}



void *MyFcn(void *arg)
{
    int i;

	// Add thread lock
	pthread_mutex_lock(&lock);
	
    for(i=0; i<Length; i++)
    {
        s++;
    }
    
    // Remove thread lock
    pthread_mutex_unlock(&lock);

    return NULL;
}

