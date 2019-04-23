#include <bits/stdc++.h>

using namespace std;

struct Node {
    int val;
    Node *next;
};

void removeNodes(Node *head, int rmv) {
    while (head != nullptr && head->val == rmv) {
        auto temp = head;
        head = head->next;
        free(temp);
    }
    if (head == nullptr) return;

    auto current = head;
    while (current->next != nullptr) {
        if (current->next->val == rmv) {
            auto temp = current->next;
            current->next = temp->next;
            free(temp);
        } else {
            current = current->next;
        }
    }
}
