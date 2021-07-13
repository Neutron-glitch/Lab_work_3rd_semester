#include <iostream>

using namespace std;

struct node
{
    int data;
    struct node *left;
    struct node *right;
    struct node *parent;
    int height;
    int bal_fac;
};

struct node *root = NULL;

struct node *newNode(int key)
{
    struct node *newnode = new node();
    newnode->data = key;
    newnode->left = NULL;
    newnode->right = NULL;
    newnode->parent = NULL;
    newnode->height = 0;
    newnode->bal_fac = 0;
    return newnode;
}

// return the height
int height(node *x)
{

    if (x == NULL)
        return -1;
    else
        return x->height;
}

// assign the height
void update_height(node *x)
{
    x->height = 1 + max(height(x->left), height(x->right));
}

// update the balance factor
int balance_factor(node *x)
{
    return height(x->left) - height(x->right);
}

//printing inorder traversal
void inorder(node *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    cout << root->data << "(" << root->bal_fac << ") ";
    inorder(root->right);
}

//inserting a new node into bst
void insertion(int key)
{
    struct node *trav = root;
    struct node *target;
    struct node *temp = newNode(key);

    if (root == NULL)
    {
        root = temp;
        root->parent = NULL;
        cout << root->data << "(0)" << endl;
        return;
    }

    // making the bst

    while (trav != NULL)
    {
        target = trav;
        if (key < trav->data)
            trav = trav->left;
        else
            trav = trav->right;
    }
    if (key < target->data)
    {
        target->left = temp;
        temp->parent = target;
    }
    else
    {
        target->right = temp;
        temp->parent = target;
    }

    struct node *t = temp;

    // assigning the height from bottom to top
    while (temp != NULL)
    {
        update_height(temp);
        temp = temp->parent;
    }

    // assigning the balance factor from bottom to top
    while (t != NULL)
    {
        int bal_fac = balance_factor(t);
        t->bal_fac = bal_fac;
        t = t->parent;
    }

    inorder(root);
    cout << endl;
}

int main()
{
    int k = 0;
    while (1)
    {
        cin >> k;
        if (k == -1)
            break;

        insertion(k);
    }
    return 0;
}
