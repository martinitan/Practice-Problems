/* leetcode26.c */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../leetcode15/leetcode15.h"

/*
a slightly modified version of this was used to save Leetcode80 delete duplicates of greater than 2
leaving arrays 2 or less of every digit.
IE. 1,1,2,2,3,4,5,6,6
*/

/*
Given an integer array nums sorted in non-decreasing order, remove the duplicates in-place such that each unique element appears only once. 
The relative order of the elements should be kept the same.

Since it is impossible to change the length of the array in some languages, you must instead have the result be placed in the first part of the array nums. 
More formally, if there are k elements after removing the duplicates, then the first k elements of nums should hold the final result. 
It does not matter what you leave beyond the first k elements.

Return k after placing the final result in the first k slots of nums.

Do not allocate extra space for another array. You must do this by modifying the input array in-place with O(1) extra memory.
*/

int removeDuplicates(int* nums, int numsSize)
{

    int i, answerIndex = 2;

    for(i = 1; i < numsSize; i++)
    {

        //if number not same as previous, save it
        if(COMPARE(nums[answerIndex - 1],nums[i])) 
        {
            nums[answerIndex] = nums[i];
            answerIndex++;
        }
    }

    return answerIndex;
}

void main(void)
{
    int test[] = {0,0,1,1,1,1,2,3,3};
    int size = sizeof(test)/sizeof(int);
    int answerSize;

    printIntArray(test, size);

    answerSize = removeDuplicates(test,size);

    printf("answer Length: %i\n", answerSize);
    printIntArray(test, answerSize);
}