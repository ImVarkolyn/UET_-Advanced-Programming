#include <iostream>
#include <string>
using namespace std;

int main() {
	// Complete the program
    string s1;
    getline(cin,s1);
    string s2;
    getline(cin,s2);
    string smerge = s1+s2;
    int n1 = s1.length();
    int n2 = s2.length();
    char mid;
    mid = s1[0];
    s1[0] = s2[0];
    s2[0] = mid;
    cout << n1 << ' ' << n2 << endl;
    cout << smerge << endl;
    cout << s1 << ' ' << s2;
    return 0;
}
