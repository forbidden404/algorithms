#include <bits/stdc++.h>

using namespace std;

string smalls[] = {
    "Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen",
    "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"
};

string tens[] = {
    "", "", "Twenty", "Thirsty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"
};

string bigs[] = {
    "", "Thousand", "Million", "Billion"
};

string hundred = "Hundred";
string negative = "Negative";

string convertChunk(int);
string convert(int num) {
    if (num == 0)
        return smalls[0];
    else if (num < 0) 
        return negative + " " + convert(-1 * num);

    string answer = "";
    int chunkCount = 0;

    while (num > 0) {
        if (num % 1000 != 0) {
            answer = convertChunk(num % 1000) + bigs[chunkCount] + " " + answer;
        }
        num /= 1000;
        chunkCount++;
    }

    return answer;
}

string convertChunk(int num) {
    string answer = "";

    if (num >= 100) {
        answer += smalls[num / 100] + " ";
        answer += hundred + " ";
        num %= 100;
    }

    if (num >= 10 && num <= 19) {
        answer += smalls[num] + " ";
    } else if (num >= 20) {
        answer += tens[num / 10] + " ";
        num %= 10;
    }

    if (num >= 1 && num <= 9)
        answer += smalls[num] + " ";

    return answer;
}

int main() {
    int i;
    cin >> i;
    cout << convert(i) << endl;
}