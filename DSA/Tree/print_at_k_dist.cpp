#include<bits/stdc++.h>
using namespace std;

struct Node{
    int key;
    Node* left;
    Node* right;
    Node(int k){
        key=k;
        left=right=NULL;
    }
};
//time complexity:O(n)
//auxiliary space: O(h)
void print_at_k(Node* root,int k){
    if(root==NULL)
        return;
    if(k==0){
        cout<<root->key<<" ";
        return;
    }
    print_at_k(root->left,k-1);
    print_at_k(root->right,k-1);
    return;
}
int main(){
    Node* root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->left->left = new Node(40);
    root->left->right = new Node(50);
    root->right->right = new Node(70);
    print_at_k(root,2);
}