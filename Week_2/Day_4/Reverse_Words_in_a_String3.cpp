#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string reverseWordsInSentence(string s)
{
    int start = 0;

    for(int i = 0; i <= s.length(); i++)
    {
        if(i == s.length() || s[i] == ' ')
        {
            reverse(s.begin() + start, s.begin() + i);
            start = i + 1;
        }
    }

    return s;
}

int main()
{
    string s;

    getline(cin, s);

    cout << reverseWordsInSentence(s);

    return 0;
}