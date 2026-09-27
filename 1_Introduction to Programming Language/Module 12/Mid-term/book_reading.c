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

/* Idea (greedy): the books are already sorted from shortest to longest, so
   reading the shortest ones first finishes the most books. Keep adding book
   times to a running total and stop at the first book that no longer fits. */

#include <stdio.h>  // standard input/output library: scanf and printf
#include <string.h> // string functions (part of the HackerRank template; not used here)
#include <math.h>   // math functions (template; not used here)
#include <stdlib.h> // general utilities (template; not used here)

int main() { // program execution starts here

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int N; // number of books
    /* T can be 10^9 and the running total of reading times can pass what an
       int holds, so both totals are long long.
       (An int stops at about 2.1 * 10^9; adding up to 10^5 book times can
       easily go past that. long long goes up to about 9.2 * 10^18.) */
    long long T; // total time Babul has
    /* A fixed array big enough for the largest N (10^5). */
    int times[100000];
    long long total_time = 0; // sum of the times of the books read so far
    int number_of_books = 0; // how many books fit so far (the answer)

    scanf("%d %lld", &N, &T); // %d reads an int, %lld reads a long long; & gives scanf each variable's address

    /* Read the N book times into times[0] .. times[N-1]; one pass reads one time. */
    for(int i=0; i < N; i++){
        scanf("%d", &times[i]); // store the next time in slot i
    }

    /* The times come sorted from shortest to longest, so the best plan is
       greedy: read the shortest books first. Add the books one by one to a
       running total; as long as the total still fits into T, that book is
       finished and counted. The first book that does not fit ends the
       search - every later book is at least as long, so none of them could
       fit either.
       Trace with T = 33 and times 1 3 4 6 8 10 ...: totals 1, 4, 8, 14, 22, 32 all fit (6 books),
       then 32 + 12 = 44 > 33 -> stop -> answer 6. */
    for(int i=0; i < N; i++){
        total_time += times[i]; // "+=" means total_time = total_time + times[i]
        if(total_time <= T){ // still within the available time: this book is finished
            number_of_books = number_of_books + 1; // count it
        } else{ // this book does not fit
            break; // leave the loop; no later (longer) book can fit either
        }
    }

    printf("%d", number_of_books); // print the answer

    return 0; // program ended successfully
}
