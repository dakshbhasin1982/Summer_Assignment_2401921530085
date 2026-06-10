#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {

        vector<int> ans;

        int n = s.length();
        int m = p.length();

        if (m > n) {
            return ans;
        }

        vector<int> freqP(26, 0);
        vector<int> freqS(26, 0);

        for (int i = 0; i < m; i++) {
            freqP[p[i] - 'a']++;
            freqS[s[i] - 'a']++;
        }

        if (freqP == freqS) {
            ans.push_back(0);
        }

        for (int i = m; i < n; i++) {

            freqS[s[i] - 'a']++;

            freqS[s[i - m] - 'a']--;

            if (freqP == freqS) {
                ans.push_back(i - m + 1);
            }
        }

        return ans;
    }
};
int main() {

    Solution obj;

    string s, p;

    cout << "Enter s: ";
    cin >> s;

    cout << "Enter p: ";
    cin >> p;

    vector<int> ans = obj.findAnagrams(s, p);

    for (int index : ans) {
        cout << index << " ";
    }

    return 0;
}