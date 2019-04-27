#include <bits/stdc++.h>

using namespace std;

bool isBalanced(string expr) {
    if (expr.size() % 2 != 0) return false;
    unordered_set<char> opening;
    opening.insert('(');
    opening.insert('[');
    opening.insert('{');

    unordered_set<string> match;
    match.insert("()");
    match.insert("[]");
    match.insert("{}");
    
    stack<char> st;
    for (char c : expr) {
        if (opening.find(c) != opening.end()) {
            st.push(c);
        } else {
            if (st.empty()) return false;
            char lastOpen = st.top(); st.pop();
            string s{lastOpen, c};
            if (match.find(s) == match.end()) return false;
        }
    }

    return st.empty();
}

int main() {
    string expr = "(([]){})";
    if (isBalanced(expr)) {
        cout << expr << " is balanced" << endl;
    } else {
        cout << expr << " is not balanced" << endl;
    }
    return 0;
}
