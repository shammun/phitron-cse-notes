/*

https://www.naukri.com/code360/problems/left-sum_920380?leftPanelTabValue=PROBLEM

*/


#include <bits/stdc++.h> 
/*
	Tree Node class.

	class BinaryTreeNode 
	{
		T data;
		BinaryTreeNode<T> *left;
		BinaryTreeNode<T> *right;

		BinaryTreeNode(T data) {
			this->data = data;
			left = NULL;
			right = NULL;
		}
	}
*/


/*
 * Left sum: add up the values of every node that is a LEFT child of its parent.
 * (The root is nobody's child, so it is never counted.)
 *
 * The idea: visit every node with the level-order queue from this module.
 * When we take a node out of the queue we look at its children: if it has a
 * left child, that child is a left child by definition, so we add its value.
 * Both children still go into the queue so their own children get checked.
 *
 * Example: 1 with children 2 and 3, 2 has a left child 4, 3 has a right child 5.
 *   left children are 2 and 4, so the answer is 6.
 *
 * long long is used because many large values could overflow an int.
 */
long long leftSum(BinaryTreeNode<int> *root)
{
	// Write your code here.
	if(root == NULL) return 0;   // no tree, nothing to add
	long long sum = 0;           // running total of left-child values

	// The queue holds nodes waiting to be checked, oldest first.
	queue<BinaryTreeNode<int>*> q;
	q.push(root);

    while (!q.empty()) {
		// Take the next node out of the queue.
		BinaryTreeNode<int>* current = q.front();
		q.pop();

        // Its left child (if any) is a left child: count it, then queue it.
        if (current->left) {
			sum += current->left->data;
			q.push(current->left);
		}
        // A right child is not counted, but it may have left children below it.
        if (current->right) {
			q.push(current->right);
		}
	}
	return sum;
}