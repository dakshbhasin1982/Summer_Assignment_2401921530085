#include <iostream>
#include <vector>
#include <string>
using namespace std;

int compress(vector<char>& chars)
{
    int write = 0;
    int read = 0;
    int n = chars.size();

    while(read < n)
    {
        char current = chars[read];
        int count = 0;

        while(read < n && chars[read] == current)
        {
            count++;
            read++;
        }

        chars[write] = current;
        write++;

        if(count > 1)
        {
            string freq = to_string(count);

            for(int i = 0; i < freq.length(); i++)
            {
                chars[write] = freq[i];
                write++;
            }
        }
    }

    return write;
}

int main()
{
    int n;
    cin >> n;

    vector<char> chars(n);

    for(int i = 0; i < n; i++)
    {
        cin >> chars[i];
    }

    int newLength = compress(chars);

    cout << "Length = " << newLength << endl;

    for(int i = 0; i < newLength; i++)
    {
        cout << chars[i] << " ";
    }

    return 0;
}