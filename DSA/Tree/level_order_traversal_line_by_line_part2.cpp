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
//auxiliary space: O(n) or theta(width) width of binary tree
void levelOrderTraversal(Node *root){
    queue<Node *> q;
    q.push(root);
    while(!q.empty()){
        int count = q.size();
        for(int i=0;i<count;i++){
            cout<<q.front()->key<<" ";
            if(q.front()->left!=NULL) q.push(q.front()->left);
            if(q.front()->right!=NULL) q.push(q.front()->right);
            q.pop();
            if(q.empty()) goto label;
        }
        cout<<endl;
    }
    label:;
}
int main(){
    Node* root = new Node(10);
    root->left = new Node(8);
    root->right = new Node(30);
    root->right->left = new Node(40);
    root->right->right = new Node(50);
    levelOrderTraversal(root); 
}