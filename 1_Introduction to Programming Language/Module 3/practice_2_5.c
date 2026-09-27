/*

Problem Statement

You will be given a positive integer N, you need to print from 1 to N and besides the value, print Yes or No. Print Yes if the value is divisible by 5 and print No otherwise.

Input Format

Input will contain a positive integer N.
Constraints

1 <= N <= 1000
Output Format

Output as mentioned in the question. See the sample input output for more clarifications. Put a new line after every line.
Sample Input 0

10
Sample Output 0

1 No
2 No
3 No
4 No
5 Yes
6 No
7 No
8 No
9 No
10 Yes
Sample Input 1

5
Sample Output 1

1 No
2 No
3 No
4 No
5 Yes

*/



/* Header files pasted in before compiling:
     stdio.h  - scanf and printf (the only one needed here)
     string.h, math.h, stdlib.h - text, maths and general helpers;
     unused in this program, left over from a template. */
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {    /* the program starts here */
    int N;      /* the last number to print (a whole number) */
    /* %d = read a whole number; &N = where to store it. */
    scanf("%d", &N); // Input the positive integer N

    /* Walk through every number from 1 to N.
       int i=1 starts at 1; i<=N keeps going up to and INCLUDING N;
       i++ adds 1 after each round. One round = one output line. */
    for(int i=1; i<=N; i++){
        /* % gives the remainder of a division. i % 5 == 0 means 5 goes
           into i with nothing left over, i.e. i is divisible by 5.
           e.g. 10 % 5 = 0 -> Yes,   7 % 5 = 2 -> No. */
        if(i % 5 == 0){
            printf("%d Yes\n", i); // Output the value and "Yes" if it's divisible by 5
        } else {
            printf("%d No\n", i); // Output the value and "No" otherwise
        }
    }

    return 0;   /* 0 = the program finished normally */
}