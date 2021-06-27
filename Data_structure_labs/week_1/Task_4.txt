#include <bits/stdc++.h>

using namespace std;

int main()
{

    // declaring a vector for the input and a vector pair for the output

    vector<int> vect;
    vector<pair<int, int>> pair_vect;

    // taking input

    while (1)
    {
        int temp;
        cin >> temp;
        if (temp != 0)
            vect.push_back(temp);
        else
            break;
    }

    int desired_number, count = 0;
    cin >> desired_number;

    // looping through to fing the pair . Time complexity O(n^2)

    for (int i = 0; i < vect.size(); i++)
    {
        for (int j = i + 1; j < vect.size(); j++)
        {
            if (vect[i] + vect[j] == desired_number)
            {
                count++;
                pair_vect.push_back(make_pair(i + 1, j + 1));
            }
        }
    }


    // printing  the pairs 

    if (count == 0)
        cout << "No pair found!" << endl;
    else
    {
        cout << count << " Pairs:" << endl;

        for (int i = 0; i < pair_vect.size(); i++)
        {
            cout << "(worker-" << pair_vect[i].first << ", worker-" << pair_vect[i].second << ")" << endl;
        }
    }

    return 0;
}