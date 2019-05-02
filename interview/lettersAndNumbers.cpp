#include <bits/stdc++.h>

using namespace std;

bool isLetter(char c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

bool isDigit(char c) {
    return (c >= '0' && c <= '9');
}

bool hasEqualLettersNumbers(vector<char> &array, int start, int end) {
    int counter = 0;
    for (auto c : array) {
        if (isLetter(c))
            counter++;
        else if (isDigit(c))
            counter--;
    }
    return counter == 0;
}

vector<char> extractSubarray(vector<char>& array, int start, int end) {
    vector<char> subarray(end - start + 1);
    for (int i = start; i <= end; i++) {
        subarray[i - start] = array[i];
    }
    return subarray;
}

vector<char> findLongestSubarray(vector<char>& array) {
    for (int i = array.size(); i > 1; i--) {
        for (int j = 0; j <= array.size() - i; j++) {
            if (hasEqualLettersNumbers(array, j, j + i - 1))
                return extractSubarray(array, j, j + i - 1);
        }
    }
    return {};
}

vector<int> computeDeltaArray(vector<char>& array) {
    vector<int> deltas;
    int delta = 0;
    for (auto c : array) {
        if (isLetter(c)) delta++;
        else if (isDigit(c)) delta--;
        deltas.push_back(delta);
    }
    return deltas;
}

vector<int> findLongestMatch(vector<int>& deltas) {
    unordered_map<int, int> map;
    map[0] = -1;
    vector<int> max(2);
    for (int i = 0; i < deltas.size(); i++) {
        if (map.find(deltas[i]) == map.end())
            map[deltas[i]] = i;
        else {
            int match = map[deltas[i]];
            int distance = i - match;
            int longest = max[1] - max[0];
            if (distance > longest) {
                max[1] = i;
                max[0] = match;
            }
        }
    }
    return max;
}

vector<char> findLongestSubarray2(vector<char> array) {
    auto deltas = computeDeltaArray(array);
    auto match = findLongestMatch(deltas);
    return extractSubarray(array, match[0] + 1, match[1]);
}

int main() {
    vector<char> v{'a','a','a','a','1','1','a','1','1','a','a','1','a','a','1','a','a','a','a'};
    auto answer = findLongestSubarray2(v);
    for (auto c : answer) { cout << c << " "; }
    cout << endl;
    return 0;
}