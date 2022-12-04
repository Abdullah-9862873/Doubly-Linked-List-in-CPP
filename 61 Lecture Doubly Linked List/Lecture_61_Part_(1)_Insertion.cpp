#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class node{
    public:
        int data;
        node* next;
        node* prev;

        node(int val){
            data = val;
            next = NULL;
            prev = NULL;
        }
};

void InsertAtHead(node* &head, int val){
    node* n = new node(val);
    // Here is the case that if head is empty so n->next will be pointing towards NULL
    // But head->prev=n; this can't be accessed so we have to write a condition

    n->next=head;
    if(head!=NULL){
        head->prev=n;
    }
    head=n;
}

void InsertAtTail(node* &head, int val){

    if(head==NULL){
        InsertAtHead(head, val);
        return;
    }
    node* n = new node(val);

    node*temp = head;
    while(temp->next!=NULL){
        temp= temp->next;
    }

    temp->next = n;
    n->prev = temp;
    // Constructor has already made the next of n the NULL value
}

void display(node* &head){
    node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

int main(){
    node* head = NULL;
    InsertAtTail(head, 1);
    InsertAtTail(head, 2);
    InsertAtTail(head, 3);
    InsertAtTail(head, 4);
    InsertAtTail(head, 5);
    display(head);
    InsertAtHead(head, 6);
    display(head);

    return 0;
}