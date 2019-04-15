// There is an array of non-negative integers. A second array is formed by shuffling the 
// elements of the first array and deleting a random element. Given these two arrays,
// find which element is missing in the second array.
#include <bits/stdc++.h>

using namespace std;

int findMissingNumber1(vector<int>& arr1, vector<int>& arr2) {
    sort(arr1.begin(), arr1.end());
    sort(arr2.begin(), arr2.end());
    for (int i = 0; i < arr2.size(); i++) {
        if (arr1[i] != arr2[i]) return arr1[i];
    }
    return arr1[arr1.size()-1];
}

int findMissingNumber(vector<int>& arr1, vector<int>& arr2) {
    int result = 0;
    for (auto num : arr1) {
        result ^= num;
    }
    for (auto num : arr2) {
        result ^= num;
    }
    return result;
}

int main() {
    vector<int> arr1{4,1,0,2,9,6,8,7,5,3};
    vector<int> arr2{6,4,7,2,1,0,8,3,9};
    cout << findMissingNumber1(arr1, arr2) << endl;
    cout << findMissingNumber(arr1, arr2) << endl;
    return 0;
}
