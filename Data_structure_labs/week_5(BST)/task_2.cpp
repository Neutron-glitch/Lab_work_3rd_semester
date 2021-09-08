#include <bits/stdc++.h>

using namespace std;

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *root = NULL;

void insert_into_bst(node *x)
{
    struct node *temp = root;

    if (temp == NULL)
    {
        root = x;
        return;
    }

    struct node *target = temp;

    while (temp != NULL)
    {

        if ((x->data >= temp->data - 3) && (x->data <= temp->data + 3))
        {
            cout << "(Reservation failed)" << endl;
            return;
        }
        target = temp;
        if (x->data < temp->data)
            temp = temp->left;
        else
            temp = temp->right;
    }

    if ((x->data) < (target->data))
        target->left = x;
    else
        target->right = x;
}

void level_order_traversal(node *root)
{
    struct node *current;

    queue<node *> Q;
    Q.push(root);
    while (!Q.empty())
    {
        current = Q.front();
        cout << current->data << " ";
        Q.pop();
        if (current->left != NULL)
            Q.push(current->left);
        if (current->right != NULL)
            Q.push(current->right);
    }
}

int main()
{
    int k;
    while (1)
    {

        cin >> k;
        if (k == -1)
            break;

        struct node *newnode = new node();
        newnode->data = k;
        newnode->left = NULL;
        newnode->right = NULL;

        insert_into_bst(newnode);
    }
    level_order_traversal(root);

    return 0;
}