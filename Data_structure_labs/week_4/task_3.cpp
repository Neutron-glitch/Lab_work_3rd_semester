#include <bits/stdc++.h>

using namespace std;

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

struct node *head, *tail = NULL;

void push_front(int key)
{
    struct node *temp = new node();

    temp->data = key;
    temp->next = head;
    temp->prev = NULL;

    if (head == NULL)
    {
        tail = temp;
    }
    else
    {
        head->prev = temp;
    }

    head = temp;

    if (head->next == NULL)
    {
        tail = head;
    }
}

void push_back(int key)
{
    struct node *newnode = new node();

    newnode->data = key;
    newnode->next = NULL;
    newnode->prev = tail;

    if (head == NULL)
    {
        head = newnode;
        tail = newnode;
    }
    else
    {
        tail->next = newnode;
        tail = newnode;
    }
}

int pop_front()
{
    if (head == NULL)
    {
        cout << "ERROR :No list to traverse through" << endl;
        return 0;
    }
    else if (head->next == NULL)
    {
        cout << "popped element :" << head->data << endl;
        head = NULL;
    }
    else
    {

        struct node *temp = head;

        cout << "popped element :" << head->data << endl;
        head = head->next;
        head->prev = NULL;

        free(temp);
    }

    return 1;
}

int pop_back()
{
    if (head == NULL)
    {
        cout << "ERROR:No elements in linked list" << endl;
        return 0;
    }
    else if (head->next == NULL)
    {
        cout << "popped element from back = " << head->data << endl;
        head = NULL;
    }
    else
    {
        cout << "popped element from back = " << tail->data << endl;

        struct node *temp = tail;
        temp = temp->prev;
        temp->next = NULL;
        tail = temp;

        
    }

    return 1;
}

void print()
{
    struct node *temp = head;

    if (temp == NULL)
    {
        cout << "Linked list is empty" << endl;
        return;
    }

    cout << "Linked list from head to tail: ";
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    free(temp);

    cout << endl;

    
}

int main()
{
    while (1)
    {
        int x;
        cout << "Press 1 to push front\nPress 2 to push_back\nPress 3 to pop_front\nPress 4 to pop_back\nPress 5 to exit \n " << endl;

        cin >> x;

        if (x == 1)
        {
            int temp;
            cout << "value ?? " << endl;
            cin >> temp;
            push_front(temp);
            print();
        }
        else if (x == 2)
        {
            int temp;
            cout << "value ?? " << endl;
            cin >> temp;
            push_back(temp);
            print();
        }
        else if (x == 3)
        {
            if (pop_front() == 0)
            {
                cout << "ERROR : popping unsuccessful" << endl;
            }
            else
            {
                print();
            }
        }
        else if (x == 4)
        {
            if (pop_back() == 0)
            {
                cout << "ERROR : popping unsuccessful" << endl;
            }
            else
            {
                print();
            }
        }
        else if (x == 5)
        {
            break;
        }
        else
        {
            cout << "Please enter a valid input from the list" << endl;
        }

        cout << "---------------------------------------------------" << endl;
    }

    return 0;
}