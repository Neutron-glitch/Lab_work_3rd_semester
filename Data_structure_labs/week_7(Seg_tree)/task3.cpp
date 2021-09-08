#include <iostream>
#include <cmath>
#define MAX INT_MAX
#define MIN INT_MIN

using namespace std;

// making the segment tree
void init(int node, int b, int e, int arr[], int seg_tree[])
{
    if (b == e)
    {
        seg_tree[node] = arr[b];
        return;
    }
    int left = node * 2;
    int right = (node * 2) + 1;
    int mid = (b + e) / 2;

    init(left, b, mid, arr, seg_tree);
    init(right, mid + 1, e, arr, seg_tree);

    seg_tree[node] = min(seg_tree[left],seg_tree[right]);
}

void update_lazy(int node,int b,int e,int i,int j,int x,int arr[],int seg_tree[],int lazy[])
{
    //pending updates
    if(lazy[node]!=0)
    {
        seg_tree[node]+=lazy[node];
        if(b!=e) // not a leaf node
        {
            lazy[node*2]+=lazy[node];
            lazy[node*2+1]+=lazy[node];
        }
        lazy[node] = 0;
    }

       // no overlap -return that does not effect the result 
    if (b>j || e<i)
        return;

    // complete overlap
    if (b >= i && e <= j) 
    {
        seg_tree[node] += x;
        arr[b] += x;
        if(b!=e)
        {
           lazy[node*2]+=x;
           lazy[node*2+1]+=x;
        }
        return;
    }

    int left = node * 2;
    int right = (node * 2) + 1;
    int mid = (b + e) / 2;

    update_lazy(left, b, mid, i, j, x, arr,seg_tree,lazy);
    update_lazy(right, mid + 1, e, i, j, x, arr,seg_tree,lazy);

    seg_tree[node] = min(seg_tree[left],seg_tree[right]);
    return;
}

int query_lazy(int node, int b, int e, int i, int j, int seg_tree[],int lazy[])
{
    //pending updates
    if(lazy[node]!=0)
    {   
         // not a leaf node
         
        seg_tree[node]+=lazy[node];
        if(b!=e)
        {
            lazy[node*2]+=lazy[node];
            lazy[node*2+1]+=lazy[node];
        }
        lazy[node] = 0;
    }

    //no overlap
    if (i>e || j<b) 
        return MAX;

    //complete overlap
    if (b >= i && e <= j) 
    {
          return seg_tree[node];
    }


    int left = node * 2;
    int right = (node * 2) + 1;
    int mid = (b + e) / 2;

    int q1 = query_lazy(left, b, mid, i, j, seg_tree,lazy);
    int q2 = query_lazy(right, mid + 1, e, i, j, seg_tree,lazy);

    return min(q1,q2);
}

int main()
{
    int n, q;
    cin >> n >> q;
    int arr[n+1];
    int seg_tree[n*2];
    int lazy[n*2];
    for (int i = 1; i <= n; i++)
        cin >> arr[i];

    for (int i = 1; i <= 2*n; i++)
        lazy[i] = 0;

    init(1, 1, n, arr, seg_tree);
    
    while (q--)
    {
        int t;
        cin >> t;
        if (t == 1)
        {
            int x,i,j;
            cin >> x >> i >> j;
            update_lazy(1, 1, n, i, j, x,arr,seg_tree,lazy);
            for (int i = 1; i <= n; i++)
            {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
        else
        {
            int i, j;
            cin >> i >> j;
            cout << query_lazy(1, 1, n, i, j, seg_tree,lazy) << endl;
            for (int i = 1; i <= n; i++)
            {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
    }
    return 0;
}

