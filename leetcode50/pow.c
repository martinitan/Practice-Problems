/* main.c */
#include <stdlib.h>
#include <stdio.h>
#include "pow.h"


// compute power function

double myPow(double x, int n)
{
    double temp;

    if( n == 0)
    {
        return 1;
    }
    temp = myPow(x, n/2);
    printf("value: %f\n", temp);
    if(n % 2 == 0)
    {
        printf("temp*temp: %f\n", temp);
        return temp*temp;
    }
    else
    {
        if(n > 0)
        {
            printf("temp*temp*x: %f temp: %f\n", temp*temp*x, temp);
            return temp*temp*x;
        }
        else
        {
            printf("temp*temp/x: %f temp: %f\n", temp*temp/x,temp);
            return temp*temp/x;
        }
    }

}
