#include <bits/stdc++.h>

using namespace std;

//declaring global variables

int N;
int top = -1;
int size_g = 0;

// finds out if the stack is empty or not

bool isEmpty()
{
    if (size_g < 1)
        return true;
    else
        return false;
}


// finds out the size of the stack

int size()
{
    return size_g;
}


// function for  iterating over all the items

void items(int arr[])
{
    if (size_g == 0)
    {
        cout << "NULL";
    }
    else
    {
        for (int i = 0; i < size_g; i++)
            cout << arr[i] << " ";
    }
}


// prints the items

void print_statement(int arr[])
{
    cout << "size = " << size() << " items = ";
    items(arr);
    cout << endl;
}


// pop function and print

void pop(int arr[])
{
    // when the array is not empty decrease the top and size
    // and printing the array ignoring the last number

    if (!isEmpty())
    {
        top--;
        size_g--;
    }

    print_statement(arr);
}


// push function and print it

void push(int number, int arr[])
{

    // increasing the value of top and size and inputting the number into array

    if (top != (N - 1))
    {
        top++;
        size_g++;
        arr[top] = number;
    }

    print_statement(arr);
}


// main function

int main()
{

    // N = maximum size of the stack

    int t;
    cin >> N >> t;

    // array to store the values
    int arr[N];

    // looping through and taking input

    while (t--)
    {
        int a, b;
        cin >> a;

        if (a == 1)
        {
            cin >> b;

            push(b, arr);
        }
        else
            pop(arr);
    }

    return 0;
}