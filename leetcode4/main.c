/* main.c */
#include <stdio.h>
#include <stdlib.h>


/*
Given two sorted arrays nums1 and nums2 of size m and n respectively, 
return the median of the two sorted arrays.

The overall run time complexity should be O(log (m+n)).

Constaints:
nums1.length == m
nums2.length == n
0 <= m <= 1000            //solution ignores these size constraints. works for (m + n = max_int)
0 <= n <= 1000
1 <= m + n <= 2000
-10^6 <= nums1[i], nums2[i] <= 10^6
*/


double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size){

    int totalsize;
    int i, n1 = 0, n2 = 0; //iterators
    totalsize = nums1Size + nums2Size;
    int nums3[totalsize];

    double answer;
    printf("nums3: "); // for printing out final array.

    // put everything into 1 array in order
    for(i = 0; i < totalsize; i++)
    {
        if( (n1 < nums1Size) && (n2 < nums2Size)) //if both arrays have values remaining, pick smallest value
        {
            if(nums1[n1] <= nums2[n2])
            {
                nums3[i] = nums1[n1];
                n1++;
            }
            else
            {
                nums3[i] = nums2[n2];
                n2++;
            }
        }
        else if( (n1 >= nums1Size) && (n2 < nums2Size)) // if first array out of values then only use array 2
        {
            nums3[i] = nums2[n2];
            n2++;
        }
        else if((n1 < nums1Size) && (n2 >= nums2Size)) //if second array out of values only use array 1
        {
            nums3[i] = nums1[n1];
            n1++;
        }
        else
        {
            printf("both arrays out of values. something is wrong if you get here");
        }
        printf("%i ",  nums3[i]); //prints out final array as creating
    }
    printf("\n");

   
    //median is middle number or average of middle 2 numbers
    if(totalsize % 2 == 0) 
    { //even so 2 middle numbers
        answer = (double) (nums3[totalsize/2] + nums3[(totalsize/2)-1]) / 2;
    }
    else
    { //just middle number
        answer = nums3[(totalsize/2)];
    }
    return answer;
}


void main(void)
{
    int test11[] = {1,3}, test12[] = {2}, s11, s12; //odd length final array
    s11 = sizeof(test11)/sizeof(test11[0]); //total size / size of each element == number of elements.
    s12 = sizeof(test12)/sizeof(test12[0]);
    double result1;

    printf("\n");
    result1 = findMedianSortedArrays(test11, s11, test12, s12); //result should be 2.0
    printf("the median: %f\n\n", result1);



    int test21[] = {1,3}, test22[] = {2,4}, s21, s22; //even length final array
    s21 = sizeof(test21)/sizeof(test21[0]);
    s22 = sizeof(test22)/sizeof(test22[0]);
    double result2;

    result2 = findMedianSortedArrays(test21, s21, test22, s22); //result should be 2.5
    printf("the median: %f\n\n", result2);

}