//Given a binary tree, check whether it's a binary search tree or not.
#include <bits/stdc++.h>

using namespace std;

struct Node {
    int val;
    Node *left, *right;

    Node(int val) : val(val), left(nullptr), right(nullptr) { } 
};

bool isBST(Node *root, int minVal=INT_MIN, int maxVal=INT_MAX) {
    if (root == nullptr) return true;
    if (!(minVal <= root->val && root->val <= maxVal))
        return false;

    return isBST(root->left, minVal, root->val) && isBST(root->right, root->val, maxVal);
}

int main() {
    auto root = new Node(3);
    auto left = new Node(2);
    auto right = new Node(5);
    root->left = left;
    root->right = right;

    auto lleft = new Node(1);
    auto lright = new Node(4);
    left->left = lleft;
    left->right = lright;

    if (isBST(root)) {
        cout << "Binary Tree with root " << root->val << " is a BST" << endl;
    } else {
        cout << "Binary Tree with root " << root->val << " isn't a BST" << endl;
    }
}
