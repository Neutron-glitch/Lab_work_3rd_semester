#include <iostream>
#include <cmath>
using namespace std;


void init(int node, int begin, int end, int arr[], int seg_tree[])
{
    if (begin == end)
    {
        seg_tree[node] = arr[begin];
        return;
    }
    int left = node * 2;
    int right = (node * 2) + 1;
    int mid = (begin + end) / 2;
    init(left, begin, mid, arr, seg_tree);
    init(right, mid + 1, end, arr, seg_tree);
    seg_tree[node] = seg_tree[left] + seg_tree[right];
}

void update(int node, int b, int e, int i, int j, int type, int val, int seg_tree[], int arr[])
{
    if (b > j || e < i)
        return;
    if (b == i && e == j)
    {
        if (type == 1)
        {
            cout << seg_tree[node];
            seg_tree[node] = val;
            arr[b] = val;
        }
        else
        {
            seg_tree[node] =seg_tree[node] + val;
            arr[b] =arr[b] + val;
        }
        return;
    }

    int left = node * 2;
    int right = (node * 2) + 1;
    int mid = (b + e) / 2;

    update(left, b, mid, i, j, type, val, seg_tree, arr);
    update(right, mid + 1, e, i, j, type, val, seg_tree, arr);

    // update again as it was changed
    seg_tree[node] = seg_tree[left] + seg_tree[right];
}
int sum(int node, int b, int e, int i, int j, int seg[])
{
    if (b > j || e < i)
        return 0;
    else if (b >= i && e <= j)
        return seg[node];

    int left = node * 2;
    int right = node * 2 + 1;
    int mid = (b + e) / 2;

    int q1 = sum(left, b, mid, i, j, seg);
    int q2 = sum(right, mid + 1, e, i, j, seg);
    
    return q1 + q2;
}

int main()
{
    int n, q;
    cin >> n >> q;
    int temp = ceil(log2(n));
    temp = 2 * pow(2, temp) - 1;
    int arr_in[n + 1];
    int arr_seg[temp + 1];
    for (int i = 1; i <= n; i++)
        cin >> arr_in[i];

    init(1, 1, n, arr_in, arr_seg);
     
    while (q--)
    {
        int q1;
        cin >> q1;
        // for making value = 0
        if (q1 == 1)
        {
            int sack_no;
            cin >> sack_no;
            update(1, 1, n, sack_no, sack_no, 1, 0, arr_seg, arr_in);
            cout << "(";
            for (int i = 1; i <= n; i++)
            {
                cout << arr_in[i] << " ";
            }
            cout << ")" << endl;
        }
        //for updating
        else if (q1 == 2)
        {
            int sack_no, x;
            cin >> sack_no >> x;
            update(1, 1, n, sack_no, sack_no, 2, x, arr_seg, arr_in);
            cout << "(";
            for (int i = 1; i <= n; i++)
            {
                cout << arr_in[i] << " ";
            }
            cout << ")" << endl;
            
        }
        else
        {
            int i, j;
            cin >> i >> j;
            cout << sum(1, 1, n, i, j, arr_seg) << endl;
        }
    }
    return 0;
}
