// this is the implementation of Circular Queue data structure 
// we have to increment/decrement in a circular manner::                             (i+1)%n

// current_position=i;
// next_position= (i+1)%n;
// previous_position=(i+n-1)%n   (rear+5-front)%5+1
#include<iostream>
int arr[5];
int front=-1;
int rear=-1;

bool Isempty(){
    return (front==-1 && rear==-1) ? true : false;
}

bool full(){
    return ((rear+1)%5==front) ? true : false;
}

void Enqueue(int x){
    if(full()){
        std:: cout<<"queue is full\n";
        return;
    }
    if(Isempty()){
        front=0;
        rear=0;
        arr[rear]=x;
    }
    else{
        rear=(rear+1)%5;
        arr[rear]=x;
    }
}

void Dequeue(){
    if(Isempty()){
        std::cout<<"c queue is empty\n";
        return;
    }
    if(front==rear){
        std:: cout<<"Dequeue element is: "<<arr[front];
        front=-1;
        rear=-1;
    }
    else{
        std:: cout<<"Dequeue element is: "<<arr[front]<<std::endl;
        front=(front+1)%5;
    }
}

void head(){
    (Isempty())? std:: cout<<"cqueue is empty\n" :   std::cout<<arr[front]<<std::endl;
}

void qprint(){ 
    int count = (rear+5-front)%5 + 1;
    std::cout<<"Queue   : ";
    for(int i = 0; i <count; i++)
    {
        int index = (front+i) % 5; // Index of element while travesing circularly from front
        std::cout<<arr[index]<<" ";
    }
    std::cout<<"\n";
}

int main(){
    Enqueue(3);
    Enqueue(5);
    Enqueue(7);
    qprint();
    Enqueue(9);
    qprint();
    Dequeue();
    Enqueue(12);
    Dequeue();
    qprint();
    Enqueue(51);
    Enqueue(12);
    qprint();
    Isempty();
    full();
    head();
    Enqueue(12);
    Dequeue();Dequeue();Dequeue();Dequeue();Dequeue();Dequeue();
    return 0;
}
