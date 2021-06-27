#include <bits/stdc++.h>

using namespace std;

int main()
{

    int n, k;
    cin >> n >> k;

    /* vector<int> v1;
    for(int i=0; i<n;i++)
    {
        int temp;
        cin>>temp;
        v1.push_back(temp);
    }

    make_heap(v1.begin() , v1.end()  , greater<int>() );

    cout<<v1.front() <<endl;

     pop_heap(v1.begin() ,  v1.end() );


     cout<<v1.front() <<endl;
        
    } */



    priority_queue<int, vector<int>, greater<int>> pq;  // greater for sorting in acending order

    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        pq.push(temp);
    }

    int count = 0;

    while (pq.top() < k && pq.size() > 1)
    {
        int a, b;
        a = pq.top();
        pq.pop();
        b = pq.top();
        pq.pop();
        pq.push(a + 2 * b);
        count++;
    }

    if (pq.top() >= k)
        cout << count << endl;
    else
        cout << "-1" << endl;

    return 0;
}
