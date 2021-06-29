#include <bits/stdc++.h>

using namespace std;

struct node
{
    int data;
    struct node *left;
    struct node *right;
    int left_subtree_size;
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
        if (x->data <= temp->data)
        {
            temp->left_subtree_size++; // size of the left subtree is determined
            temp = temp->left;
        }
        else
            temp = temp->right;
    }

    if ((x->data) < (target->data))
        target->left = x;
    else
        target->right = x;
}

int predecessor_count(int value) // checking how many predecessor before the value
{
    int count = 0;
    struct node *temp = root;

    /*
    case :
    1 . as the left_subtree_size determines the number of predecessors if we find the value the ans is left_subtree_size
    2 . if the value is in right sub tree this means it's predecessors also include the left subtree size of the root node as the root and it's predecessors has lower value
    */

    while (temp != NULL && temp->data != value) // finding the value
    {
        if (value <= temp->data)
        {
            temp = temp->left;
        }
        else
        {
            count = count + 1 + temp->left_subtree_size;
            temp = temp->right;
        }
    }
    if (temp != NULL)
    {
        count = count + temp->left_subtree_size;
    }

    return count;
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
        newnode->left_subtree_size = 0;

        insert_into_bst(newnode);
    }

    int n;
    cin >> n;
    while (n--)
    {
        int val;
        cin >> val;
        cout << predecessor_count(val) << endl;
    }

    return 0;
}
