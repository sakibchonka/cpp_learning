#include<bits/stdc++.h>
using namespace std;

struct Node{
    int key;
    Node *left;
    Node *right;
    //no of nodes in left subtree
    int lcount;
    Node(int k){
        key = k;
        left = right = NULL;
        lcount=0;
    }
};

Node* insert(Node *root,int x){
    if(root == NULL)
        return new Node(x);
    
    if(x<root->key){
        root->left = insert(root->left,x);
        root->lcount++;
    }
    else if(x>root->key){
        root->right = insert(root->right,x);
    }
    return root;
}

Node* KthSmallest(Node *root,int k){
    if(root == NULL) 
        return NULL;
    
    int count = root->lcount + 1;
    if(count == k) return root;
    if(count>k){
        return KthSmallest(root->left,k);
    }
    return KthSmallest(root->right,k-count);
}

int main() {
	
	Node *root=NULL;
    int keys[] = {20,8,22,4,12,10,14};

    for(int x:keys)
        root = insert(root,x);

	int k=4;
	cout<<"Kth Smallest: ";
	Node *res = KthSmallest(root,k);
	cout<<res->key;

	return 0;
}