#include <stack>
#include <iostream>
using namespace std;

void print_s(stack<int> s)
{
    if (s.empty())
    {
        cout << "elements= NULL" << endl;
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

        cout << "elements = ";

        // popping and printing rhe reverse order of temp stack

        while (!temp_stack.empty())
        {
            cout << temp_stack.top() << " ";
            temp_stack.pop();
        }

        cout << endl;
    }
}

int main()
{
    stack<int> one, two; // one for push and two for pop
    int max_size, t;
    cin >> max_size >> t;

    while (t--)
    {
        int a, number;
        cin >> a;

        if (a == 1)
        {
            cin >> number;

            if (one.empty())
            {
                while (!two.empty())
                {
                    one.push(two.top());
                    two.pop();
                }
            }

            if (one.size() < max_size)
            {
                one.push(number);

                cout << "Size :" << one.size() << " ";
                print_s(one);
            }

            else
            {
                cout << "Size :" << one.size() << " ";
                cout << "elements : Overflow !" << endl;
            }
        }
        else if (a == 2)
        {
            if (two.empty())
            {
                while (!one.empty())
                {
                    two.push(one.top());
                    one.pop();
                }
            }

            if (!two.empty())
            {

                two.pop();

                if (one.empty())
                {
                    while (!two.empty())
                    {
                        one.push(two.top());
                        two.pop();
                    }
                }

                cout << "Size :" << one.size() << " ";
                print_s(one);
            }
        }
    }

    return 0;
}