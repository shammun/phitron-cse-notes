/*

Max

Problem Statament

You are given an empty array initially. Then, you will be given Q queries to perform on this array. You will 
be given 2 types of queries to perform.

- 1 X - add  to the array.
- 2 - If the array is empty print empty otherwise print the element which occurrence is maximum , if there 
exist multiple element with maximum occurrence print the largest value which occurrence is maximum and erase 
max (1, ⌊total occurrences of that element / 2⌋) occurrences of that value.

Here, ⌊x⌋ represents the largest integer less than or equal to a given number x. For example : ⌊5/2⌋ = ⌊2.5⌋ = 2

It is guaranteed that at least one type 2 query will be present in all the test case.

Note: The input file is too large. Must use fast I/O and don't use endl. Use "\n" instead of endl.

Fast I/O: Add these 2 lines at the first of main function -

ios::sync_with_stdio(false);
cin.tie(nullptr);

Input Format

- The first line contains a single positive integer Q.
- The next Q lines will contains the queries.

Constraints
- 1 <= Q <= 10^5
- 1 <= X <= 10^9


Output Format
If the query type is 2 print the desired output as written in the problem statement. Dont' forget to print a 
newline after each test case.

Sample Input 0
12
2
1 12
1 10
1 12
1 12
1 10
1 12
1 10
1 10
2
1 15
2

Sample Output 0
empty
12
10

Explanation 0
During the first 2 type of query, the array is empty so you must print empty. For the next 2 type of query, 
10 appears 4 times and 12 also appears 4 times. Since their occurrences are the same you must print 12 because 
it is greater than 10. After printing 12, remove ⌊4/2⌋ = 2 means erase 2 occurrences of 12.

*/


