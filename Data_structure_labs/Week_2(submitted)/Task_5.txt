#include <bits/stdc++.h>
#include <stack>

using namespace std;


// main function

int main()
{
    int n;

    cin >> n;

    int arr[n];
    stack<int> s;
    

    // taking the input in a array 

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int count = 1;
    int hello = 6;
    int flag = 0;

    int ans_counter = 0;
    int i = 0;


    // looping through until we find all the numbers in order 

    while (1)
    {

        //  checking whether the i index in array is the required number 
        // if not found pushing it to stack or checking in the stack

        if (i < n)
        {

            if (arr[i] == count)
            {
                flag = 1;

                ans_counter++;
                count++;
            }
            else if (!s.empty() && s.top() == count)
            {

                flag = 1;
                ans_counter++;
                count++;

                s.pop();

                i--;
            }
            else
            {
                s.push(arr[i]);
            }
        }
        

        // it's for the numbers in the stack which are present after we pharse through the array  

        if (i >= n)
        {
            while (!s.empty())
            {
                if (s.top() == count)
                {
                    flag = 1;

                    ans_counter++;
                    count++;

                    s.pop();
                }
                else
                {
                    
                    // when the number is not matched the  whole loop breaks and flag = 0 is returned  

                    flag = 0;

                    hello = -5;
                    s.pop();
                    break;
                }
            }
        }


        // when all numbers are found the loop is broken

        if (ans_counter == n || hello == -5)
            break;

        i++;
    }

    if (flag == 1)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;

    return 0;
}