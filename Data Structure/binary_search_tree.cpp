// just an implementation for BST
#include<bits/stdc++.h>
using namespace std;
struct BstNode
{
    int data;
    BstNode *left;
    BstNode *right;
};
BstNode * getNewNode()
{
    BstNode *temp = new BstNode;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}
BstNode * Insert(BstNode *root, int data)
{
    if(root == NULL)
    {
        BstNode *newNode = getNewNode();
        newNode->data = data;
        root = newNode;
    }
    else if(data <= root->data)
    {
        root->left = Insert(root->left, data);
    }
    else
    {
        root->right = Insert(root->right, data);
    }
    return root;
}
int main()
{
    BstNode *root = NULL;
    root = Insert(root, 15);
    root = Insert(root, 8);
    root = Insert(root, 10);
    root = Insert(root, 26);
    cout<<root->data<<"\n";
    cout<<root->left->right->data<<"\n"; //should be 10 (15->left(8)->right(10))
    cout<<root->right->data<<"\n"; // should be 26 (15->right(26))
    return 0;
}