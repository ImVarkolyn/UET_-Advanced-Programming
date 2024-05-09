#include <bits/stdc++.h>

using namespace std;

void generateStrings(const vector<char>& letters, string current, int length) {
    if (length == 0) {
        cout << current << endl;
        return;
    }

    for (char letter : letters) {
        generateStrings(letters, current + letter, length - 1);
    }
}

int main() {
    vector<char> letters = {'a', 'b', 'c', 'd'};
    int length = 3;

    generateStrings(letters, "", length);

    return 0;
}

