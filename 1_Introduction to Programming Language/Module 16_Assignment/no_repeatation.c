/*
You will be given an Array of N integers, print the count of numbers that have appeared only once.

Input Format

The first line will contain an integer N.
The next line will contain N integers.
Constraints

1 <= N <= 10^5
1 <= A[i] <= 10^5
Output Format

Print a single integer,the count of numbers that have apeared only once in the array.

Sample Input 0

10
1 4 3 3 5 2 4 6 2 3
Sample Output 0

3
Explanation 0

In the sample only 1, 5, 6 have apeared only once in the array.So, the count is 3.
*/

#include<stdio.h>

int main(){
    int N;
    scanf("%d", &N);

    /* One counter per possible value (values go up to 10^5). */
    int freq[100005] = {0};

    int numbers[N+5];

    for(int i=0; i<N; i++){
        scanf("%d", &numbers[i]);
    }

    /* Pass 1: count every value. */
    for(int i=0; i<N; i++){
        freq[numbers[i]]++;
    }

    /* Pass 2: walk the numbers again and count those whose value appeared
       exactly once. A value that appears once is met exactly once in this
       walk, so it adds exactly 1; values seen 2 or more times add nothing. */
    int count = 0;
    for(int i=0; i<N; i++){
        if(freq[numbers[i]] == 1){
            count++;
        }
    }

    printf("%d\n", count);

    return 0;
}

