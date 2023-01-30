/* main.c */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define max_length 16

/*
Roman numerals are represented by seven different 
symbols: I, V, X, L, C, D and M.


Symbol       Value
I             1
V             5
X             10
L             50
C             100
D             500
M             1000

For example, 2 is written as II in Roman numeral, 
just two one's added together. 12 is written as XII, which is simply X + II. 
The number 27 is written as XXVII, which is XX + V + II.

Roman numerals are usually written largest to smallest from left to right. 
However, the numeral for four is not IIII. 
Instead, the number four is written as IV. 
Because the one is before the five we subtract it making four. 
The same principle applies to the number nine, which is written as IX. 
There are six instances where subtraction is used:

I can be placed before V (5) and X (10) to make 4 and 9. 
X can be placed before L (50) and C (100) to make 40 and 90. 
C can be placed before D (500) and M (1000) to make 400 and 900.
Given an integer, convert it to a roman numeral.
*/

char * intToRoman(int num)
{
    char answer[max_length] = {max_length*'\0'};
    int i = 0;
    
    while(num > 0)
    {
        printf("current number: %i\n", num);
        if(num >= 1000)
        {

            memcpy(&answer[i], "M", sizeof(char));
            i++;
            num -= 1000;
        }
        else if(num >= 900)
        {
            memcpy(&answer[i], "CM", 2*sizeof(char));
            i += 2;
            num -= 900;
        }
        else if(num >= 500)
        {
            memcpy(&answer[i], "D", sizeof(char));
            i++;
            num -= 500;
        }
        else if(num >= 400)
        {
            memcpy(&answer[i], "CD", 2*sizeof(char));
            i += 2;
            num -= 400;
        }
        else if(num >= 100)
        {
            memcpy(&answer[i], "C", sizeof(char));
            i++;
            num -= 100;
        }
        else if(num >= 90)
        {
            memcpy(&answer[i], "XC", 2*sizeof(char));
            i +=2;
            num -= 90;
        }
        else if(num >= 50)
        {
            memcpy(&answer[i], "L", sizeof(char));
            i++;
            num -= 50;
        }
        else if(num >= 40)
        {
            memcpy(&answer[i], "XL", 2*sizeof(char));
            i +=2;
            num -= 40;
        }
        else if(num >= 10)
        {
            memcpy(&answer[i], "X", sizeof(char));
            i++;
            num -= 10;
        }
        else if(num >= 9)
        {
            memcpy(&answer[i], "IX", 2*sizeof(char));
            i +=2;
            num -= 9;
        }
        else if(num >= 5)
        {
            memcpy(&answer[i], "V", sizeof(char));
            i++;
            num -= 5;
        }
        else if(num >= 4)
        {
            memcpy(&answer[i], "IV", 2*sizeof(char));
            i +=2;
            num -= 4;
        }
        else
        {
            memcpy(&answer[i], "I", sizeof(char));
            i++;
            num -= 1;
        }
    }
    printf("%s", answer);
    return strdup(answer);
}

void main(void)
{
    int test1 = 3888, test2 = 3900, test3 = 3500;

    printf("number is %i: %s\n", test1, intToRoman(test1));
    printf("number is %i: %s\n", test2, intToRoman(test2));
    printf("number is %i: %s\n", test3, intToRoman(test3));

}