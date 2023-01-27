/* main.c */
#include <stdbool.h>
#include <stdio.h>
#include <limits.h>
#include <stdlib.h>


/*
Given an integer x, return true if x is a 
palindrome, and false otherwise.

Constraints:
-2^31 <= x <= 2^31 - 1

bonus: Could you solve it without converting the integer to a string
*/


bool isPalindrome(int x){

    int remainder, reverse = 0;
    int temp = x;
    int temp1;

    if(x < 0) //per example, negative sign means not palindrome
    {
        return false;
    }

    // if same as backwards it is palindrome
    while (x != 0) {

        remainder = x % 10;
        if(__builtin_mul_overflow(reverse, 10, &temp1))
        {
            return false;
        }
        if(__builtin_add_overflow(temp1, remainder, &reverse))
        {
            return false;
        }
        x/= 10;
    }

    if(reverse == temp)
    {
        return true;
    }
    return false;
}

void main(void)
{

    int test = 1234567899;
    bool answer;

    answer = isPalindrome(test);

    printf("is %i a palindrome?\nanswer: ", test);
    printf(answer ? "true" : "false");

}