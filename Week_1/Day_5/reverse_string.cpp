#include <iostream>
#include <vector>
using namespace std;

void reverseString(vector<char>& letters) {
    int size = letters.size();

    for (int position = 0; position < size / 2; position++) {

        char temp = letters[position];
        letters[position] = letters[size - 1 - position];
        letters[size - 1 - position] = temp;
    }
}

int main() {
    int n;
    cin >> n;

    vector<char> letters(n);

    for (int index = 0; index < n; index++) {
        cin >> letters[index];
    }

    reverseString(letters);

    for (char ch : letters) {
        cout << ch << " ";
    }

    return 0;
}