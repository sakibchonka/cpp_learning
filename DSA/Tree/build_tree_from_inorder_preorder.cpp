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

//O(n^2)
Node *buildTree(int *in,int *pre, int s, int e){
    if(s>e) return NULL;
    static int pre_index = 0;
    Node *root = new Node(pre[pre_index++]);

    int in_index;
    for(int i=s;i<=e;i++){  //hashing can be used here to reduce complexity to O(n)
        if(in[i]==root->key){
            in_index=i;
            break;
        }
    }
    root->left = buildTree(in,pre,s,in_index-1);
    root->right = buildTree(in,pre,in_index+1,e);
    return root;
}

void preorder(Node *root){
    if(root!=NULL){
        cout<<root->key<<" ";
        preorder(root->left);
        preorder(root->right);
    }
}

int main(){
    int in[] = {20,10,40,30,50};
    int pre[] = {10,20,30,40,50};
    Node *root = buildTree(in,pre,0,4);
    preorder(root);
}