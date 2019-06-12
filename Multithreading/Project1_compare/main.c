#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define Length 500000000

int Array[Length];

int main(void)
{
    int i;
    int s;

    // Initial Array
    s = 0;
    for(i=0; i<Length; i++)
    {
        Array[i] = 1;
    }

    // Sum
    for(i=0; i<Length; i++)
    {
        s = s+Array[i];
    }
    
    printf("s = %d\n", s);

    return 0;
}

