#include <bits/stdc++.h>

using namespace std;

int n;

void heapify(int A[], int i, int heap_size) // log n ;
{
    int largest = i;
    int l = 2 * i;
    int r = 2 * i + 1;

    if (A[l] > A[i] && l <= heap_size)
    {
        largest = l;
    }
    else
        largest = i;

    if (A[r] > A[largest] && r <= heap_size)
    {
        largest = r;
    }
    if (largest != i)
    {
        swap(A[i], A[largest]);

        heapify(A, largest, heap_size);
    }
}

void Build_max_heap(int A[], int heap_size)  // bottom up approach
{
    for (int i = n / 2; i > 0; i--)  // nlogn
        heapify(A, i, heap_size);
}

void printHeap(int A[])
{
    for (int i = 1; i < n + 1; i++)
        cout << A[i] << " ";
}

void Heap_sort(int A[], int heap_size)
{
    Build_max_heap(A, heap_size);

    for (int i = n; i >= 2; i--)
    {

        swap(A[1], A[i]);
        heap_size--;

        heapify(A, 1, heap_size);
    }
}

int main()
{

    cin >> n;
    int arr[n + 1];

    int heap_size = n;

    for (int i = 1; i < n + 1; i++)
        cin >> arr[i];

    Heap_sort(arr, heap_size);
    printHeap(arr);

    return 0;
}