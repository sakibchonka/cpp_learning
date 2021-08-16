#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *next;
    Node *prev;
    Node(int d){
        data = d;
        next = prev = nullptr;
    }
};

void push(Node** head, int new_data)
    {
        Node *new_node = new Node(new_data);

        new_node->prev = nullptr;
        new_node->next = (*head);

        if ((*head) != nullptr) {
            (*head)->prev = new_node;
        }

        (*head) = new_node;
    }

Node* reverse(Node* head){
    if(head == nullptr || head->next == nullptr)
        return head;
    Node* curr  = head, *prev = nullptr;
    while(curr!=nullptr){
        prev = curr->prev;
        curr->prev = curr->next;
        curr->next = prev;
        curr = curr->prev;
    }
    return prev->prev;
}

void printList(Node *node)
{
    while(node != NULL)
    {
        cout << node->data << " ";
        node = node->next;
    }
}

int main(){
    Node* head = NULL;
     
    /* Let us create a sorted linked list to test the functions
    Created linked list will be 10->8->4->2 */
    push(&head, 2);
    push(&head, 4);
    push(&head, 8);
    push(&head, 10);
     
    cout << "Original Linked list" << endl;
    printList(head);
     
    /* Reverse doubly linked list */
    head = reverse(head);
     
    cout << "\nReversed Linked list" << endl;
    printList(head);        
     
}