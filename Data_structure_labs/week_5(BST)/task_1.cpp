//week - 5 :
//https://docs.google.com/document/d/1-OMCtIoaTzJDVdlhvByf4tHBD-sYCJboy4XUqL1IUbo/edit

#include <bits/stdc++.h>

using namespace std;

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *root = NULL;

void inorder(node *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

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
            inorder(root);
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

    inorder(root);
    cout << endl;
}

int main()
{
    int k;
    while (1)
    {

        cin >> k;

        if (k == -1)
        {
            break;
        }

        struct node *newnode = new node();
        newnode->data = k;
        newnode->left = NULL;
        newnode->right = NULL;

        insert_into_bst(newnode);
    }

    return 0;
}