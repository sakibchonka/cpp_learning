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

int height(Node *root){
    if(root==NULL) return 0;
    return max(height(root->left),height(root->right))+1;
}

int maxDiameter(Node* root){
    if(root==NULL) return 0;
    if(root->left==NULL && root->right==NULL) return 1;

    return max((1+height(root->left)+height(root->right)),max(maxDiameter(root->left),maxDiameter(root->right)));
}

//method-2
//modify height function
int max_d = 0;
int mod_height(Node *root){
    if(root==NULL) return 0;
    int lh = mod_height(root->left);
    int rh = mod_height(root->right);
    max_d = max(max_d,1+lh+rh);
    return 1+max(lh,rh);
}
int main(){
    Node *root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(60);
    root->left->left = new Node(30);
    root->left->right = new Node(80);
    root->left->right->right = new Node(90);
    root->left->right->right->right = new Node(18);
    root->left->left->left = new Node(40);
    root->left->left->right = new Node(50);
    root->left->left->left->left = new Node(60);
    cout<<maxDiameter(root)<<endl;
    mod_height(root);
    cout<<max_d;
}