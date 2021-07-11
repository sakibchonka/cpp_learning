#include<bits/stdc++.h>
using namespace std;

struct Node{
    int key;
    Node *left;
    Node *right;
    Node(int k){
        key = k;
        left = right = nullptr;
    }
};

//not the best successor function
//assumes the node to be deleted has right node present
Node* successor(Node* curr){
    curr = curr->right;
    while(curr!=nullptr && curr->left!=nullptr){
        curr = curr->left;
    }
    return curr;
}

Node* deleteBST(Node *root,int ele){
    if(root == nullptr) return root;
    else if(root->key<ele)
        root->right = deleteBST(root->right,ele);
    else if(root->key>ele)
        root->left = deleteBST(root->left,ele);
    else{
        if(root->left == nullptr){
            Node *temp = root->right;
            delete root;
            return temp;
        }
        else if(root->right == nullptr){
            Node *temp = root->left;
            delete root;
            return temp;
        }
        else{
            Node *succ = successor(root);
            root->key = succ->key;
            root->right = deleteBST(root->right,succ->key);
        }
    }
    return root;
}

void display(Node* root){
    if(root==NULL)return;
    display(root->left);
    cout<<root->key<<" ";
    display(root->right);
}

int main(){
    Node *root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(15);
    root->left->left = new Node(3);
    root->left->right = new Node(7);
    root->right->right = new Node(18);
    deleteBST(root,10);
    display(root);
}