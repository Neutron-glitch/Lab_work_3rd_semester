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

int height(node *n)
{
    if (n == NULL)
        return -1;
    int left = height(n->left);
    int right = height(n->right);
    return (max(left, right) + 1);
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
    cout << height(root) << endl;

    return 0;
}