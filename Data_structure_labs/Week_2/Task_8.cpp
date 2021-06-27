#include <bits/stdc++.h>
#include <stack>

using namespace std;

// function to find the next greater element

void finding_NGE(vector<int> v)
{
    stack<int> s;
    unordered_map<int, int> m;

    // going through the vector  

    for (int i = 0; i < v.size(); i++)
    {
        if (s.empty())
        {
            s.push(v[i]);
            continue;
        }


        // if the top element is less than the vector element then the pair is stored in map

        while (!s.empty() && s.top() < v[i])
        {

            m[s.top()] = v[i];
            s.pop();
        }

        // pushing the vector element for it's comparision

        s.push(v[i]);
    }

    // all the other numbers has no nge so -1 is stored is their respective map pair
    while (!s.empty())
    {
        m[s.top()] = -1;
        s.pop();
    }


    // looping to print the result 

    for (int i = 0; i < v.size(); i++)
    {
        cout << m[v[i]] << " ";
    }
}


// main function 

int main()
{
    int n;
    cin >> n;

    while (n--)
    {
        stack<int> s;
        vector<int> vect;

        while (1)
        {
            int temp;
            cin >> temp;
            if (temp != -1)
                vect.push_back(temp);
            else
                break;
        }

        finding_NGE(vect);

        cout << endl;
        cout << endl;
    }

    return 0;
}