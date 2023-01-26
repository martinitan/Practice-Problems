/* main.c */
#include <stdlib.h>
#include <stdio.h>
#include <strings.h>
#include <stdbool.h>
#include <ctype.h>
#include <limits.h>


/* 
implement the myAtoi(string s) function, which converts a string to a 32-bit signed integer (similar to C/C++'s atoi function).

The algorithm for myAtoi(string s) is as follows:

1. Read in and ignore any leading whitespace.
2. Check if the next character (if not already at the end of the string) is '-' or '+'. Read this character in if it is either. 
This determines if the final result is negative or positive respectively. 
Assume the result is positive if neither is present.

3. Read in next the characters until the next non-digit character or the end of the input is reached. The rest of the string is ignored.

4. Convert these digits into an integer (i.e. "123" -> 123, "0032" -> 32). If no digits were read, then the integer is 0. Change the sign as necessary (from step 2).

If the integer is out of the 32-bit signed integer range [-2^31, 2^31 - 1], then clamp the integer so that it remains in the range. 
Specifically, integers less than -2^31 should be clamped to -2^31, and integers greater than 2^31 - 1 should be clamped to 2^31 - 1.
Return the integer as the final result.


NOTES:
Only the space character ' ' is considered a whitespace character.
Do not ignore any characters other than the leading whitespace or the rest of the string after the digits.

Constraints:
0 <= s.length <= 200
s consists of English letters (lower-case and upper-case), digits (0-9), ' ', '+', '-', and '.'
*/


int myAtoi(char * s){

    int length = strlen(s);
    int i, temp;
    bool isPositive = true;
    int answer = 0;
    bool overflow = false; // for handling overflow negative edge case


    if(length == 0)
    {
        printf("length: %i", length);
        return 0;
    }

    //read and ignore white space
    for(i = 0; i < length; i++)
    {
        printf("ignoring whitespace\n");
        if(s[i] != ' ')
        {
            break;
        }
    }

    //set sign
    //if there is a sign increment position
    if(s[i] == '-')
    {
        printf("sign is negative\n");
        isPositive = false;
        i++;
    }
    else if(s[i] == '+')
    {
        printf("sign is positive\n");
        i++;
    }

    //creates integer
    for(i; i < length; i++)
    {
        printf("adding digit: %i\n", s[i]-'0');
        if(isdigit(s[i]))
        {
            if(__builtin_mul_overflow(answer,10,&temp)) //detects overflows and handles accordingly
            {
                answer = INT_MAX;
                overflow = true;
                break;
            }
            if(__builtin_add_overflow(temp, (s[i]-'0'), &answer))
            {
                answer = INT_MAX;
                overflow = true;
                break;
            }
        }
        else
        {
            break;
        }
    }

    //sets final sign
    if(!isPositive)
    {
        answer -= 2*answer;
        if(overflow) //negative overflow edge case
        {
            answer -= 1;
        }
    }

    return answer;
}

void main(void)
{
    char test[] = "    -12345678911111111111 asdfasdf";

    printf("test: %s, answer: %i", test, myAtoi(test));
}