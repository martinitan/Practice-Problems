/* leetcode16.c */
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

/*
Given an integer array nums of length n and an integer target, 
find three integers in nums such that the sum is closest to target.

Return the sum of the three integers.

You may assume that each input would have exactly one solution.

Constraint:
3 <= nums.length <= 500
-1000 <= nums[i] <= 1000
-10^4 <= target <= 10^4 
*/
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


int threeSumClosest(int* nums, int numsSize, int target)
{
    int i = 0, j, k;
    int temp, dif;
    int closest = INT_MAX, answer;



    //sort list
    qsort(nums, numsSize, sizeof(int), compare_int);

    j = 1;
    k = numsSize-1;
    for(i = 0; i < numsSize - 2;)
    {
        temp = nums[i] + nums[j] + nums[k];
        printf("%i %i %i\n", nums[i], nums[j], nums[k]);
        printf("temp:target %i : %i\n", temp, target);
        if(temp < target)
        {
            dif = target - temp;
            // make number possible answer bigger
            j++;
        }
        else if(temp > target)
        {
            dif = temp - target;
            //make possible answer smaller
            k--;
        }
        else
        {
            return temp;
        }

        printf("dif: %i\n", dif);


        if( j >= k)
        {
            i++;
            j = i+1;
            k = numsSize-1;
        }
        

        if(dif < closest)
        {
            closest = dif;
            answer = temp;
        }


    }

    return answer;
}

void main(void)
{
    int testa[] = {-1,2,1,-4};
    int testtarget = 1;
    int size = sizeof(testa)/sizeof(int);

    int answer;

    answer = threeSumClosest(testa, size, testtarget);

    printf("the answer : %i\n", answer);

}