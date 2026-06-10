#include <iostream>
#include <string>
using namespace std;

bool isSubsequence(string s, string t) {

    int i = 0;
    int j = 0;

    while (i < s.size() && j < t.size()) {

        if (s[i] == t[j]) {
            i++;
        }

        j++;
    }

    return i == s.size();
}

int main() {

    string s, t;

    cout << "Enter s: ";
    cin >> s;

    cout << "Enter t: ";
    cin >> t;

    if (isSubsequence(s, t)) {
        cout << "true";
    } else {
        cout << "false";
    }

    return 0;
} 