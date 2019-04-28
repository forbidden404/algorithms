#include <bits/stdc++.h>

using namespace std;

int getIndex(vector<int> &arr, int num) {
    int index =  0, exp = 0;
    while (true) {
        try {
            if (arr.at(index) == num) {
                return index;
            } else if (arr.at(index) < num) {
                index = int(pow(2, exp));
                exp++;
            } else {
                break;
            }
        } catch (const std::out_of_range& oor) {
            break;
        }
    }

    int left = (index/2) + 1;
    int right = index - 1;
    while (left <= right) {
        int middle = left + (right - left) / 2;
        try {
            if (arr.at(middle) == num) return middle;
            else if (arr.at(middle) < num) left = middle + 1;
            else right = middle - 1;
        } catch (const std::out_of_range& oor) {
            right = middle - 1;
        }
    }

    return -1;
}

int main() {
    vector<int> v{1, 2, 3, 4, 5, 6, 7, 8, 10, 15, 19, 23, 44, 75};
    int index = getIndex(v, 44);
    if (index != -1)
        cout << v[index] << endl;
    else
        cout << "Couldn't find 44 in array." << endl;

    return 0;
}