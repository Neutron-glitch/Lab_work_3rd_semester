#include <iostream>

using namespace std;

struct node
{
    int data;
    struct node *left;
    struct node *right;
    struct node *parent;
    int height;
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

// inorder traversal
void print_avl(struct node *temp)
{
    if (temp == NULL)
        return;
    print_avl(temp->left);
    cout << temp->data << "(" << balance_factor(temp) << ")"
         << " ";
    print_avl(temp->right);
}

void Right_rotate(struct node *z)
{
    struct node *y = z->left;
    struct node *t3 = y->right;
    y->parent = z->parent;
    if (z->parent == NULL)
        root = y;
    else
    {
        if (z == z->parent->left)
            z->parent->left = y;
        else
            z->parent->right = y;
    }
    y->right = z;
    z->parent = y;
    z->left = t3;
    if (t3 != NULL)
        t3->parent = z;

    // fixing the height of z after rotation
    struct node *temp = z;
    while (temp != NULL)
    {
        update_height(temp);
        temp = temp->parent;
    }
}

void Left_rotate(struct node *z)
{
    struct node *y = z->right;
    struct node *t3 = y->left;
    y->parent = z->parent;
    if (z->parent == NULL)
        root = y;
    else
    {
        if (z == z->parent->left)
            z->parent->left = y;
        else
            z->parent->right = y;
    }
    y->left = z;
    z->parent = y;
    z->right = t3;
    if (t3 != NULL)
        t3->parent = z;

    // fixing the height of z after rotation
    struct node *temp = z;
    while (temp != NULL)
    {
        update_height(temp);
        temp = temp->parent;
    }
}

void check_balance(struct node *temp, int key)
{
    bool balanced = true;
    while (temp != NULL)
    {
        if (balance_factor(temp) > 1)
        {

            if (key < temp->left->data)
            {

                Right_rotate(temp);
            }
            else if (key > temp->left->data)
            {
                Left_rotate(temp->left);
                Right_rotate(temp);
            }
            balanced = false;
            break;
        }
        else if (balance_factor(temp) < -1)
        {
            if (key > temp->right->data)
            {

                Left_rotate(temp);
            }
            else if (key < temp->right->data)
            {

                Right_rotate(temp->right);
                Left_rotate(temp);
            }
            balanced = false;
            break;
        }
        // traversing the parent to find the unbalanced node 
        else
        {
            temp = temp->parent;
        }
    }
}

void insertion(int key)
{
    struct node *trav = root;
    struct node *target;
    struct node *temp = newNode(key);

    if (root == NULL)
    {
        root = temp;
        root->parent = NULL;

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

    check_balance(t, key);

    while (t != NULL)
    {
        update_height(t);
        t = t->parent;
    }
}

// to find the lowenst common ancestor
int LCA(int a, int b, node *temp)
{
    while (1)
    {
        if (temp->data > a && temp->data > b)
            temp = temp->left;
        else if (temp->data < a && temp->data < b)
            temp = temp->right;
        else
            break;
    }
    return temp->data;
};

int main()
{
    int k = 0;
    while (1)
    {
        cin >> k;
        if (k == -1)
        {
            cout << "Status :";
            print_avl(root);
            break;
        }

        insertion(k);
    }

    int t;
    cin >> t;
    while (t--)
    {
        int a, b;
        cin >> a >> b;
        struct node *temp = root;
        int result;
        result = LCA(a, b, temp);
        cout << result << endl;
    }

    return 0;
}
