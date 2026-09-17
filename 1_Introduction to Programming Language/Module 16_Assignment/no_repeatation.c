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

    int freq[100005] = {0};

    int numbers[N+5];

    for(int i=0; i<N; i++){
        scanf("%d", &numbers[i]);
    }

    for(int i=0; i<N; i++){
        freq[numbers[i]]++;
    }

    int count = 0;
    for(int i=0; i<N; i++){
        if(freq[numbers[i]] == 1){
            count++;
        }
    }

    printf("%d\n", count);

    return 0;
}

