/*

Here Comes The Genie_

Problem Statement

Here comes the genie with  bags. The -th bag contains  balls of color . Your goal is to collect as many 
balls as possible. However, the genie has a condition: the number of balls you take from each color must 
be distinct. More formally, if you take  balls of color  where , then you cannot take  balls of another 
color .

For example, suppose n = 3 and a = [1, 2, 4].

You can take c = [1, 2, 3] or c = [1, 2, 4]. However, you cannot take c = [1, 2, 2] or c = [1, 1, 4], as 
these sets violate the condition of having distinct elements.

It's acceptable to take 0 balls from multiple bags. For instance, c = [0, 0, 1] or c = [1, 1, 4] are valid.

Now, you ask yourself: What is the maximum number of balls that you can collect?

Input Format

- First line contains n
- Next line contains the array a_1, a_2, a_3, ..., a_n

Constraints
1 <= n <= 2X10^5
1 <= a_i <= 10^9

Output Format
Output the maximum number of balls that you can collect.

Sample Input 0
4
1 1 2 1

Sample Output 0
3

Sample Input 1
3
1 4 5

Sample Output 1
10

Sample Input 2
4
5 1 1 4

Sample Output 2
10

*/