#include <bits/stdc++.h>

using namespace std;



int findPowerSum(int total, int power, int n)
{
    int value = (total - pow(n, power));
    if(value < 0) return 0;
    else if(value == 0) return 1;
    else return findPowerSum(value , power, n + 1) +
                findPowerSum(total, power, n + 1);
}
int main() {
    int total;
    int power;
    cin >> total;
    cin >> power;
    cout << findPowerSum(total, power, 1);
    return 0;
}


