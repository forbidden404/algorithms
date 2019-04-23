#include <bits/stdc++.h>

using namespace std;

unordered_map<string, int> cache;
void precompute(string text) {
    int start = 0;
    int end = 0;
    for (int i = 0; i < text.size(); i++) {
        if (text[i] == ' ') {
            if (start != end) {
                cache[text.substr(start, end - start)]++; 
            }
            start = i;
            end = i;
        } else {
            end++;
        }

        if (i == text.size() - 1) {
            cache[text.substr(start)]++;
        }
    }
}

int frequency(string word) {    
    return cache[word];
}

int main() {

}
