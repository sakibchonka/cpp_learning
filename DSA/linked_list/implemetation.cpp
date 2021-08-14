#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *next;
    Node(int x){
        data = x;
        next = NULL;
    }
};

Node* insertEnd(Node *head,int x){
    Node *temp = new Node(x);
    if(head == nullptr)
        return temp;
    Node *curr = head;
    while(curr->next!=nullptr){
        curr = curr->next;
    }
    curr->next = temp;
    return temp;
}

Node* insertBegin(Node *head,int x){
    Node *temp = new Node(x);
    temp->next = head;
    return temp;
}

void printlist(Node *head){
    while(head!=nullptr){
        cout<<head->data<<" ";
        head = head->next;
    }
}

int main(){
    Node *head=NULL;
	head=insertEnd(head,10);
	head=insertEnd(head,20);
	head=insertEnd(head,30);
	printlist(head);

    return 0;
}