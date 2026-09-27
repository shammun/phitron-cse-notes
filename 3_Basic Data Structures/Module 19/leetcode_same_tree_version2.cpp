/*

https://leetcode.com/problems/same-tree/

*/

/*
 * Same tree, version 2: compare the two trees directly, node by node.
 *
 * The idea ("ask both children, combine with &&"): two trees are the same if
 * both are empty, or if both roots hold the same value AND their left
 * subtrees are the same AND their right subtrees are the same.
 * No extra vector is needed, and the && stops at the first difference.
 *
 * Example: [1,2,3] vs [1,2,3] -> true;  [1,2] vs [1,null,2] -> false.
 */
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {

        // Both empty: nothing to differ.
        if(p == NULL && q == NULL){
            return true;
        }
    
        // Exactly one is empty: different shapes.
        if(p == NULL || q == NULL){
            return false;
        }

        // Both exist: same value here, and the same on both sides below.
        return p->val == q->val && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};
