#include<bits/stdc++.h>
using namespace std;

struct Node{
    int key;
    Node*left;
    Node* right;
    Node(int k){
        key = k;
        left=right=NULL;
    }
};
//time complexity:O(n)
//auxiliary space: O(h)
int sizeOfTree(Node* root){
    if(root==NULL)return 0;
    return 1+sizeOfTree(root->left)+sizeOfTree(root->right);
}

int main(){
    Node* root = new Node(10);
    root->left = new Node(8);
    root->right = new Node(30);
    root->right->left = new Node(40);
    root->right->right = new Node(50);
    cout<<sizeOfTree(root);
}