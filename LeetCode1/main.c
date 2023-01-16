/* main.c */
#include <stdlib.h>
#include <stdio.h>

/* 
Problem: 
Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.
*/


int* twoSum(int* nums, int numsSize, int target, int* returnSize)
{
    
    int i = 0;
    int j = 0;
    int result = 0;
    int *answer = malloc(2*sizeof(int));
    *returnSize = 2;

    for(i=0; i<numsSize; i++)
    {
        for(j=i+1; j<numsSize; j++)
        {
            result = nums[i] + nums[j];
            printf("result : %i\n", result,j);
            answer[0] = i;
            answer[1] = j;
            if(result == target)
            {
                printf("answer: %i, %i\n", i, j);
                return answer;
            }
        }
    }
    return answer;
}

int main(void)
{
    int input1[4] = {2,7,11,15};
    int input2[3] = {3,2,4};
    int input3[2] = {3,3};

    int returnSize[1] = {2};

    int *answer1 = twoSum(input1, 4, 9, returnSize);
    int *answer2 = twoSum(input2, 3, 6, returnSize);
    int *answer3 = twoSum(input3, 2, 6, returnSize);

    printf("Expected: [0,1], Actual: [%i,%i]\n",answer1[0],answer1[1]);
    printf((answer1[0]==0)&&(answer1[1]==1) ? "Passed" : "Failed");
    printf("\nExpected: [1,2], Actual: [%i,%i]\n",answer2[0],answer2[1]);
    printf((answer2[0]==1)&&(answer2[1]==2) ? "Passed" : "Failed");
    printf("\nExpected: [0,1], Actual: [%i,%i]\n",answer3[0],answer3[1]);
    printf((answer3[0]==0)&&(answer3[1]==1) ? "Passed" : "Failed");

    free(answer1);
    free(answer2);
    free(answer3);

    return 0;

}
