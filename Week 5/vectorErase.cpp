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
    vector<int> v;
    for (int i=0 ;i<n; i++)
    {
        int x;
        cin >> x;
        v.push_back(x);
    }
    int index;
    cin >> index;
    v.erase(v.begin()+index-1);
    int left, right;
    cin >> left >> right;
    v.erase(v.begin()+left-1,v.begin()+right-1);
    cout << v.size() << endl;
    for (int i=0;i<v.size();i++)
    {
        cout << v[i] << ' ';
    }
    return 0;
}
