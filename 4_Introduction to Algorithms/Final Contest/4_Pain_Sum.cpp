/*

Pain Sum

Problem Statement

There is a sequence of length N, the property of the sequence is -

- N >= 3 and N is a multiple of 3.
- Sorted in non-decreasing order.
- Each element appears exactly thrice from 1 to N/3.

You are given the value N and you are also given Q queries, where each query consists of two integers L and R. 
For each query, you need to find the sum of the elements in the sequence from position L to R.

Note: A multiple of 3 is any integer that can be expressed as 3k, where k is an integer. For example: 
3,6,9,12,15 etc. are all multiples of 3.

Input Format
- The first line will contain a single positive integer N and Q, the length of the sequence and the number of 
queries respectively.
- Next Q lines will contain L and R.

Constraints
- 3 <= N <= 10^9
- 1 <= Q <= 2 X 10^5
- 1 <= L <= R <= N

Output Format
For each query find the sum of the elements in the sequence from position L to R. Don't forget to print a 
newline after each query.

Sample Input 0
9 3
2 9
2 6
7 9

Sample Output 0
17
8
9

Explanation 0
In the given test case N = 9 . So the sequence will be [1,1,1,2,2,2,3,3,3]. Now for first query L = 2 and 
R = 9, it represents the values [1,1,2,2,2,3,3,3] which belongs from the position L = 2 to R = 9 
(considering 1-base indexing) and hence the sum of 1+1+2+2+2+3+3+3 = 17 for the first query.

*/



