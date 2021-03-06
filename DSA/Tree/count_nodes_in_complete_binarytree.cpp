#include<bits/stdc++.h>
using namespace std;

struct Node{
    int key;
    Node *left;
    Node *right;
    Node(int k){
        key = k;
        left = right =NULL;
    }
};

//O(log n * log n)
int countNode(Node *root){
    if(root==NULL) return 0;
    int lh=0,rh=0;
    Node *curr = root;
    while(curr!=NULL){
        curr = curr->left;
        lh++;
    }
    curr=root;
    while(curr!=NULL){
        curr = curr->right;
        rh++;
    }
    if(lh==rh)
        return pow(2,lh)-1;
    return 1 + countNode(root->left) + countNode(root->right);

}

int main(){
    Node *root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->left->left = new Node(40);
    root->left->right = new Node(50);
    root->right->left = new Node(60);
    root->right->right = new Node(70);
    root->left->left->left = new Node(80);
    root->left->left->right = new Node(90);
    root->left->right->left = new Node(100);
    root->left->right->right = new Node(110);
    root->right->left->left = new Node(120);
    cout<<countNode(root);
}