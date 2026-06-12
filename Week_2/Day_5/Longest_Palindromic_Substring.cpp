#include <iostream>
#include <string>
using namespace std;

string longestPalindrome(string s)
{
    int n = s.length();

    int start = 0;
    int maxLength = 1;

    for(int i = 0; i < n; i++)
    {
        // Odd length palindrome
        int left = i;
        int right = i;

        while(left >= 0 && right < n && s[left] == s[right])
        {
            if(right - left + 1 > maxLength)
            {
                maxLength = right - left + 1;
                start = left;
            }

            left--;
            right++;
        }

        // Even length palindrome
        left = i;
        right = i + 1;

        while(left >= 0 && right < n && s[left] == s[right])
        {
            if(right - left + 1 > maxLength)
            {
                maxLength = right - left + 1;
                start = left;
            }

            left--;
            right++;
        }
    }

    return s.substr(start, maxLength);
}

int main()
{
    string s;
    cin >> s;

    cout << longestPalindrome(s);

    return 0;
}