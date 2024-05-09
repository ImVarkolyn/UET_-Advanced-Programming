/// Recursive binary search

#include <bits.stdc++.h>

using namespace std;

int binarySearch(const vector<int>& arr, int n, int low, int high) {
    if (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == n) {
            return mid;
        } else if (arr[mid] < n) {
            return binarySearch(arr, target, mid + 1, high);
        } else {
            return binarySearch(arr, target, low, mid - 1);
        }
    }
    return -1;
}

int main() {
    vector<int> arr = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20};
    int n = 10;

    int result = binarySearch(arr, target, 0, arr.size() - 1);

    if (result != -1) {
        cout << "Found at number index: " << result << endl;
    } else {
        cout << "Not found" << endl;
    }

    return 0;
}
