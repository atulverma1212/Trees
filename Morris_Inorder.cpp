#include<iostream>
using namespace std;

struct node
{
    int data;
    node *left;
    node *right;
};


node *stack[100];
int top=-1;

void push(node *n)
{
    top++;
    stack[top]=n;
}

node *pop() { return stack[top--]; }

node *inorder_predecessor(node *root)
{
    node *cur  = root->left;
    while(cur->right && cur->right!=root)
        cur=cur->right;
    return cur;
}

void inorder_traversal(node *root)
{
    if(root==NULL)
        return;
    node *pred = NULL;    // in order predecessor
    node *current = root;
    while(current)
    {
        if(current->left == NULL)
        {
            cout << current->data << " ";
            current = current->right;
        }
        else
        {
            pred = inorder_predecessor(current);
            if(pred->right == NULL)
            {
                pred->right=current;
                current=current->left;
            }
            else
            {
                cout << current->data << " ";
                pred->right=NULL;
                current = current->right;
            }
        }
    }
}

class Tree
{
    node *tree;
public:
    Tree() { tree = NULL; }
    node *create(int d)
    {
        node *temp = new node;
        temp->data = d;
        temp->left = temp->right = NULL;
        return temp;
    }
    void insert(int d)
    {
        node *newnode = create(d);
        node *temp = tree;
        node *parent = NULL;
        if(tree==NULL)
            tree=newnode;
        else
        {
            while(temp!=NULL)
            {
                parent = temp;
                if(d < temp->data)
                    temp=temp->left;
                else
                    temp=temp->right;
            }
            if(d < parent->data)
                parent->left = newnode;
            else
                parent->right = newnode;
        }
    }
    void morris()
    {
        inorder_traversal(tree);
        cout  <<  endl;
    }
};

int main()
{
    Tree arr;
    int str[] = {5,3,8,2,4,7,9};
    int n = sizeof(str)/sizeof(str[0]);
    for(int i=0;i<n;i++)
        arr.insert(str[i]);
    arr.morris();
}
