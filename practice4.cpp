//reverse a linked list using recurssion method
#include<iostream>
using namespace std;
struct Node{
    int data;
    Node* next;
};
Node* head;
void Insert(int n){
    Node* temp=new Node;
    temp->data=n;
    temp->next=NULL;
    if(head==NULL){
        head=temp;
        return;
    }
    else{
        Node* temp1=head;
        while(temp1->next!=NULL){
            temp1=temp1->next;
        }
        temp1->next=temp;
    }
}
void Print(){
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<"  ";
        temp=temp->next;
    }
    cout<<endl;
}

void ReversePrint(Node* p){
    if(p->next==NULL){
        head=p;
        return;
    }
    ReversePrint(p->next);
    Node* q=p->next;
    q->next=p;
    p->next=NULL;
}

int main(){
    head=NULL;
    Insert(4);
    Insert(7);
    Insert(2);
    Insert(8);
    Insert(9);
    ReversePrint(head);
    Print();
    return 0;
}
