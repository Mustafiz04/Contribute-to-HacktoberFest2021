//traversals in Binary Search Tree
#include<iostream>
#include<queue>
using namespace std;
class node
{
    public:
    int data;
    node* left;
    node* right;
    node(int d)
    {
        data=d;
        left=right=NULL;
    }
};
// creating bst
node* insertbst(node* root,int data)
{
    if(root == NULL)
    {
        root= new node(data);
        return root;
    }
    if (root->data>data)
    {
        root->left= insertbst(root->left,data);
    }
    else
    {
        root->right= insertbst(root->right,data);
    }
    return root;
}
// enter nodes value 
node* bst()
{
    node* root = NULL;
    int data;
    cin>>data;
    if (data == -1)
    {
        return root;
    }
    while (data != -1)
    {
        root = insertbst(root,data);
        cin>>data;
    }
    return root;     
}
void levelorder(node* root)
{
    queue<node*> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        node* n=q.front();
        q.pop();
        if (n==NULL)
        {
            cout<<endl;
            if(!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout<<n->data<<" ";
            if (n->left)
            {
                q.push(n->left);
            }
            if(n->right)
            {
                q.push(n->right);
            }   
        }
    }
}
int main()
{
    node* root = bst();
    cout<<"Levelorder"<<endl;
	levelorder(root);
    return 0;
}