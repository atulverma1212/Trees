#include<iostream>
#include <stack>
using namespace std;

struct node
{
    int data;
    node *left;
    node *right;
};

stack <node *> arr;

void topView(node * root) {
    node *head = root;
    node *temp = NULL;
    while(root)
    {
        arr.push(root);
        root=root->left;
    }
    do
    {
        root = arr.top();
        cout << root->data << " ";
        arr.pop();
    }while(root!=head);
    head=head->right;
    while(head)
    {
        cout << head->data << " ";
        head=head->right;
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
    void postorder()
    {
        topView(tree);
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
    arr.postorder();
}
