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
    static char answer[1000];
    int i,col = 0, row = 0;
    int k, l, m;
    printf("rows: %i, columns: %i, totalchar: %i\n",numRows,numCol, totalchar);


    for(i = 0; i < totalchar; i++)
    {
        printf("row: %i, col: %i\n", row, col);
        if(col % (numRows-1) == 0) //for columns with every index filled
        {

            temp[row][col] = s[i]; 
            row++;
            if(row == numRows) //when bottom of column, move to next
            {
                row = 0;
                col++;
            }
        }
        else
        { // for columns with only 1 index filled
            /*
            if first after full row, should be second from the end row
                numRow = 3
                3 - (1%(3-1)) - 1 = 3 - 1%2 - 1 = 3 - 1 - 1 = 1

                numRow = 4
                4 - (1%(4-1) - 1) = 4 - 1%3 - 1 = 4 - 1 - 1 = 2

            if second after full Row, should be third from end row
                numRow = 4
                4 - (2%(4-2)) - 1 = 4 - 2%2 - 1 = 4 - 0 - 1 = 3
            */

            temp[numRows - (col%(numRows-1)) - 1][col] = s[i];
            col++;
        }
    }

    printf("\n");
    for(k = 0; k < totalchar; k++)
    {
        for(l = 0; l < totalchar; l++)
        {
            if(temp[k][l] != '\0')
            {
                answer[m] = temp[k][l];
                m++;
            }
        }
    }

    return (char*)answer;
}


void main(void)
{
    char *test = "PAYPALISHIRING";
    char *answer;
    
    answer = convert(test, 4);
    printf(!strcmp("PINALSIGYAHRPI", answer) ? "passed": "failed");
    printf("\nFound answer: %s, Correct answer: PINALSIGYAHRPI\n", answer);
    
}