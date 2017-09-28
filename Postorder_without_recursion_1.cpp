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

void traversal(node *root)
{
    node *temp = NULL;
   do
    {
        while(root)
        {
            if(root->right)
                arr.push(root->right);
            arr.push(root);
            root=root->left;
        }

        root = arr.top();
        arr.pop();

        if(!arr.empty() && root->right && root->right == arr.top())
        {
            arr.pop();
            arr.push(root);
            root=root->right;
        }
        else
        {
            cout << root->data <<  "  ";
            root=NULL;
        }
    }while(!arr.empty());
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
        traversal(tree);
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
