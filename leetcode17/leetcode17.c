/* leetcode17.c */
#include <strings.h>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>



/*
Given a string containing digits from 2-9 inclusive, 
return all possible letter combinations that the number could represent. Return the answer in any order.

A mapping of digits to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.

constraints:
0 <= digits.length <= 4
digits[i] is a digit in the range ['2', '9'].

mapping:
2:abc
3:def
4:ghi
5:jkl
6:mno
7:pqrs
8:tuv
9:wxyz
*/

/*
 * Note: The returned array must be malloced, assume caller calls free().
 */
//I already hate malloced answerrrr
char ** letterCombinations(char * digits, int* returnSize)
{
    int length = strlen(digits);
    *returnSize = pow(3,length);
    char **answer = (char **)malloc(*returnSize*sizeof(char*));
    char *dvalue[] = {"abc","def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
    

//solve problem 


    return answer;
}

void main(void)
{

    char *testd = "23";
    int retSize;
    char **answer;

    answer = letterCombinations(testd, &retSize);
}