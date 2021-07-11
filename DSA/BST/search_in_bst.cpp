#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int key;
    Node *left;
    Node *right;
    Node(int k){
        key = k;
        left = right = NULL;
    }
};

bool rec_search(Node* root,int v){
    if(root == NULL) return false;
    if(root->key == v) return true;
    if(root->key<v)
        return rec_search(root->right,v);
    else
        return rec_search(root->left,v);
}

bool itr_search(Node* root,int v){
    while(root!=nullptr){
        if(root->key == v) return true;
        else if(root->key>v)
            root = root->left;
        else
            root = root->right;
    }
    return false;
}

int main(){
    Node *root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(15);
    root->left->left = new Node(3);
    root->left->right = new Node(7);
    root->right->right = new Node(18);
    cout<<rec_search(root,15)<<endl;
    cout<<itr_search(root,15);
}
