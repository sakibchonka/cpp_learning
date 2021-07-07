#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int key;
    Node *left;
    Node *right;
    Node(int k):key(k){
        left=right=NULL;
    }
};
//time complexity:O(n)
//auxiliary space: O(h) width of binary tree
void levelOrderTraversal(Node *root){
    queue<Node *> q;
    q.push(root);
    while(!q.empty()){
        if(q.front()->left!=NULL)
            q.push(q.front()->left);
        if(q.front()->right!=NULL)
            q.push(q.front()->right);
        cout<<q.front()->key<<" ";
        q.pop();
    }
}
int main(){
    Node* root = new Node(10);
    root->left = new Node(8);
    root->right = new Node(30);
    root->right->left = new Node(40);
    root->right->right = new Node(50);
    levelOrderTraversal(root); 
}