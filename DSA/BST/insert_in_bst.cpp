#include<bits/stdc++.h>
using namespace std;

struct Node{
    int key;
    Node *left;
    Node *right;
    Node(int k){
        key = k;
        left = right = NULL;
    }
};

Node* itr_insert(Node* root,int ele){
    Node *temp = new Node(ele);
    Node *parent = nullptr, *curr = root;
    while(curr!=nullptr){
        parent = curr;
        if(curr->key<ele)
            curr = curr->right;
        else if(curr->key>ele)
            curr = curr->left;
        else 
            return root;
    }
    if(parent == nullptr)
        return temp;
    else if(parent->key<ele)
        parent->right = temp;
    else
        parent->left = temp;
    return root;

}

Node* rec_insert(Node* root,int ele){
    if(root == NULL){
        Node *n = new Node(ele);
        return n;
    }
    else{
        if(ele<root->key){
            root->left = rec_insert(root->left,ele);
        }
        else{
            root->right = rec_insert(root->right,ele);
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
    rec_insert(root,6);
    display(root); cout<<endl;
    Node* b = itr_insert(root,6);
    display(b);
}