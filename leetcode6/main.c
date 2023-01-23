/* main.c */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/*
The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"

Write the code that will take a string and make this conversion given a number of rows:

string convert(string s, int numRows);

Constraints:
-1 <= s.length <= 1000
-s consists of English letters (lower-case and upper-case), ',' and '.'.
-1 <= numRows <= 1000
*/



char * convert(char * s, int numRows){

    //number of total whitespaces = numRows-2;
    int totalchar = strlen(s);
    int numCol = totalchar/numRows;
    static char temp[1000][1000];
    int i,j = 0, k = 0; //use i for rows, j for columns
    printf("rows: %i, columns: %i, totalchar: %i\n",numRows,numCol, totalchar);


    for(i = 0; i < totalchar; i++)
    {
        if(j < numRows){
            j++;
        }
        else
        {
            j = 0;
            k++;
        }
        temp[j][k] = s[i];
        printf("%c", temp[j][k]);

    }

    printf("\n");
    return (char*)temp;

}


void main(void)
{
    char *test = "PAYPALISHIRING";
    char *answer;

    answer = convert(test, 3);

    printf("answer: %s", answer);

}