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
    stack[++top] = n;
}

bool isempty()
{
    if(top==-1) return 1; return 0;
}

node* pop()
{
    return stack[top--];
}

void traverse(node *current)
{
    if(current==NULL)
    {
        cout << "Empty Tree\n";
        return;
    }
    node *print = NULL;
    while(current || !isempty())
    {
        while(current)
        {
            push(current);
            current = current->left;
        }
        print = pop();
        cout << print->data << " ";
        current=print->right;
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
    void inorder()
    {
        traverse(tree);
        cout << endl;
    }
};

int main()
{
    Tree arr;
    int str[] = {5,3,8,2,4,7,9};
    int n = sizeof(str)/sizeof(str[0]);
    for(int i=0;i<n;i++)
        arr.insert(str[i]);
    arr.inorder();
}
