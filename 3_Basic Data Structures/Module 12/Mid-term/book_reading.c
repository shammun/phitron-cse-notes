/*

Babul likes to read books. He has N books and they take different times to finish each. He has arranged all the books in a order of finishing time to read them. So the first book will need the least time to finish and the last book will take the most time. He as T time to read.

He has given how a list of N number in increasing order. The numbers are the times to finish the books.

You have to tell him how many books he can finish reading at most in T time.

Input Format

The first line of input will contain two integers N and T, the number of books and the time he has in total. The next line will contain N numbers in increasing order.

Constraints

1 <= N <= 10^5
0 <= T <= 10^9
Output Format

Print a single integer, the maximum number of books babul can finish reading in T time.

Sample Input 0

10 33
1 3 4 6 8 10 12 15 23 36
Sample Output 0

6

*/



#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    /* The idea: the times are already sorted from shortest to longest, so
     * reading the short books first finishes as many as possible. Add the
     * times one by one; as long as the running total fits in T, that book
     * is finished. The first book that does not fit ends it - every book
     * after it is even longer.
     * Sample: 1+3+4+6+8+10 = 32 <= 33, adding 12 gives 44 > 33 -> 6 books.
     *
     * total_time is a long long: up to 10^5 books can add up to far more
     * than an int holds. */
    int N;
    long long T;
    int times[100000];
    long long total_time = 0;
    int number_of_books = 0;
    
    scanf("%d %lld", &N, &T);
    
    /* Read the N reading times. */
    for(int i=0; i < N; i++){
        scanf("%d", &times[i]);
    }
    
    for(int i=0; i < N; i++){
        total_time += times[i];      /* time needed to finish books 0..i */
        if(total_time <= T){
            number_of_books = number_of_books + 1;   /* this one fits too */
        } else{
            /* Out of time: the remaining books are longer still. */
            break;
        }
    }
    
    printf("%d", number_of_books);
    
    return 0;
}
