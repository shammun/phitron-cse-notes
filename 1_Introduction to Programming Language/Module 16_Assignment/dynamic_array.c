/*
You will be given N integer Numbers.

You will initialy declare an array with length 1.

After taking input of each numbers you will insert the number in the end and increase the array length by one.

Finally, print all N numbers in the array in a single line, separated by spaces.

Note: The solution must be implemented with dynamic array.

Input Format

The first line will contain an integer N, the number of elements.
The second line will contain N integers.
Constraints

1 <= N <= 1000
1 <= Each integers <= 10^9
Output Format

Print the array of N integers in a single line, with all the elements separated by spaces.

Sample Input 0

5
1 4 2 6 9
Sample Output 0

1 4 2 6 9
*/

#include<stdio.h>
#include<stdlib.h>

int main(){
    int N;
    scanf("%d", &N);
    int *arr = (int *)malloc(sizeof(int));

    int num_array[N+5];
    for(int i=0; i<N; i++){
        scanf("%d", &num_array[i]);
        arr = (int *)realloc(arr, (i+1)*sizeof(int));
        arr[i] = num_array[i];
    }

    for(int i=0; i<N; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");

    free(arr);

    return 0;
}
