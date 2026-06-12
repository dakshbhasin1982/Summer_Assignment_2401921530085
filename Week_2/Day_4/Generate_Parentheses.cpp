#include <iostream>
#include <vector>
#include <string>
using namespace std;

void generate(int left, int right, int n, string current, vector<string>& ans)
{
    if(left > n || right > n)
    {
        return;
    }

    if(right > left)
    {
        return;
    }

    if(left == n && right == n)
    {
        ans.push_back(current);
        return;
    }

    generate(left + 1, right, n, current + "(", ans);
    generate(left, right + 1, n, current + ")", ans);
}

int main()
{
    int n;
    cin >> n;

    vector<string> ans;

    generate(0, 0, n, "", ans);

    for(int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << endl;
    }

    return 0;
}