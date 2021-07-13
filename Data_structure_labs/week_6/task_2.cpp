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
void print_avl(node *temp)
{
    if (temp == NULL)
        return;
    print_avl(temp->left);
    cout << temp->data << "(" << balance_factor(temp) << ")"
         << " ";
    print_avl(temp->right);
}

void Right_rotate(node *z)
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

void Left_rotate(node *z)
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


// checking the tree for balancing and making it balance
bool check_balance(node *temp, int key)
{
    bool balanced = true;
    while (temp != NULL)
    {
        if (balance_factor(temp) > 1)
        { 
            cout << "Imbalance at node : " << temp->data << endl;

            // LL case right rotate imbalanced node
            if (key < temp->left->data)
            {
                cout << "LL case" << endl;
                cout << "Right_rotate(" << temp->data << ")" << endl;
                Right_rotate(temp);
                cout << "status: ";
                print_avl(root);
                cout << endl;
                cout << "Root=" << root->data << endl;
            }

            // LR case first left rotate heavy child then right rotate imbalanced node
            else if (key > temp->left->data)
            {
                cout << "LR case" << endl;
                cout << "Left_rotate(" << temp->left->data << "), ";
                cout << "Right_rotate(" << temp->data << ")" << endl;
                Left_rotate(temp->left);
                Right_rotate(temp);
                cout << "status: ";
                print_avl(root);
                cout << endl;
                cout << "Root=" << root->data << endl;
            }
            balanced = false;
            break;
        }
        else if (balance_factor(temp) < -1)
        {   
            //RR case left rotate imbalanced node
            cout << "Imbalance at node : " << temp->data << endl;
            if (key > temp->right->data)
            {
                cout << "RR case" << endl;
                cout << "Left_rotate(" << temp->data << ")" << endl;
                Left_rotate(temp);
                cout << "status: ";
                print_avl(root);
                cout << endl;
                cout << "Root=" << root->data << endl;
            }

            //RL case first right rotate heavy child then left rotate imbalanced node
            else if (key < temp->right->data)
            {
                cout << "RL case" << endl;
                cout << "Right_rotate(" << temp->right->data << ")" << endl;
                cout << "Left_rotate(" << temp->data << "), ";
                Right_rotate(temp->right);
                Left_rotate(temp);
                cout << "status: ";
                print_avl(root);
                cout << endl;
                cout << "Root=" << root->data << endl;
            }
            balanced = false;
            break;
        }
        else
        {
            temp = temp->parent;
        }
    }
    return balanced;
}

// inserting node at bst and balancing the tree at a time
void insertion(int key)
{
    struct node *trav = root;
    struct node *target;
    struct node *temp = newNode(key);

    if (root == NULL)
    {
        root = temp;
        root->parent = NULL;
        cout << root->data << " "
             << "(0)" << endl;
        cout << "Balanced" << endl;
        cout << "Root= " << root->data << endl;

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

    print_avl(root);
    cout << endl;


    //checking whether the tree is balanced if not balance it in check balance
    if (check_balance(t, key))
    {
        cout << "Balanced" << endl;
        cout << "Root= " << root->data << endl;
    }

    while (t != NULL)
    {
        update_height(t);
        t = t->parent;
    }
}


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
    return 0;
}
