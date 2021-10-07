// implementation of queue using array

#include<iostream>
int arr[33];
int front=-1;
int rear=-1;

bool Isempty(){
    if(front==-1 && rear==-1){
        return true;
    }
    else{
        return false;
    }
}

bool full(){
    if(rear==32){
        return true;
    }
    else{
        return false;
    }
}

void Enqueue(int x){
    if(full()){
        std::cout<<"queue is full\n";
        return;
    }
    else if(Isempty()){
    front=0;
    rear=0;
    arr[rear]=x;
    }
    else{
        ++rear;
        arr[rear]=x;
    }
    }
void Dequeue(){
    if(Isempty()){
        std:: cout<<"deletion can't be performed\n";
        return;
    }
    else if(front==rear){
        front=-1;
        rear=-1;
    }
    else{
        std:: cout<<"dequeue element is "<<arr[front]<<std:: endl;
        ++front;
    }
}
void qprint(){
    int i=front;
    if(Isempty()){
        std:: cout<<"queue is empty\n";
    }
    else{
        while(i<=rear){
            std:: cout<<arr[i]<<"   ";
            i++;
        }
        std::cout<<std::endl;
    }
}

void head(){
    std::cout<<arr[front]<<std::endl;
}


int main(){
    qprint();
    Enqueue(3);   qprint();
    Enqueue(5);   qprint();
    Enqueue(7);   qprint();
    Enqueue(9);   qprint();
    Dequeue();    qprint();
    Enqueue(12);  qprint();
    Enqueue(50);  qprint();
    full();
    Dequeue();    qprint();
    Enqueue(51);  qprint();
    Dequeue();    qprint();
    head();       Isempty();
    return 0;
}
