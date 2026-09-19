/*

https://leetcode.com/problems/minimum-deletions-to-make-character-frequencies-unique/

1647. Minimum Deletions to Make Character Frequencies Unique

Problem (in my own words)

A string is called "good" when no two different letters appear the same number of times.
For example "aab" is good: a appears twice, b appears once, and 2 is not 1. But "aabb" is
not good, because a and b both appear twice.

You are given a lowercase string s. You may delete characters, one at a time, anywhere in
the string. Find the smallest number of deletions that makes the string good.

A letter that disappears completely does not count as a frequency, so several letters are
allowed to end up at count 0.

Input Format
One line: the string s, made of lowercase English letters only.

Output Format
One number: the minimum number of deletions.

Constraints
The string is non-empty and contains only the 26 lowercase English letters.

Sample Input 0
aaabbbcc

Sample Output 0
2

Explanation 0
a appears 3 times, b appears 3 times, c appears 2 times.
Sort the counts from big to small: 3, 3, 2.
The first 3 may stay. The second 3 clashes with it, so delete one b and it becomes 2.
But 2 is now taken by that b, so the c with count 2 must drop to 1 - one more deletion.
Counts end up 3, 2, 1, all different, after 2 deletions.

Sample Input 1
ceabaacb

Sample Output 1
2

Explanation 1
Counts: a 3, b 2, c 2, e 1. Sorted big to small: 3, 2, 2, 1.
3 stays, the first 2 stays, the second 2 must fall to 1 (one deletion), and then the letter
with count 1 must fall to 0 (one more deletion). Total 2.

*/

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minDeletions(string s) {
        /* Only 26 letters exist, so a plain frequency array is enough - no map needed. */
        int freq[26] = {0};
        for (int i = 0; i < (int)s.size(); i++) {
            freq[s[i] - 'a']++;
        }

        /* Keep only the letters that actually show up. A letter with count 0 was never
           there, so it can never clash with anything. */
        vector<int> counts;
        for (int i = 0; i < 26; i++) {
            if (freq[i] > 0) {
                counts.push_back(freq[i]);
            }
        }

        /* Biggest first. The idea is the same greedy as "Here Comes the Genie": the biggest
           count should be allowed to stay the biggest, because lowering a big count costs
           exactly as much as lowering a small one, and leaving big values high keeps more
           room free underneath for everybody else. */
        sort(counts.begin(), counts.end(), greater<int>());

        int deletions = 0;
        int allowed = counts[0];  // the first count is free to keep everything it has

        for (int i = 0; i < (int)counts.size(); i++) {
            /* This letter may keep at most `allowed` characters. If it already has fewer,
               it keeps all of them; every extra character above the cap is a deletion. */
            int keep = counts[i];
            if (keep > allowed) {
                keep = allowed;
            }
            deletions += counts[i] - keep;

            /* The value `keep` is now used up, so the next letter must go one lower.
               Zero is the floor: any number of letters may end at 0 together. */
            allowed = keep - 1;
            if (allowed < 0) {
                allowed = 0;
            }
        }

        return deletions;
    }
};

int main() {
    string s;
    cin >> s;

    Solution sol;
    cout << sol.minDeletions(s) << endl;

    return 0;
}
