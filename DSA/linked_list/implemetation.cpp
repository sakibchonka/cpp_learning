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

Node* delHead(Node *head){
    if(head == nullptr)
        return nullptr;
    else{
        Node *temp = head->next;
        delete head;
        return temp;
    }
}

Node* delTail(Node *head){
    if(head == nullptr)
        return nullptr;
    if(head->next == nullptr){
        delete head;
        return nullptr;
    }
    Node *curr = head;
    while(curr->next->next !=nullptr){
        curr = curr->next;
    }
    delete curr->next;
    curr->next =nullptr;
    return head;
}

Node* insertPos(Node *head,int pos,int data){
    Node *temp = new Node(data);
    if(pos == 1){
        temp->next = head;
        return temp;
    }
    Node *curr = head;
    for(int i=1; i<=pos-2 && curr!=nullptr; i++){
        curr = curr->next;
    }
    if(curr == nullptr) 
        return head;
    temp->next = curr->next;
    curr->next = temp;
    return head;
}

void printlist(Node *head){
    while(head!=nullptr){
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<"\n";
}

int main(){
    Node *head=new Node(10);
	head->next=new Node(20);
	head->next->next=new Node(30);
	printlist(head);
	head=delTail(head);
	printlist(head);

    return 0;
}