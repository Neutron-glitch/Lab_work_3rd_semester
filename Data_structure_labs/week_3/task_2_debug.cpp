#include <bits/stdc++.h>

using namespace std;

int n;
int heap_size=n;


void heapify(int A[], int i)
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

        heapify(A, largest );
    }
}

void Build_max_heap(int A[])
{
    for (int i = n / 2; i > 0; i--)
        heapify(A, i);
}

void printHeap(int A[])
{
    for (int i = 1; i < n + 1; i++)
        cout << A[i] << " ";

    
}


void Heap_sort(int A[])
{   
    Build_max_heap(A);
    printHeap(A);
    
    int count =0;

    for (int i = n; i >=2; i--)
    {   
        count++;
        
        cout<<"count : " << count << endl;
        swap(A[1], A[i]);
        heap_size--;

         cout<<"ahaha"<<endl;
          printHeap(A);
        heapify(A , 1 );
         cout<< "kokoko"<<endl;
         printHeap(A);
    }

    
}



int main()
{

    cin >> n;
    int arr[n + 1];
    int array_size=n;

    for (int i = 1; i < n + 1; i++)
        cin >> arr[i];


    Build_max_heap(arr);
    cout<<"real"<<endl;
    printHeap(arr);

   



    return 0;
}