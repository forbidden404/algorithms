#include <bits/stdc++.h>

using namespace std;

vector<string> helper(string digits, unordered_map<char, string>& map) {
    vector<string> answer;
    if (digits.size() == 1) {
        for (auto c : map[digits[0]]) {
            string s(1, c);
            answer.push_back(s);
        }
        return answer;
    }

    cout << "helper(" << digits << ")" << endl;

    auto v = helper(digits.substr(1), map);
    auto input = map[digits[0]];
    for (auto c : input) {
        if (!v.empty()) {
            for (auto s : v) {
                answer.push_back(c + s);
            }    
        } else {
            string s(1, c);
            answer.push_back(s);
        }
    }

    return answer;
}

vector<string> letterCombinations(string digits) {
    unordered_map<char, string> map;
    map['0'] = ""; 
    map['1'] = "";
    map['2'] = "abc";
    map['3'] = "def";
    map['4'] = "ghi";
    map['5'] = "jkl";
    map['6'] = "mno";
    map['7'] = "pqrs";
    map['8'] = "tuv";
    map['9'] = "wxyz";

    return helper(digits, map);
}

int main() {
    string s = "23";
    auto v = letterCombinations(s);
    for (auto c : v) {
        cout << c << " ";
    }
    cout << endl;
}
