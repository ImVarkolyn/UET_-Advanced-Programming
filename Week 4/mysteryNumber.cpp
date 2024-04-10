#include <bits/stdc++.h>

using namespace std;

int mysteryNumber (const vector<int>& a, const vector<int>& b)
{
     int sumA=0, sumB=0;
     for (int i : a)
        sumA+=i;
     for (int i : b)
        sumB+=i;
     return sumB-sumA;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n; cin >> n;

    vector<int> a(n);
    vector<int> b(n+1);
    for (int i=0; i<n; i++)
    {
        int x; cin >> x;
        a.push_back(x);
    }
    for (int i=0; i<(n+1); i++)
    {
        int x; cin >> x;
        b.push_back(x);
    }
    cout << mysteryNumber(a,b) << endl;
    return 0;
}
