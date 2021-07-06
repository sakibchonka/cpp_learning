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
    queue<Node *> q;
    stack<int> st;
    bool  reverse = false;
    q.push(root);
    while(q.empty()==false){
        int count = q.size();
        for(int i=0;i<count;i++){
            Node *curr = q.front();
            q.pop();
            if(reverse){
                st.push(curr->key);
            }
            else
                cout<<curr->key<<" ";
            if(curr->left!=NULL) q.push(curr->left);
            if(curr->right!=NULL) q.push(curr->right);
        }
        if(reverse){
            while(st.empty()==false){
                cout<<st.top()<<" ";
                st.pop();
            }
        }
        reverse = !reverse;
        cout<<endl;
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