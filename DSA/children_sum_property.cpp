#include<bits/stdc++.h>
using namespace std;

struct Node{
    int key;
    Node *left;
    Node *right;
    Node(int key){
        this->key = key;
    }
};


bool childrenSumProp(Node *root){
    if(root==NULL) return true;
    if(root->left==NULL && root->right==NULL) return true;
    int sum=0;
    if(root->left!=NULL) sum+=root->left->key;
    if(root->right!=NULL) sum+=root->right->key;
    return root->key==sum && childrenSumProp(root->left) && childrenSumProp(root->right);
    
}

int main(){
    Node *root = new Node(20);
    root->left = new Node(8);
    root->right = new Node(12);
    root->left->left = new Node(3);
    root->left->right = new Node(5);
    cout<<childrenSumProp(root);
}