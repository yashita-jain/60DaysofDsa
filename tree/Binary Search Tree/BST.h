#include <bits/stdc++.h>
#include "../Binary Tree/BinaryTreeNode.h"

class BST
{

    BinaryTreeNode<int> *root;

    bool hasData(int data, BinaryTreeNode<int> *node)
    {
        if (node == NULL)
        {
            return 0;
        }
        if (node->data == data)
        {
            return 1;
        }
        else if (node->data > data)
        {
            return hasData(data, node->left);
        }
        else
        {
            return hasData(data, node->right);
        }
    }

    BinaryTreeNode<int> *insert(int data, BinaryTreeNode<int> *node)
    {
        if (node == NULL)
        {
            BinaryTreeNode<int> *node = new BinaryTreeNode<int>(data);
            return node;
        }

        if (node->data > data)
        {
            node->left = insert(data, node->left);
        }
        else
        {
            node->right = insert(data, node->right);
        }
        return node;
    }

BinaryTreeNode<int>* deleteData(int data,BinaryTreeNode<int>* node){
    if(node==NULL){
        return NULL;
    }
    if(node->data>data){
        node->left=deleteData(data,node->left);
        return node;
    }
    else if(node->data<data){
        node->right=deleteData(data,node->right);
        return node;
    }
    else{
        if(node->left==NULL&&node->right==NULL){
            delete node;
            return NULL;
        }
        else if(node->left==NULL){
            BinaryTreeNode<int>*temp=node->right;
            node->right=NULL;
            delete node;
            return temp;
        }
     else if(node->right==NULL){
            BinaryTreeNode<int>*temp=node->left;
            node->left=NULL;
            delete node;
            return temp;
        }
        else{
            int minimum;
            BinaryTreeNode<int>* temp=node->right;
            while (temp->left!=NULL)
            {
          
               temp=temp->left;
              
            }
            minimum=temp->data;
            
            node->data=minimum;
           node->right= deleteData(minimum,node->right);
            return node;
        }
    }

}


void printTree(BinaryTreeNode<int>* node){
    if(node==NULL){
        return;
    }
    
    cout<<node->data<<" :";
    if(node->left!=NULL){
cout<<"L"<<node->left->data;
    }

    if(node->right!=NULL){
cout<<"R"<<node->right->data;
    }

    cout<<endl;
    printTree(node->left);
    printTree(node->right);
}

public:
    BST()
    {
        root = NULL;
    }

    ~BST()
    {
        delete root;
    }

    int hasData(int data)
    {
        return hasData(data, root);
    }
    void insertData(int data)
    {
        this->root = insert(data, this->root);
    }

    void deleteData(int data)
    {
        this->root = deleteData(data, this->root);
    }

    void printTree(){
printTree(root);
    }
};