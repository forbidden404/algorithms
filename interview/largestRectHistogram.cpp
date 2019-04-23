#include <bits/stdc++.h>

using namespace std;

int maxArea(vector<int>& A) {
    stack<int> s;
    int area = 0;
    int i = 0;
    while (i < A.size()) {
        if (s.empty() || A[s.top()] <= A[i]) {
            s.push(i);
            i++;
        } else {
            int curMax = s.top();
            s.pop();
            int curArea = A[curMax] * (s.empty() ? i : (i - 1 - s.top()));
            area = max(area, curArea); 
        }
    }

    while (!s.empty()) {
        int curMax = s.top();
        s.pop();
        int curArea = A[curMax] * (s.empty() ? i : (i - 1 - s.top()));
        area = max(area, curArea);
    }

    return area;
}

int main() {
    vector<int> v{1,2,3,4,5,3,3,2};
    cout << maxArea(v) << endl;
    return 0;
}
