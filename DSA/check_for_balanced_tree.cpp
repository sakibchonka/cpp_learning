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

int checkForBalTree(Node *root){
    if(root == NULL) return 0;
    int lh = checkForBalTree(root->left);
    if(lh==-1) return -1;
    int rh = checkForBalTree(root->right);
    if(rh==-1) return -1;
    if(abs(lh-rh)>1) return -1;
    else 
        return max(lh,rh)+1;
}

int main(){
    Node *root = new Node(3);
    root->left = new Node(4);
    root->right = new Node(8);
    root->left->left = new Node(5);
    root->left->right = new Node(9);
    root->right->right = new Node(7);
    root->right->right->left = new Node(6);
    cout<<checkForBalTree(root);
}