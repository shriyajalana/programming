//printing number in farward and backward direction using recursion method

#include<iostream>
using namespace std;
struct Node{
    int data;
    Node* next;
};

Node* Insert(Node* head,int n){
    Node* temp=new Node;
    temp->data=n;
    temp->next=NULL;
    if(head==NULL){
        head=temp;
        return;
    }
    else{
        Node* temp1;
        temp1=head;
        while(temp1->next!=NULL){
            temp1=temp1->next;
        }
        temp1->next=temp;
    }
    return head;
}

void Print(Node* head){
    if(head==NULL){
        cout<<"\n";
        return;
    }
    cout<<head->data<<"  ";      // Number will print in the forward direction
    Print(head->next);           //recursive call of Print function
    cout<<head->data<<"  ";      //Number will print in the backward direction
}

int main(){
    Node* head=NULL;
    head=Insert(head,2);
    head=Insert(head,5);
    head=Insert(head,7);
    head=Insert(head,4);
    Print(head);
    return 0;
}
