/*

Problem Statement

I know and you also know that you love practice day so much. So this task is for you. You will be given a positive integer N, you need to print "I Love Practice" N times.

Here positive integer means those integers that are greater than 0.

Input Format

You will be given a positive integer N.
Constraints

1 <= N <= 1000
Output Format

Output "I Love Practice" N times. Don't forget to put a new line after every line.
Sample Input 0

5
Sample Output 0

I Love Practice
I Love Practice
I Love Practice
I Love Practice
I Love Practice
Sample Input 1

2
Sample Output 1

I Love Practice
I Love Practice

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
    int N;      /* how many times to print; a whole number (int) */
    /* %d = read a whole number; &N = address of N, where scanf stores it. */
    scanf("%d", &N); // Input the positive integer N

    /* Repeat the printf N times.
       for (start; keep-going test; step):
         int i=0  - make a counter i, starting at 0
         i<N      - run the body while i is less than N
         i++      - after each round add 1 to i
       i takes the values 0, 1, ..., N-1: that is exactly N rounds.
       With N = 2: i=0 prints, i=1 prints, i=2 fails the test -> stop. */
    for(int i=0; i<N; i++){
        printf("I Love Practice\n"); // Output "I Love Practice" and a newline (\n)
    }

    return 0;   /* 0 = the program finished normally */
}