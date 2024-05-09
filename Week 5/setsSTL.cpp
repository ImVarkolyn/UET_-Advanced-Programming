#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int q;
    cin >> q;

    set<int> s;

    while (q--) {
        int type, num;
        cin >> type >> num;

        if (type == 1) {
            s.insert(num);
        } else if (type == 2) {
            s.erase(num);
        } else if (type == 3) {
            if (s.find(num) != s.end()) {
                cout << "Yes" << endl;
            } else {
                cout << "No" << endl;
            }
        }
    }

    return 0;
}





