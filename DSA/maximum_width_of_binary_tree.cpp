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

int maxWidth(Node *root){
    if(root==NULL) return 0;
    queue<Node *> q;
    q.push(root);
    q.push(NULL);
    int width=1;
    int count=0;
    while(q.size()>1){
        if(q.front()==NULL){
            count=0;
            q.push(NULL);
            q.pop();
            continue;
        }
        if(q.front()->left!=NULL)
            q.push(q.front()->left);
        if(q.front()->right!=NULL)
            q.push(q.front()->right);
        count++;
        q.pop();
        width = max(width,count);
    }
    return width;
}

int main(){
    Node *root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->left->left = new Node(40);
    root->left->left = new Node(80);
    root->right->left = new Node(50);
    root->right->right = new Node(60);
    cout<<maxWidth(root);
}