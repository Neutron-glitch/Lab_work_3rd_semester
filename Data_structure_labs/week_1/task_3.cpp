#include <bits/stdc++.h>

using namespace std;


//binary search function suinbg iteration

int Iterative_binary_search(vector<int> vect, int x)
{
    // selecting the lower bound and upper bound

    int l = 0, h = vect.size() - 1;

    // looping through the expected range , here ' <= ' is important .

    while (l <= h)
    {

        // finding the middle value and thus dividing the range into half

        int m = (l + h) / 2;

        if (vect[m] == x)
            return m;

        if (vect[m] < x)
            l = m + 1;
        else
            h = m - 1;
    }

    // returns -1 when the desired numbers is not found

    return -1;
}


// binary search using recursion where l is the lower bounf and h is the upper bound

int Recursive_binary_search(vector<int> vect, int l, int h, int x)
{
    if (l <= h)
    {
        int m = (l + h) / 2;

        if (vect[m] == x)
            return m;

        if (vect[m] < x)
            return Recursive_binary_search(vect, m + 1, h, x);

        else
            return Recursive_binary_search(vect, l, m - 1, x);
    }
    return -1;
}

//main function

int main()
{
    vector<int> vect;

    // taking inputs

    while (1)
    {
        int temp;
        cin >> temp;
        if (temp >= 0)
            vect.push_back(temp);
        else
            break;
    }

    int desired_number;
    cin >> desired_number;

    // finding the output by passing through the functions

    int itr_binary_search = Iterative_binary_search(vect, desired_number);
    int rec_binary_search = Recursive_binary_search(vect, 0, vect.size() - 1, desired_number);

    // showing the output

    cout << itr_binary_search << " (using iteration)" << endl;
    cout << rec_binary_search << " (using recursion)" << endl;

    return 0;
}