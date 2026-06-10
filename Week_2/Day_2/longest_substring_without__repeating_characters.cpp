 #include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        unordered_map<char, int> mp;
        int left = 0;
        int ans = 0;

        for (int right = 0; right < s.length(); right++) {

            char ch = s[right];

            if (mp.count(ch) && mp[ch] >= left) {
                left = mp[ch] + 1;
            }

            mp[ch] = right;

            ans = max(ans, right - left + 1);
        }

        return ans;
    }
};

int main() {
    Solution obj;

    string s;
    cin >> s;

    cout << obj.lengthOfLongestSubstring(s);

    return 0;
}