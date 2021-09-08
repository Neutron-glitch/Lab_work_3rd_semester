#include <iostream>
#include <cmath>

#define MAX INT_MAX
using namespace std;

// making the segment tree
void init(int node, int begin, int end, int arr[], int seg_tree[])
{
    if (begin == end) //leaf node
    {
        seg_tree[node] = arr[begin];
        return;
    }
    int left = node * 2;
    int right = (node * 2) + 1;
    int mid = (begin + end) / 2;
    init(left, begin, mid, arr, seg_tree);
    init(right, mid + 1, end, arr, seg_tree);

    if (seg_tree[left] < seg_tree[right])
    {
        seg_tree[node] = seg_tree[left];
    }
    else
        seg_tree[node] = seg_tree[right];
}

// b and e is the range of the segment
// i and j given range that is needed to be found 

int query_min(int node, int b, int e, int i, int j, int seg_tree[])
{   
    // no overlap -return that does not effect the result 
    if (b > j || i>e)
        return MAX;

    // total overlap
    else if (b >= i && e <= j)
        return seg_tree[node];

    //for partial overlap
    int left = node * 2;
    int right = node * 2 + 1;
    int mid = (b + e) / 2;

    int q1 = query_min(left, b, mid, i, j, seg_tree);
    int q2 = query_min(right, mid + 1, e, i, j, seg_tree);


    if(q1<q2)
        return q1;
    else
        return q2;
}

int main() 
{
    int n, b;
    cin >> n >> b;

    int temp = ceil(log2(n));
    temp = 2 * pow(2, temp) - 1;

    int arr_in[n + 1];
    int arr_seg[temp + 1];

    for (int i = 1; i <= n; i++)
        cin >> arr_in[i];

    init(1, 1, n, arr_in, arr_seg);

    while (b--)
    {
        int i, j;
        cin >> i >> j;
        cout << query_min(1, 1, n, i, j, arr_seg) << endl;
    }
    return 0;
}
