#include <bits/stdc++.h>
#include <stack>

using namespace std;

// for printing all the items in the stack

void print_s(stack<int> s)
{
    if (s.empty())
    {
        cout << "items = NULL" << endl;
    }
    else
    {
        // making a temporary stack and filling up the stack which is reverse of the original stack

        stack<int> temp_stack;

        while (!s.empty())
        {
            temp_stack.push(s.top());
            s.pop();
        }

        cout << "items = ";


        // popping and printing rhe reverse order of temp stack 

        while (!temp_stack.empty())
        {
            cout << temp_stack.top() << " ";
            temp_stack.pop();
        }

        cout << endl;
    }
}


// main function

int main()
{
    stack<int> stack;
    int N, t;
    cin >> N >> t;

    // looping t times

    while (t--)
    {
        int a, b;
        cin >> a;

        if (a == 1)
        {
            cin >> b;

            if (stack.size() < N)
                stack.push(b);
        }
        else
        {
            if (!stack.empty())
                stack.pop();
        }

        cout << "size = " << stack.size() << "  ";

        print_s(stack);
    }

    return 0;
}
