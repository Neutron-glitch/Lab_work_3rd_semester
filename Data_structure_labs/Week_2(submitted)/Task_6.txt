#include <bits/stdc++.h>
#include <stack>

using namespace std;

int main()
{
    stack<char> sta;
    string s;
    getline(cin, s);  // using getline as space is also mentioned 


    //iterating through the string

    for (int i = 0; i < s.size(); i++)
    {
        // pushing in stack when opening bracket is found

        if (s[i] == '(')
        {
            sta.push(s[i]);
        }

        // pushing when the opening bracket is not found and popping otherwise

        if (s[i] == ')')
        {
            if (sta.empty()) // this is needed as sta.top will show garbage when empty
                sta.push(s[i]);
            else if (sta.top() == '(')
            {
                sta.pop();
            }
            else
            {
                sta.push(s[i]);
            }
        }
    }

    // printing the stack size as the stack only contains the unfinished brackets
    // and we need the same amount of brackets to complete those

    cout << sta.size() << endl;

    return 0;
}