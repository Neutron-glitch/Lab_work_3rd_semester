
// https://docs.google.com/document/d/1ZI9D9H0fYtEhxXJ0AiYCOcbKdxsPHiq0sCBLz1Gecu0/edit (Queue , heap )


#include <bits/stdc++.h>

using namespace std;

//declaring global variables

int N;
int front = 0;
int rear = 0;
int size_count = 0;

// finds out if the stack is empty or not

bool isEmpty()
{
    if (front == rear)
        return true;
    else
        return false;
}

// finds out the size of the stack

int size()
{
    return size_count;
}

void enqueue(int arr[], int number)
{
    if (rear == N)
        cout << "Overflow" << endl;
    else
    {
        arr[rear] = number;
        rear++;
        size_count++;
    }
}

void dequeue(int arr[])
{
    if (front == rear)
        cout << "Underflow" << endl;
    else
    {
        arr[front] = 0;
        front++;
        size_count--;
    }
}

void circular_enqueue(int arr[], int number)
{
    if (size_count == N)
        cout << "Overflow" << endl;
    else
    {
        arr[rear] = number;
        rear = (rear + 1) % N;
        size_count++;
    }
}

void circular_dequeue(int arr[])
{
    if (size_count == 0)
        cout << "Underflow" << endl;
    else
    {
        arr[front] = 0;
        front = (front + 1) % N;
        size_count--;
    }
}

// main function

int main()
{

    cout << "set array size :";
    cin >> N;
    int arr[N];
    cout << endl;

    cout << "Press 1 for linear implementation" << endl;
    cout << "press 2 for circular implementaion" << endl;
    int a;
    cin >> a;

    if (a == 1)
    {

        while (1)
        {

            int temp;
            cout << endl;
            cout << "1. For enqueue press : 1 " << endl;
            cout << "2. For dequeue press : 2 " << endl;
            cout << "3.To output the array press :3 " << endl;
            cout << "4. Exit : 4 " << endl;
            cout << endl;

            cout << "Input number :";
            cin >> temp;

            if (temp == 1)
            {
                int for_enqueue;
                cout << "enter number to enqueue : ";
                cin >> for_enqueue;

                enqueue(arr, for_enqueue);
            }
            else if (temp == 2)
            {
                int for_dequeue;

                dequeue(arr);
            }
            else if (temp == 3)
            {
                cout << "---------------------------" << endl;
                if (size() == 0)
                    cout << "NULL" << endl;

                else
                {
                    cout << "The queue is : ";
                    for (int i = front; i < rear; i++)
                        cout << arr[i] << " ";
                }

                cout << endl;
            }
            else if (temp == 4)
            {
                break;
            }
        }
    }
    else if (a == 2)
    {

        while (1)
        {

            int temp;
            cout << endl;
            cout << "1. For circular_enqueue press : 1 " << endl;
            cout << "2. For circular_dequeue press : 2 " << endl;
            cout << "3.To output the cirular_array press :3 " << endl;
            cout << "4. Exit : 4 " << endl;
            cout << endl;

            cout << "Input number :";
            cin >> temp;

            if (temp == 1)
            {
                int for_enqueue;
                cout << "enter number to enqueue : ";
                cin >> for_enqueue;

                circular_enqueue(arr, for_enqueue);
            }
            else if (temp == 2)
            {
                int for_dequeue;

                circular_dequeue(arr);
            }
            else if (temp == 3)
            {
                cout << "---------------------------" << endl;
                if (size() == 0)
                    cout << "NULL" << endl;

                else
                {
                    cout << "The queue is : ";
                    int temp_count = size();
                    int i = front;

                    while (temp_count--)
                    {

                        cout << arr[i] << " ";
                        i = (i + 1) % N;
                    }
                }

                cout << endl;
            }
            else if (temp == 4)
            {
                break;
            }
        }
    }

    return 0;
}