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

int max_level=0;
void printLeftView(Node *root,int level){
    if(root==NULL) return;
    if(level>max_level){
        cout<<root->key<<" ";
        max_level = level;
    }
    printLeftView(root->left,level+1);
    printLeftView(root->right,level+1);
}

int main(){
    Node *root = new Node(10);
    root->left = new Node(50);
    root->right = new Node(60);
    root->right->left = new Node(70);
    root->right->right = new Node(20);
    root->right->left->right = new Node(8);
    printLeftView(root,1);
}
