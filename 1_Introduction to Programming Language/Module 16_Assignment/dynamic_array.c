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

#include<stdio.h>  // standard input/output library: scanf and printf
#include<stdlib.h> // standard library: malloc, realloc, free

/*
stdlib.h is needed because it declares the three memory functions your program
uses: malloc, realloc, and free. stdio.h only covers input/output functions
like scanf and printf, so it doesn't include them.
*/

/* Idea: arr lives on the heap and starts with room for one int. Before the
   i-th number is stored, realloc resizes the block to i + 1 ints, so the
   array always has exactly as many boxes as numbers read so far.
   (Values go up to 10^9, which still fits in an int.) */

int main(){ // program execution starts here
    int N; // how many numbers
    scanf("%d", &N); // &N = address where scanf stores N
    int *arr = (int *)malloc(sizeof(int)); // room for exactly 1 int; the (int *) cast turns malloc's void* into an int pointer

    int num_array[N+5]; // an ordinary array that just receives each number as it is read
    for(int i=0; i<N; i++){ // one pass = one new number
        scanf("%d", &num_array[i]); // read the next number
        arr = (int *)realloc(arr, (i+1)*sizeof(int)); // resize the block to i + 1 ints (for i = 0 it stays 1 int)
        /*

        realloc is not just "give me a new block." It is "resize my existing
        block, and keep what's inside." Copying the old values is part of its
        job.

        What realloc(ptr, new_size) guarantees

        It does one of two things:

            Grow in place. If there's free memory right after the current block, it
            just extends the block. The address stays the same, and the values never
            move.

            Move. If there isn't room, it:
                allocates a new block of new_size bytes somewhere else,
                copies the old contents into it (as many bytes as the old block had),
                frees the old block,
                returns the new address.

        (If it cannot find memory at all it returns NULL. This program does not
        check for that; with at most 1000 ints it will not happen in practice.)

        */

        arr[i] = num_array[i]; // the new last box (index i) gets the number just read
    }

    for(int i=0; i<N; i++){ // print all N numbers
        printf("%d ", arr[i]);
    }
    printf("\n"); // end the line

    free(arr); // give the heap memory back

    return 0; // program ended successfully
}
