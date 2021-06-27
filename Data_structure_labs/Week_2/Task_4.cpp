#include <bits/stdc++.h>
#include <stack>

using namespace std;

// function to check if it's properly pa
bool parenthesized()
{
    string str;
    stack<char> brackets;
    int flag = 0;

    // taking the string including whitespaces

    getline(cin, str);

    // iterating over the string to find the parenthesis

    for (int i = 0; i < str.size(); i++)
    {

        // pushing to stack when finding opening bracket

        if (str[i] == '(' || str[i] == '{' || str[i] == '[')
        {
            brackets.push(str[i]);
        }

        // popping from stack when there is closing parenthesis

        if ((str[i] == ')' || str[i] == '}' || str[i] == ']'))
        {

            if (!brackets.empty())
            {
                if (str[i] == ')')
                {
                    if (brackets.top() == '(')
                    {
                        brackets.pop();
                        flag = 1;
                    }
                    else
                    {
                        flag = 0;
                        break;
                    }
                }

                if (str[i] == '}')
                {

                    if (brackets.top() == '{')
                    {
                        brackets.pop();

                        flag = 1;
                    }
                    else
                    {
                        flag = 0;
                        break;
                    }
                }

                if (str[i] == ']')
                {
                    if (brackets.top() == '[')
                    {
                        brackets.pop();

                        flag = 1;
                    }
                    else
                    {
                        flag = 0;
                        break;
                    }
                }
            }

            else
            {
                flag = 0;
                break;
            }
        }
    }

    // return statement 

    if (brackets.empty() && flag == 1)
        return true;
    else
        return false;
}


// main function

int main()
{
    int n;
    cin >> n;
    cin.ignore();

    while (n--)
    {
        if (parenthesized())
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }

    return 0;
    
}