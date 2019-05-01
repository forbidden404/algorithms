#include <bits/stdc++.h>

using namespace std;

struct Tree {
    int val;
    Tree *left, *right;
    Tree(int val) : val(val), left(nullptr), right(nullptr) { }
};

void reverseLevelOrderPrint(Tree* root) {
    if (root == nullptr) return;

    stack <Tree *> s;
    queue <Tree *> q; 
    q.push(root);

    int currentCount = 1, nextCount = 0;
    while (!q.empty()) {
        auto node = q.front(); q.pop();
        s.push(node);
        currentCount--;

        if (node->right) {
            q.push(node->right);
            nextCount++;
        }

        if (node->left) {
            q.push(node->left);
            nextCount++;
        }

        if (currentCount == 0 && nextCount != 0) s.push(nullptr);
        swap(currentCount, nextCount);
    }

    while (!s.empty()) {
        auto node = s.top(); s.pop();
        if (node == nullptr) cout << endl;
        else cout << node->val << " ";
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
    reverseLevelOrderPrint(root);
    return 0;
}