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

const int EMPTY = -1;
void serialize(Node *root,vector<int>&ser){
    if(root==NULL){
        ser.push_back(EMPTY);
        return;
    }
    ser.push_back(root->key);
    serialize(root->left,ser);
    serialize(root->right,ser);
}

int index = 0;
Node* deserialize(vector<int> &ser){
    if(index == ser.size()) return NULL;
    if(ser.at(index)==EMPTY) return NULL;
    Node *val = new Node(ser.at(index));
    index++;
    val->left = deserialize(ser);
    val->right = deserialize(ser);
    return val;
}

int main(){
    Node *root=new Node(10);
	root->left=new Node(20);
	root->right=new Node(30);
	root->left->left=new Node(40);
	root->left->right=new Node(50);
	root->right->left=new Node(60);
    //n+n+1 size of vector where (n+1) are NULL
    vector<int> ser;
    serialize(root,ser);
    Node *root = deserialize(ser);
    
}