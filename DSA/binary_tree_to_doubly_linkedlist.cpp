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


Node* BTtoDD(Node *root){
    if(root==NULL) return root;
    static Node *prev = NULL;
    Node *head = BTtoDD(root->left);
    if(prev == NULL) head = root;
    else{
        root->left = prev;
        prev->right = root;
    }
    prev = root;
    BTtoDD(root->right);
    return head;
}

void printList(Node *node)
{
    while (node!=NULL)
    {
        cout << node->key << " ";
        node = node->right;
    }
}

int main(){
    Node *root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(20);
    root->right->left = new Node(30);
    root->right->right = new Node(40);
    Node *head = NULL;
    head = BTtoDD(root);
    printList(head);
}