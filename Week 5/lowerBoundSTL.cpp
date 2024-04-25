#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        arr.push_back(x);
    }

    int m;
    cin >> m;

    while (m--) {

        int num;
        cin >> num;

        auto ans = lower_bound(arr.begin(), arr.end(), num);

        if(arr[ans - arr.begin()] == num){
            cout << "Yes" << " ";
            cout << ans - arr.begin() + 1 << '\n';
        }else{
            cout << "No" << " ";
            cout << ans - arr.begin() + 1 << '\n';
        }
    }
    return 0;
}
