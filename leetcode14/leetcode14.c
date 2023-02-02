/* leetcode14.c */
#include <stdio.h>
#include <string.h>
#include <limits.h>


/* 
misunderstood problem
this finds the longest common prefix between atleast 2 of the strings

Leetcode problem wanted common between all of the strings. 

for their problem:

for(len(shortestString))
{
    equal = char[0][j]^char[i][j]

    if(!equal)
    {
        return char[0][0:j];
    }
}


*/



/*
Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".


Constraints: 
1 <= strs.length <= 200
0 <= strs[i].length <= 200
strs[i] consists of only lowercase English letters.
*/

// 0 if values are equal
#define COMPARE( a, b) ((a)^(b))
#define MIN( a, b) ((a) < (b) ? (a) : (b))
#define MAX( a, b) ((a) > (b) ? (a) : (b))

int sum(int *x, int length)
{
    int answer = 0, i;

    for(i = length-1; i > 0; i--)
    {
        answer += x[i];
    }
    return answer;
}

char * longestCommonPrefix(char ** strs, int strsSize)
{

    char answer[200];
    int answerLen = 0, answerString = 0;
    int done[strsSize];
    int i, j, k;
    int smallestLen = INT_MAX;
    int temp, tempLen = 0;

    //find shortest string, thats longest t prefix possible
    for(i = strsSize; i--;)
    {
        smallestLen = MIN(smallestLen, strlen(strs[i]));
        done[i] = 1;
    }

    k = 0;
    //for each character check if continuously common characters 
    for(i = -1; i++ < smallestLen;)
    {

//        printf("currently using word %i:%s as base\n", k,strs[k]);
        for(j = strsSize-1; j > k; j--)
        {
            temp = COMPARE(strs[k][i],strs[j][i]);
            if(!temp && (done[j] == 1)) //same and all previous where same
            {
                tempLen++;
            }
            else //not same
            {
                done[j] = 0;
            }

//            printf("templen: %i, done[j]: %i, comparing to: %s\n", tempLen, done[j], strs[j]);
        }

        //save string and length of answer
        if(tempLen > answerLen)
        {
            answerLen = MAX(answerLen, tempLen); 
            answerString = k;

            if(answerLen == smallestLen)
            {
                break;
            }
        }
        

        if(sum(&done[k], strsSize-k) == 0) //none are same so try using next word as base.
        {
//            printf("Moving on to next word\n\n");
            tempLen = 0;
            k++;
            i= -1;
            if(k == strsSize)
            {
                break;
            }
            for(j = k; j < strsSize; j++)
            {
                done[j] = 1;
            }
        }
//        printf("\n");
    }

//    printf("len : %i\n", answerLen);
    if(answerLen)
    {
        strncpy(answer, strs[answerString] ,answerLen);
    }
    else
    {
        memcpy(answer, "", 1);
    }

//    printf("%s\n", answer);
    
    return strdup(answer);
}

void main(void)
{

    char *test[] = {"flower","flow", "flight"};
    int length = 3;


    
    printf("Wrong programe");


}