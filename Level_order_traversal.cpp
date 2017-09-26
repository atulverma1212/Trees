#include<iostream>
using namespace std;

struct node
{
    int data;
    node *left;
    node *right;
};


node *que[100];
int rear=-1,front=-1;

void enq(node *n)
{
    if(front==-1 && rear==-1)
        front=rear=0;
    else
        rear++;
    que[rear] = n;
}

node* deq()
{
    front++;
    return que[front-1];
}

void level(node *root)
{
    if(root==NULL)
    {
        cout << "Empty Tree\n";
        return;
    }
    while(root)
    {
        cout << root->data << endl;
        if(root->left)
            enq(root->left);
        if(root->right)
            enq(root->right);
        root = deq();
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
    void show()
    {
        level(tree);
    }
};

int main()
{
    Tree arr;
    int str[10] = {1,2,3,4,5,6,7,8,9,10};
    for(int i=0;i<10;i++)
        arr.insert(str[i]);
    arr.show();
}
