#include <bits/stdc++.h>

using namespace std;

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

struct node *head, *tail = NULL;

void insert_front(int key)
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

void insert_back(int key)
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

void insert_after_node(int key, int v)
{
    struct node *newnode = new node();

    if (head == NULL)
    {
        cout << "No list to traverse through" << endl;
        return;
    }

    struct node *temp = head;
    int flag = 1;

    while (1)
    {

        if (temp->data == v)
        {
            break;
        }
        else if (temp->next == NULL)
        {
            flag = 0;
            break;
        }
        else
        {
            temp = temp->next;
        }
    }

    if (flag == 0)
        cout << "ERROR message : the node does not exist " << endl;
    else
    {
        if (temp == tail)
        {
            newnode->next = temp->next;
            newnode->prev = temp;
            temp->next = newnode;
            newnode->data = key;
            tail = newnode;
        }
        else
        {
            newnode->next = temp->next;
            temp->next->prev = newnode;
            newnode->prev = temp;
            temp->next = newnode;
            newnode->data = key;
        }
    }
}

void update_node(int key, int v)
{
    struct node *temp = head;
    int flag = 1;

    if (head == NULL)
    {
        cout << "No list to traverse through" << endl;
        return;
    }

    while (1)
    {

        if (temp->data == v)
        {

            if (temp == tail)
            {
                temp->data = key;
                tail = temp;
            }
            else
            {
                temp->data = key;
                break;
            }
        }
        else if (temp->next == NULL)
        {
            flag = 0;
            break;
        }
        else
        {
            temp = temp->next;
        }
    }

    if (flag == 0)
        cout << "ERROR message : the node does not exist " << endl;
}

void remove_head()
{
    struct node *temp = head;

    head = head->next;
    head->prev = NULL;

    free(temp);
}

void remove_element(int key)
{
    struct node *temp = head;
    int flag = 1;

    if (head == NULL)
    {
        cout << "No list to traverse through" << endl;
        return;
    }

    // if in head
    if (temp->data == key)
    {
        remove_head();
        return;
    }

    while (1)
    {

        if (temp->next == NULL)
        {
            flag = 0;
            break;
        }
        else if (temp->next->data == key)
        {
            if (temp->next->next == NULL)
            {
                temp->next = NULL;
                tail = temp;
                break;
            }
            else
            {
                temp->next = temp->next->next;
                temp->next->prev = temp;
                break;
            }
        }
        else
        {
            temp = temp->next;
        }
    }

    if (flag == 0)
        cout << "ERROR message : the node does not exist " << endl;
}

void remove_end()
{
    if (head == NULL)
    {
        cout << "No elements in linked list" << endl;
    }
    else if (head->next == NULL)
    {
        head = NULL;
    }
    else
    {
        struct node *temp = tail;
        temp = temp->prev;
        temp->next = NULL;
        tail = temp;
    }
}

void print()
{
    struct node *temp = head;
    struct node *reverse;

    if (temp == NULL)
    {
        cout << "Linked list is empty" << endl;
        return;
    }

    cout << "Linked list from head to tail: ";
    while (temp != NULL)
    {
        cout << temp->data << " ";
        reverse = temp;
        temp = temp->next;
    }
    free(temp);

    cout << endl;

    cout << "Linked list from tail to head : ";
    while (reverse != NULL)
    {
        cout << reverse->data << " ";
        reverse = reverse->prev;
    }

    cout << endl;
}

int main()
{

    while (1)
    {
        int x;
        cout << "Press 1 to insert at front\nPress 2 to insert at back\nPress 3 to insert after a node\nPress 4 to update a node\nPress 5 to remove a node\nPress 6 to remove the last node\nPress 7 to exit.\n " << endl;

        cin >> x;

        if (x == 1)
        {
            int temp;
            cout << "value ?? " << endl;
            cin >> temp;
            insert_front(temp);
            print();
        }
        else if (x == 2)
        {
            int temp;
            cout << "value ?? " << endl;
            cin >> temp;
            insert_back(temp);
            print();
        }
        else if (x == 3)
        {
            int temp, compare;
            cout << "values are ?? " << endl;
            cin >> temp >> compare;
            insert_after_node(temp, compare);
            print();
        }
        else if (x == 4)
        {
            int temp, update;
            cout << "values are ?? " << endl;
            cin >> temp >> update;
            update_node(temp, update);
            print();
        }
        else if (x == 5)
        {
            int temp;
            cout << "remove value  ?? " << endl;
            cin >> temp;
            remove_element(temp);
            print();
        }
        else if (x == 6)
        {
            remove_end();
            print();
        }
        else if (x == 7)
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