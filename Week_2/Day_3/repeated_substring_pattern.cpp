#include <iostream>
#include <string>
using namespace std;

bool hasRepeatedPattern(string s) {

    int n = s.size();

    for (int len = 1; len <= n / 2; len++) {

        if (n % len != 0) {
            continue;
        }

        string part = s.substr(0, len);
        string formed = "";

        int repeatCount = n / len;

        for (int i = 0; i < repeatCount; i++) {
            formed += part;
        }

        if (formed == s) {
            return true;
        }
    }

    return false;
}

int main() {

    string s;

    cout << "Enter string: ";
    cin >> s;

    if (hasRepeatedPattern(s)) {
        cout << "true";
    }
    else {
        cout << "false";
    }

    return 0;
}