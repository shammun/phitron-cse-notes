/*

https://leetcode.com/problems/same-tree/description/

Same Tree (LeetCode 100)
Given the roots of two binary trees, say whether they are the same: the same
shape, with the same value in every matching position.

Examples:
    [1,2,3] and [1,2,3]     -> true
    [1,2]   and [1,null,2]  -> false  (2 is a left child in one, right in the other)
    [1,2,1] and [1,1,2]     -> false  (same shape, values in different places)

This file only holds the problem. It is solved twice in this module:
    leetcode_same_tree_version1.cpp  - write both trees as lists (with markers
                                       for empty places) and compare the lists
    leetcode_same_tree_version2.cpp  - compare the two trees node by node
                                       with recursion

*/
