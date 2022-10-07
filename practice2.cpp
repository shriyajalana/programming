//reverse the linkedlist by iteratively
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
    Node* temp1=head;
    while(temp1->next!=NULL){
        temp1=temp1->next;
    }
    temp1->next=temp;
}

void Reverse(){
    Node *current,*pre,*next;
    pre=NULL;
    current=head;
    while(current!=NULL){
        next=current->next;
        current->next=pre;
        pre=current;
        current=next;
    }
    head=pre;
}

void Print(){
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<"  ";
        temp=temp->next;
    }
    cout<<"\n";
}

int main(){
    head=NULL;
    Insert(3);
    Insert(7);
    Insert(22);
    Insert(15);
    cout<<"List before reverse is...";
    Print();
    Reverse();
    cout<<"List after reverse is...";
    Print();
    return 0;
}
