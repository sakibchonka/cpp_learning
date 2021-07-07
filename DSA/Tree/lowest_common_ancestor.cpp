#include<bits/stdc++.h>
using namespace std;

struct Node{
    int key;
    Node *left;
    Node *right;
    Node(int k){
        key = k;
        left=right=NULL;
    }  
};

bool findPath(Node *root,vector<Node*>&path,int n){
    if(root==NULL) return false;
    path.push_back(root);
    if(root->key==n) return true;
    if(findPath(root->left,path,n) || findPath(root->right,path,n))
        return true;
    path.pop_back();
    return false;
}

Node* LCA(Node *root,int n1,int n2){
    vector<Node*> path1,path2;
    if(findPath(root,path1,n1)==false || findPath(root,path2,n2)==false)
        return NULL;
    for(int i=0;i<path1.size()-1 && i<path2.size()-1;i++){
        if(path1[i+1]!=path2[i+1])
            return path1[i];
    }
    return NULL;
}

int main(){
    Node *root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->right->left = new Node(40);
    root->right->right = new Node(50);
    root->right->left->left = new Node(60);
    root->right->right->left = new Node(70);
    root->right->right->right = new Node(80);
    int n1,n2;
    cout<<"enter n1 and n2 values: ";
    cin>>n1>>n2;
    Node *res =LCA(root,n1,n2);
    cout<<res->key;
}