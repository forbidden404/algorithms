#include <bits/stdc++.h>

using namespace std;

struct Tree {
    int val;
    Tree *left, *right;
    Tree(int val) : val(val), left(nullptr), right(nullptr) {}
};

Tree *trimBST(Tree *root, int minVal, int maxVal) {
    if (root == nullptr) return nullptr;
    root->left = trimBST(root->left, minVal, maxVal);
    root->right = trimBST(root->right, minVal, maxVal);
    if (minVal <= root->val && root->val <= maxVal) return root;
    if (root->val < minVal) return root->right;
    if (root->val > maxVal) return root->left;
    return nullptr;
}

void levelOrderPrint(Tree* root) {
    if (root == nullptr) return;
    queue<Tree *> nodes;
    nodes.push(root);
    int currentCount = 1;
    int nextCount = 0;
    while (!nodes.empty()) {
        auto node = nodes.front(); nodes.pop();
        currentCount--;
        cout << node->val << " ";
        if (node->left != nullptr) {
            nodes.push(node->left);
            nextCount++;
        }
        if (node->right != nullptr) {
            nodes.push(node->right);
            nextCount++;
        }
        if (currentCount == 0) {
            cout << endl;
            swap(currentCount, nextCount);
        }
    }
    cout << endl;
}

int main() {
    auto root = new Tree(8);
    root->left = new Tree(3);
    root->right = new Tree(10);
    root->left->left = new Tree(1);
    root->left->right = new Tree(6);
    root->left->right->left = new Tree(4);
    root->left->right->right = new Tree(7);
    root->right->right = new Tree(14);
    root->right->right->left = new Tree(13);
    levelOrderPrint(root);
    trimBST(root, 5, 13);
    levelOrderPrint(root);
    return 0;
}