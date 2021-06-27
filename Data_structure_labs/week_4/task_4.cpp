#include <bits/stdc++.h>

using namespace std;

struct node
{
    int data;
    struct node *next;
};

struct node *head, *tail = NULL;

void insert_back(int key)
{
    struct node *newnode = new node();

    newnode->data = key;
    newnode->next = NULL;

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

void in_search_of_unique()
{
    int flag = head->data;
    cout << flag << " ";

    struct node *temp = head;

    while (temp != NULL)
    {
        if (flag < temp->data)
        {
            flag = temp->data;
            cout << flag << " ";
        }

        temp = temp->next;
    }
}

int main()
{
    int x;
    while (1)
    {
        cin >> x;

        if (x == -1)
            break;
        else
        {
            insert_back(x);
        }
    }

    in_search_of_unique();

    return 0;
}
