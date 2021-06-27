#include <bits/stdc++.h>
#include <stack>

using namespace std;

//main function 

int main()
{
    int n;
    cin >> n;

    while (n--)
    {
        stack<int> result;

        string postfix;
        cin >> postfix;

       
       // iterating through the string 

        for (int i = 0; i < postfix.size(); i++)
        {   

            // when the character is a digit we push it to stack 
            // and when it's a operator we do the required operation

            if (isdigit(postfix[i]))
            { 
                // making the char int 

                result.push(postfix[i] - '0');   
            }
            else
            {   
                // for example  in expression :[   ab-  ]it will be [  a-b  ] we took b first 

                int a, b;
                b = result.top();
                result.pop();
                a = result.top();
                result.pop();

        
                // using the respective operation 

                if (postfix[i] == '+')
                    result.push(a + b);
                else if (postfix[i] == '-')
                    result.push(a - b);
                else if (postfix[i] == '*')
                    result.push(a * b);
                else if (postfix[i] == '/')
                    result.push(a / b);
            }
        }

        cout << result.top() << endl;
        result.pop();
        
    }

    return 0;
}