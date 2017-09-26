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

void deq()
{
    front++;
}

void level(node *root)
{
    if(root==NULL)
    {
        cout << "Empty Tree\n";
        return;
    }
    enq(root);
    while(1)
    {
        int node_count = rear-front;
        if(node_count<0)
            break;
        while(node_count>=0)
        {
            cout << que[front]->data << " ";
            if(que[front]->left)
                enq(que[front]->left);
            if(que[front]->right)
                enq(que[front]->right);
            deq();
            node_count--;
        }
        cout << endl;
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
    void level_order()
    {
        level(tree);
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
    arr.level_order();
}
