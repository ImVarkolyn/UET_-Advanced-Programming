#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> a(n);

    for (int i=0;i<n;i++)
    {
        int x;
        cin >> x;
        a[i].resize(x);
        for (int j=0;j<x;j++)
        {
            cin >> a[i][j];
        }
    }

    for (int i=0;i<m;i++)
    {
        int aIndex, nIndex;
        cin >> aIndex >> nIndex;
        cout << a[aIndex][nIndex] << endl;
    }

    return 0;
}
