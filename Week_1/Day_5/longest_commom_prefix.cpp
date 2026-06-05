#include <iostream>
#include <vector>
#include <string>
using namespace std;

string longestCommonPrefix(vector<string>& words) {

    if (words.size() == 0) {
        return "";
    }

    string answer = "";

    for (int i = 0; i < words[0].length(); i++) {

        char currentChar = words[0][i];

        for (int j = 1; j < words.size(); j++) {

            if (i >= words[j].length() || words[j][i] != currentChar) {
                return answer;
            }
        }

        answer += currentChar;
    }

    return answer;
}

int main() {

    int n;
    cin >> n;

    vector<string> words(n);

    for (int i = 0; i < n; i++) {
        cin >> words[i];
    }

    cout << longestCommonPrefix(words);

    return 0;
}