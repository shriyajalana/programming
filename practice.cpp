// Delete a node at nth position

#include<iostream>
using namespace std;
struct Node{
    int data;
    Node* next;
};
Node* head;

void Insert(int data){
    Node* temp=new Node;
    temp->data=data;
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

void Print(){
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<"  ";
        temp=temp->next;
    }
    cout<<"\n";
}

void Delete(int p){
    Node* temp;
    temp=head;
    if(p==1){
        head=temp->next;
        free(temp);     //delete node
        return;
    }
    Node* temp1=head;
    for(int i=0;i<p-2;i++){
        temp1=temp1->next;   //p-1 node
    }
    Node* temp2=temp1->next; //p node
    temp1->next=temp2->next; // connection p-1th node to p+1th node 
    free(temp2);   //delete node free pth node
}

int main(){
    head=NULL;
    Insert(7);
    Insert(9);
    Insert(2);
    Insert(45);
    Print();
    cout<<"Enter position to delete \n";
    int pos;
    cin>>pos;
    Delete(pos);
    Print();
    return 0;
}
