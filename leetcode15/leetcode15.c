/* leetcode15.c */
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

/*
Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

Notice that the solution set must not contain duplicate triplets.

Contraints:
3 <= nums.length <= 3000
-10^5 <= nums[i] <= 10^5
*/

//0 if equal
#define COMPARE( a, b) ((a)^(b))

//taken from Stackoverflow user: caf
//found at https://stackoverflow.com/questions/1169385/is-there-a-good-library-for-sorting-a-large-array-of-numbers-in-c
//feb 3, 2023
int compare_int(const void *a, const void *b)
{
    const int *ia = a;
    const int *ib = b;

    if (*ia < *ib)
        return -1;

    if (*ia > *ib)
        return 1;

    return 0;

}

void printIntArray(int *x, int size)
{
    printf("Array: ");
    int i;
    for(i = size; i--;)
    {
        printf("%i ", x[size - i - 1]);
    }
    printf("\n");
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes)
{
    //  max triplets:
    //                    n!
    //                ----------                
    //                 n!(n-r)!
    int maxTriplets = 100000;
    int **answer = (int**)malloc(maxTriplets*sizeof(int*));
    int i = 0, k, j;
    int temp, p;
    int tempArray[3];

    *returnSize = 0;
    returnColumnSizes[0] = (int*)malloc(maxTriplets*sizeof(int));

//sort list
    qsort(nums, numsSize, sizeof(int), compare_int);

//find all possible sums, save correct ones 
//use head of array + two pointers to check all values
    j = 1;
    k = numsSize-1;
    for(i = 0; i < numsSize;)
    {
        temp = nums[i] + nums[j] + nums[k];
        if(temp < 0)
        {
            j++;
        }
        else if(temp > 0)
        {
            k--;
        }
        else
        {
            //save info. if values not used.
            tempArray[0] = nums[i];
            tempArray[1] = nums[j];
            tempArray[2] = nums[k];
            qsort(tempArray, 3, sizeof(int), compare_int);

            //for first found triplet, just save it
            if(*returnSize == 0)
            {
                answer[*returnSize] = (int*)malloc(3*sizeof(int));

                answer[*returnSize][0] = tempArray[0];
                answer[*returnSize][1] = tempArray[1];
                answer[*returnSize][2] = tempArray[2];

                returnColumnSizes[0][*returnSize] = 3;
                *returnSize += 1;
            }

            for(p = 0; p < *returnSize; p++)
            {
                // if value is not same as saved array
                // keep searching
                if(COMPARE(answer[p][0],tempArray[0]) || COMPARE(answer[p][1],tempArray[1])
                    || COMPARE(answer[p][2],tempArray[2]))
                {
                    
                    // if we are at last found triplet, and still unique, save it
                    if((p+1) == *returnSize)
                    {
                        answer[*returnSize] = (int*)malloc(3*sizeof(int));

                        answer[*returnSize][0] = tempArray[0];
                        answer[*returnSize][1] = tempArray[1];
                        answer[*returnSize][2] = tempArray[2];

                        returnColumnSizes[0][*returnSize] = 3;
                        *returnSize += 1;
                    }
                }
                else
                {
                    //if value is same as saved array, do not add
                    break;
                }
            }

            j++;
            k--;
            //printf("\n");
        }
        if(j >= k)
        {
            i++;
            j = i+1;
            k = numsSize - 1;
        }
        if( j == k)
        {
            printf("returning\n");
            return answer;
        }
    }
//return
    printf("returning\n");
    return answer;
}

void main(void)
{
    int test[] = {-1,0,1,2,-1,-4, 4, -5, 5};
    int testlen = sizeof(test)/sizeof(int);
    int i;
    int retSize;
    int *retColSize;
    int **answer;

    retSize = -1;

    answer = threeSum(test, testlen, &retSize, &retColSize);

    printIntArray(answer[0], retColSize[0]);

    free(retColSize);
    free(answer);

}