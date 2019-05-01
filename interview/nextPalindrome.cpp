#include <bits/stdc++.h>

using namespace std;

pair<string, char> getLeftHalfAndMiddle(int num) {
    string str = to_string(num);
    string left = str.substr(0, str.size() / 2);
    return make_pair(left, str[str.size()-1 / 2]);
}

int roundUp(int num) {
    int length = to_string(num).size();
    double increment = pow(10, ((length/2) + 1));
    return ((num/increment) + 1) * increment;
}

int nextPalindrome(int num) {
    int length = to_string(num).size();
    bool oddDigits = length % 2 != 0;
    auto p = getLeftHalfAndMiddle(num);
    auto leftHalf = p.first;
    auto leftHalfRev = leftHalf;
    reverse(leftHalfRev.begin(), leftHalfRev.end());
    auto middle = p.second;

    double newNum = 0;
    double increment = 0;
    if (oddDigits) {
        increment = pow(10, length/2);
        newNum = stoi(leftHalf + middle + leftHalfRev);
    } else {
        increment = (1.1 * pow(10, length/2));
        newNum = stoi(leftHalf + leftHalfRev);
    }

    if (newNum > num) return newNum;
    if (middle != '9') return newNum + increment;
    else return nextPalindrome(roundUp(num));
}

int main() {
    int a = 1091;
    cout << nextPalindrome(a) << endl;
    return 0;
}