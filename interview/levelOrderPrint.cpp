#include <bits/stdc++.h>

using namespace std;

struct Tree {
    int val;
    Tree *left, *right;

    Tree(int val) : val(val), left(nullptr), right(nullptr) { }
};

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
    auto root = new Tree(1);
    root->left = new Tree(2);
    root->left->left = new Tree(4);
    root->right = new Tree(3);
    root->right->left = new Tree(5);
    root->right->right = new Tree(6);
    levelOrderPrint(root);
    return 0;
}