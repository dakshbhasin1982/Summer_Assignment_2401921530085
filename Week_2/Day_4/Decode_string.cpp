#include <iostream>
#include <stack>
#include <string>
using namespace std;

string decodeString(string s)
{
    stack<int> numbers;
    stack<string> words;

    string current = "";
    int num = 0;

    for(int i = 0; i < s.length(); i++)
    {
        if(isdigit(s[i]))
        {
            num = num * 10 + (s[i] - '0');
        }
        else if(s[i] == '[')
        {
            numbers.push(num);
            words.push(current);

            num = 0;
            current = "";
        }
        else if(s[i] == ']')
        {
            int repeat = numbers.top();
            numbers.pop();

            string previous = words.top();
            words.pop();

            string temp = "";

            for(int j = 0; j < repeat; j++)
            {
                temp += current;
            }

            current = previous + temp;
        }
        else
        {
            current += s[i];
        }
    }

    return current;
}

int main()
{
    string s;
    cin >> s;

    cout << decodeString(s);

    return 0;
}