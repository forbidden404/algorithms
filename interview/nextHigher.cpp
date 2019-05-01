#include <bits/stdc++.h>

using namespace std;

int nextHigher(int num) {
    auto strNum = to_string(num);
    auto length = strNum.size();
    for (int i = length - 2; i >= 0; i--) {
        if (strNum[i] < strNum[i+1]) {
            int numDigits = length - (i + 1);
            int digits[numDigits];
            for (int j = 0; j < numDigits; j++) 
                digits[j] = strNum[j + (i + 1)] - '0';

            sort(digits, digits+numDigits);

            int oldPivot = strNum[i] - '0';
            for (int j = 0; j < numDigits; j++) {
                if (digits[j] > oldPivot) {
                    strNum[i] = digits[j] + '0';
                    digits[j] = oldPivot;
                    break;
                }
            }

            for (int j = 0; j < numDigits; j++) {
                strNum[j + (i + 1)] = digits[j] + '0';
            }
            break;
        }
    }

    return stoi(strNum);
}

int main() {
    int num = 12543;
    cout << "Number: " << num << endl;
    cout << "Next higher number: " << nextHigher(num) << endl;

    num = 13542;
    cout << "Number: " << num << endl;
    cout << "Next higher number: " << nextHigher(num) << endl;

    num = 136442;
    cout << "Number: " << num << endl;
    cout << "Next higher number: " << nextHigher(num) << endl;

    num = 776442;
    cout << "Number: " << num << endl;
    cout << "Next higher number: " << nextHigher(num) << endl;

    return 0;
}