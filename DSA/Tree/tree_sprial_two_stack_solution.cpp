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

void spiralTraversal(Node *root){
    if(root == NULL) return;
    stack<Node*> s1;
    stack<Node*> s2;
    s1.push(root);
    while(!s1.empty() || !s2.empty()){
        while(!s1.empty()){
            Node *curr = s1.top();
            s1.pop();
            cout<<curr->key<<" ";
            s2.push(curr->left);
            s2.push(curr->right);
        }
        while(!s2.empty()){
            Node *curr = s2.top();
            s2.pop();
            cout<<curr->key<<" ";
            s1.push(curr->right);
            s1.push(curr->left);
        }
    }
}

int main(){
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    spiralTraversal(root);
}