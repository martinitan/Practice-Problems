/* main.c */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/*
Given a string s, find the length of the longest 
substring without repeating characters.

constraints
-0 <= s.length <= 5 * 10^4(50000)
-s consists of English letters, digits, symbols and spaces.
*/


int lengthOfLongestSubstring(char * s)
{
    int longestLength = 0, currentLength = 0;
    int size = strlen(s);
    char current[50000];
    int i, j; 

    //outer loop tests each substring, inner loop finds length before repeat char
    for(i = 0; i < size; i++)
    {
        //sets current string and length to 0
        memset(current, 0, sizeof(current));
        currentLength = 0;
        for(j = i; j < size; j++)
        {   
            //if current character has been used we are done with substring
            if(strchr(current,s[j]) != NULL) //searches string for char, NULL if not found
            {
                break;
            }
            else    //otherwise update current string and length
            {
                strncat(current,&s[j],1); //appends char to current string
                currentLength = currentLength + 1;
            }
            if(currentLength > longestLength) //when we reach longest length update
            {
                longestLength = currentLength; //only keep longest
            }
            //debug printf
//            printf("i: %i, j: %i,  current: %s, s: %c\n", i, j, current, s[j]);

        }
    }
    return longestLength;
}



void main(void)
{
    char test1[] = " "; //returns 1
    char test2[] = "bbbbbbb"; //returns 1
    char test3[] = "pwwkew";  //returns 3
    int a1,a2,a3;
    
    a1 = lengthOfLongestSubstring(test1);
    a2 = lengthOfLongestSubstring(test2);
    a3 = lengthOfLongestSubstring(test3);

    printf("test 1: %i\n",a1);
    printf("test 2: %i\n",a2);
    printf("test 3: %i\n",a3);

}