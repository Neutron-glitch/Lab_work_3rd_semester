#include <bits/stdc++.h>
#include <stack>
#include <string>

using namespace std;

int main()
{
    int n;

    cin >> n;
    cin.ignore();

    stack<char> str;

    while (n--)
    {
        string s;
        // cin >> s ;


        // taking input which can also be a sentence 

        getline(cin, s);

        for (int i = 0; i < s.size(); i++)
            str.push(s[i]);

        while (!str.empty())
        {
            cout << str.top();
            str.pop();
        }
        cout << endl;
    }

    return 0;
}