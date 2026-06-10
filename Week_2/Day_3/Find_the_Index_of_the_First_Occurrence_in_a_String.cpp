#include <iostream>
#include <string>
using namespace std;

int findFirstOccurrence(string text, string pattern) {

    int textLength = text.size();
    int patternLength = pattern.size();

    for (int start = 0; start <= textLength - patternLength; start++) {

        int matched = 0;

        while (matched < patternLength &&
               text[start + matched] == pattern[matched]) {

            matched++;
        }

        if (matched == patternLength) {
            return start;
        }
    }

    return -1;
}

int main() {

    string haystack, needle;

    cout << "Enter haystack: ";
    cin >> haystack;

    cout << "Enter needle: ";
    cin >> needle;

    cout << findFirstOccurrence(haystack, needle);

    return 0;
}