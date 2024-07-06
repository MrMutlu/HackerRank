#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    // initialize T and dynamically allocate array size
    int T = 0; 
    scanf("%d", &T);
    int *arr = malloc(T * (sizeof(int)));
    // make a flag
    int isPrime = 1;
    for(int i = 0; i < T; i++)
    {
        // reset the flag each iteration
        isPrime = 1;
        scanf("%d", &arr[i]);
        
        // check numbers less than 2
        if(arr[i] < 2)
        {
            isPrime = 0;
        }
        // else we check numbers between
        // [2, sqrt(number)]
        else{
            for(int j = 2; j <= sqrt(arr[i]); j++)
            {
                // if its divisible
                // break loop
                if(arr[i] % j == 0)
                {
                    isPrime = 0;
                    break;
                }
            }
        }
        // print the values according to flag
        if(isPrime)
        {
            printf("Prime");
        }
        else
        {
            printf("Not prime");
        }
        printf("\n");
    }
    return 0;
}

