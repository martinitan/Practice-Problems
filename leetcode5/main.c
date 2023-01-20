/* main.c */
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

/*

Given a string s, return the longest palindromic
 
substring in s.

Constraints:
-1 <= s.length <= 1000
-s consist of only digits and English letters.
*/

// char array must not include "\0" null character to work

bool isPalindrome(char * s, int size)
{
    if(size <= 1) //anything 1 char or less is palindrome
    {
        return true;
    }
    else if (size == 2) // with 2 char, both must be the same 
    {
        if(s[0] == s[1])
        {
            return true;
        }
    }
    else if (s[0] == s[size-1]) //if both ends are same and inside is palindrome, then palindrome
    {
        return isPalindrome(&s[1],size-2);
    }

    return false;
}

// find all substrings, pick longest palindrome from them
char * longestPalindrome(char * s)
{
    int i, j, k;
    int maxSize = strlen(s);    //ignore null character
    static char longest[1001];
    int longestLength = 0;

    for(i = 0; i <= maxSize; i++) //starting char of subset
    {
        for(j = i; j <= maxSize; j++) //end char of subset
        {
            if(isPalindrome(&s[i], j-i)) //if subset is palindrome
            {
                if((j-i) > longestLength)//if longest palindrome found
                {
                    memset(longest, 0, sizeof(longest));
                    for(k = 0; k < j-i; k++)//save palindrome
                    {
                        longestLength = j-i;
                        longest[k] = s[i+k];
                    }
                }
            }
        }
    }

    return longest;

}

void main(void)
{
    char test[] = "cbbd";
    char *answer;
    answer = longestPalindrome(test);

    printf("input: %s\nLongest Palindrome: %s", test, answer);
    
}