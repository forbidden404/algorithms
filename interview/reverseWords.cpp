#include <bits/stdc++.h>

using namespace std;

void reverseString(string& text, int start, int end, int destination) {
    int length = end - start + 1;
    text.replace(destination, length, text.substr(start, length));
    for (int i = 0; i < length/2; i++) {
        swap(text[destination+i], text[destination+length-1-i]);
    }
}

void reverseWord(string& text) {
    int length = text.size();
    reverseString(text, 0, length - 1, 0);
    int read = 0, write = 0;
    while (read < length) {
        if (text[read] != ' ') {
            int wordStart = read;
            for (; read < length && text[read] != ' '; read++);
            reverseString(text, wordStart, read-1, write);
            write += read - wordStart;
            text[write++] = ' ';
        }
        read++;
    }
    text.erase(write-1);
}

int main() {
    string s1 = "Interviews are awesome!";
    reverseWord(s1);
    string s2 = "    CS degree ";
    reverseWord(s2);
    cout << s1 << endl;
    cout << s2 << endl;
    return 0;
}
