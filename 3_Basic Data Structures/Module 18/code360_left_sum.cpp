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


long long leftSum(BinaryTreeNode<int> *root)
{
	// Write your code here.
	if(root == NULL) return 0;
	long long sum = 0;

	queue<BinaryTreeNode<int>*> q;
	q.push(root);

    while (!q.empty()) {
		BinaryTreeNode<int>* current = q.front();
		q.pop();

        if (current->left) {
			sum += current->left->data;
			q.push(current->left);
		}
        if (current->right) {
			q.push(current->right);
		}
	}
	return sum;
}