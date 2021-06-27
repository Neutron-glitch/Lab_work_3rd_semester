#include <bits/stdc++.h>
#include <stack>
#include <string>

using namespace std;

bool isoperand(char c)
{
    if (isalpha(c))
        return true;
    else
        return false;
}

bool isoperator(char c)
{
    if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^')
        return true;
    else
        return false;
}

bool isopeningParenthesis(char c)
{
    if (c == '(')
        return true;
    else
        return false;
}

bool isclosingParenthesis(char c)
{
    if (c == ')')
        return true;
    else
        return false;
}

int precedence(char c)
{
    if (c == '^')
        return 3;
    else if (c == '*' || c == '/')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return -1;
}

// function to convert infix expression to postfix expression

void infix_to_postfix(string str)
{
    // declaring a stack to hold the operators and and the opening bracket
    //and a string to hold the required result

    stack<char> s;
    string result = {};

    // iterating through each character of the given expression

    for (int i = 0; i < str.size(); i++)
    {
        // as the operand comes serially it is put into result string

        if (isoperand(str[i]))
        {
            result = result + str[i];
        }

        // the operators are stored in the stack and popped out if it's has higher precedence compared to the next operator

        else if (isoperator(str[i]))
        {
            while (!s.empty() && !isopeningParenthesis(s.top()) && (precedence(str[i]) <= precedence(s.top())))
            {
                result = result + s.top();
                s.pop();
            }

            s.push(str[i]);
        }


        // the opening parenthesis is pushed 
        //and when the closing bracket is found the sub- expression is calculated

        else if (isopeningParenthesis(str[i]))
            s.push(str[i]);
        else if (isclosingParenthesis(str[i]))
        {
            while (!s.empty() && !isopeningParenthesis(s.top()))
            {
                result = result + s.top();
                s.pop();
            }

            s.pop(); // popping the opening parenthesis
        }
    }


    // popping all the leftover operants into the string 

    while (!s.empty())
    {
        result = result + s.top();
        s.pop();
    }

    cout << result << endl;
}


// main function

int main()
{
    int n;

    cin >> n;

    while (n--)
    {
        string s;
        cin >> s;

        infix_to_postfix(s);
    }

    return 0;
}