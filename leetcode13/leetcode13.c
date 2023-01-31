/* leetcode13.c */
#include "../leetcode12/leetcode12.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define debug

/*

Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.

Symbol       Value
I             1
V             5
X             10
L             50
C             100
D             500
M             1000
For example, 2 is written as II in Roman numeral, just two ones added together. 12 is written as XII, which is simply X + II. The number 27 is written as XXVII, which is XX + V + II.

Roman numerals are usually written largest to smallest from left to right. However, the numeral for four is not IIII. Instead, the number four is written as IV. Because the one is before the five we subtract it making four. The same principle applies to the number nine, which is written as IX. There are six instances where subtraction is used:

I can be placed before V (5) and X (10) to make 4 and 9. 
X can be placed before L (50) and C (100) to make 40 and 90. 
C can be placed before D (500) and M (1000) to make 400 and 900.
Given a roman numeral, convert it to an integer.

Constraints:

1 <= s.length <= 15
s contains only the characters ('I', 'V', 'X', 'L', 'C', 'D', 'M').
It is guaranteed that s is a valid roman numeral in the range [1, 3999].

*/


int romanToInt(char * s)
{
    int answer = 0, i = 0;
    int length = strlen(s);

    while(length > i)
    {

        if(s[i] == 'M')
        {
            i++;
            answer += 1000;
        }
        else if(s[i] == 'C' && s[i+1] == 'M')
        {
            i += 2;
            answer += 900;
        }
        else if(s[i] == 'D')
        {
            i++;
            answer += 500;
        }
        else if(s[i] == 'C' && s[i+1] == 'D')
        {
            i += 2;
            answer += 400;
        }
        else if(s[i] == 'C')
        {
            i++;
            answer += 100;
        }
        else if(s[i] == 'X' && s[i+1] == 'C')
        {
            i +=2;
            answer += 90;
        }
        else if(s[i] == 'L')
        {
            i++;
            answer += 50;
        }
        else if(s[i] == 'X' && s[i+1] == 'L')
        {
            i +=2;
            answer += 40;
        }
        else if(s[i] == 'X')
        {
            i++;
            answer += 10;
        }
        else if(s[i] == 'I' && s[i+1] == 'X')
        {
            i +=2;
            answer += 9;
        }
        else if(s[i] == 'V')
        {
            i++;
            answer += 5;
        }
        else if(s[i] == 'I' && s[i+1] == 'V')
        {
            i +=2;
            answer += 4;
        }
        else
        {
            i++;
            answer += 1;
        }
#ifdef debug
        printf("Number: %i\n", answer);
#endif
    }
    

    return answer;
}

void main(void)
{
    int test = 3888;
    char *testchars = intToRoman(test);

    printf("the test number is: %i, the answer is: %i", test, romanToInt(testchars));


}