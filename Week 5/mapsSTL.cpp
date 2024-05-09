#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */

    map<string, int> a;
    int q;
    cin >> q;

    while(q--){
        int m;
        cin >> m;

        if(m == 1){
            string n; cin >> n;
            int p; cin >> p;
            a[n] += p;
        }else if(m == 2){
            string n; cin >> n;
            a.erase(n);
        }else if(m == 3){
            string n; cin >> n;
            cout << a[n] << endl;
        }
    }
    return 0;
}
