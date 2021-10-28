#include <bits/stdc++.h>

using namespace std;

bool linearProbing(int arr[], int value, int sizee, int n)
{
    int x = 0, count = 1;
    int id = (value + x) % n;
    while (arr[id] != -1)
    {
        cout << "Collision: Index-" << id << endl;
        count++;
        x++;
        id = (value + x) % n;
        if (count > 6)
        {
            cout << "Input Abandoned" << endl;
            return 0;
        }
    }
    arr[id] = value;
    sizee++;
    cout << "Inserted : Index-" << id << " (L.F=" << ((double)sizee / (double)n) << ")" << endl;
    return 1;
}

bool quadraticProbing(int arr[], int value, int sizee, int n)
{
    int x = 0, count = 1;
    int id = (value + x * x) % n;
    while (arr[id] != -1)
    {
        cout << "Collision: Index-" << id << endl;
        count++;
        x++;
        id = (value + x * x) % n;
        if (count > 6)
        {
            cout << "Input Abandoned" << endl;
            return 0;
        }
    }
    arr[id] = value;
    sizee++;
    cout << "Inserted : Index-" << id << " (L.F=" << ((double)sizee / (double)n) << ")" << endl;
    return 1;
}

bool doubleHashing(int arr[], int value, int sizee, int n)
{
    int x = 0, count = 1;
    int hash2 = 4 - (value % 4);
    int f = x * hash2;
    int id = (value + f) % n;
    while (arr[id] != -1)
    {
        cout << "Collision: Index-" << id << endl;
        count++;
        x++;
        f = x * hash2;
        id = (value + f) % n;
        if (count > 6)
        {
            cout << "Input Abandoned" << endl;
            return 0;
        }
    }
    arr[id] = value;
    sizee++;
    cout << "Inserted : Index-" << id << " (L.F=" << ((double)sizee / (double)n) << ")" << endl;
    return 1;
}

int main()
{
    int t, n, q;
    cin >> t >> n >> q;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        arr[i] = -1;
    }

    int x = 0;
    bool s = 0;

    while (q--)
    {
        int v;
        cin >> v;
        if (t == 1)
            x = x + linearProbing(arr, v, x, n);
        else if (t == 2)
            x = x + quadraticProbing(arr, v, x, n);
        else
            x = x + doubleHashing(arr, v, x, n);
    }
    return 0;
}
