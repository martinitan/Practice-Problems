/* main.c */
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

/* 
Given a signed 32-bit integer x, return x with its digits reversed. 
If reversing x causes the value to go outside the signed 32-bit integer range [-2^31, 2^31 - 1], 
then return 0.

Assume the environment does not allow you to store 64-bit integers (signed or unsigned).

Constraints
** -2^31 <= x <= 2^31 - 1
*/

int digitLength(int x)
{
    int length = 0;

    do
    {
        x /=10;
        length++;
    }
    while(x != 0);

    printf("length: %i\n", length);
    return length;
}

int power(int x, int y)
{
    if(y == 0)
    {
        return 1;
    }
    return (x * power(x,y-1) );
}

int reverse(int x)
{
    int length = digitLength(x);
    int i = 0, temp1, temp2;
    int answer = 0;

    for(i = 0; i < length; i++)
    {
        temp1 = x%10; //get smallest digit

        if(__builtin_mul_overflow( temp1, power(10,length-i-1), &temp2))  // set digit to proper place. return if overflowed
        {
            return 0;
        }

        if(__builtin_add_overflow(temp2, answer, &answer)) // add digit to answer, return it overflowed.
        {
            return 0;
        }
        x /= 10; //update x

    }
    return answer;
}

void main(void)
{
    int test = 123;
    int answer = reverse(test);
    printf("test: %i, answer: %i\n", test, answer);

    test = INT_MAX;
    answer = reverse(test);
    printf("test: %i, answer: %i\n", test, answer);
    test = 1534236469;
    answer = reverse(test);
    printf("test: %i, answer: %i\n", test, answer);
    test = -INT_MAX;
    answer = reverse(test);
    printf("test: %i, answer: %i\n", test, answer);
    test = 0;
    answer = reverse(test);
    printf("test: %i, answer: %i\n", test, answer);
    test = 1828384;
    answer = reverse(test);
    printf("test: %i, answer: %i\n", test, answer);
}