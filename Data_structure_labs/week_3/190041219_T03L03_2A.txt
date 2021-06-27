#include <bits/stdc++.h>

using namespace std;

int n;


void heapify(int A[], int i , int heap_size)
{
    int largest=i ;
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

        heapify(A, largest ,heap_size );
    }
}

void Build_max_heap(int A[] , int heap_size)
{
    for (int i = n / 2; i > 0; i--)
        heapify(A, i , heap_size);
}

int heap_minimum(int A[])
{
    return A[1];
}

void heap_extract_min(int A[] , int heap_size)
{
    if(heap_size < 1)
    cout<<"underflow"<<endl;
    else
    {
        int min = A[1] ;
        swap(A[1] , A[heap_size]);
        heap_size--;
        heapify(A , 1 , heap_size);

        cout<< min;
    }
    
}

void min_heap_insert(int A[] , int key ,int heap_size)
{
    heap_size++;
    A[heap_size] = key ;

    int i =heap_size;
    int parent_of_i=heap_size/2;

    while( A[i] < A[parent_of_i] && i>1)
    {
        swap (A[i] , A[parent_of_i]);
        i = parent_of_i ;
        parent_of_i = i/2;

    }

}

// void heap_decrease_key(int A[] , int key , int heap_size)
// {

// }







void printHeap(int A[] ,int heap_size)
{
    for (int i = 1; i < heap_size + 1; i++)
        cout << A[i] << " ";

    
}

void Heap_sort(int A[], int heap_size)
{   
    Build_max_heap(A , heap_size);
  
    for (int i = n; i >=2; i--)
    {   
       
        swap(A[1], A[i]);
        heap_size--;

        heapify(A , 1 , heap_size );
       
    }
    
}




int main()
{

    cin >> n;
    int arr[n + 1];

    int heap_size=n;

    for (int i = 1; i < n + 1; i++)
        cin >> arr[i];


    Heap_sort(arr, heap_size);
    printHeap(arr,heap_size);

    
    //cout<<"heap_size :" <<heap_size<<endl;
  




    return 0;
}