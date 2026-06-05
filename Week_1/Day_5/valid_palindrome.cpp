#include <iostream>
#include <string>
#include <cctype>
using namespace std;

bool validPalindrome(string str) {
    int start = 0;
    int end = str.length() - 1;

    while (start < end) {

        if (!isalnum(str[start])) {
            start++;
            continue;
        }

        if (!isalnum(str[end])) {
            end--;
            continue;
        }

        if (tolower(str[start]) != tolower(str[end])) {
            return false;
        }

        start++;
        end--;
    }

    return true;
}

int main() {
    string str;
    getline(cin, str);

    if (validPalindrome(str))
        cout << "true";
    else
        cout << "false";

    return 0;
}