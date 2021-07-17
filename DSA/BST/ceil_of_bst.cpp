#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int key;
    Node *left;
    Node *right;
    Node(int k){
        key = k;
        left = right = nullptr;
    }
};

Node* Ceil(Node *root,int ele){
    Node *res = nullptr;
    Node *curr = root;
    while(curr!=nullptr){
        if(curr->key == ele) return curr;
        else if(curr->key < ele){
            curr = curr->right;
        }
        else{
            res = curr;
            curr = curr->left;
        }
    }
    return res;
}

int main(){
    Node *root = new Node(50);
    root->left = new Node(30);
    root->right = new Node(70);
    root->left->left = new Node(20);
    root->left->right = new Node(40);
    root->right->left = new Node(60);
    root->right->right = new Node(80);
    root->right->left->left = new Node(55);
    root->right->left->right = new Node(65);
    Node *ans = Ceil(root,90);
    if(ans == nullptr) cout<<"NULL";
    cout<<ans->key;
}