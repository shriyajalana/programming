// queue using LinkedList Enqueue-O(1)  from tail and Dequeue from head pointer

#include <iostream>
struct Node
{
    int data;
    Node *next;
};

Node *front = NULL;
Node *rear = NULL;

void Enqueue(int x)
{
    Node *temp = new Node;
    temp->data = x;
    temp->next = NULL;
    if (front == NULL && rear == NULL)
    {
        front = rear = temp;
        return;
    }
    rear->next = temp;
    rear = temp;
}

void Dequeue()
{
    Node *temp = front;
    if (front == NULL && rear == NULL)
    {
        return;
    }
    if (front == rear)
    {
        front = rear = NULL;
    }
    else
    {
        front = front->next;
    }
    free(temp);
}

bool IsEmpty()
{
    return (front == NULL && rear == NULL) ? true : false;
}

void Front()
{
    if (IsEmpty())
    {
        std::cout << "Queue is Empty:\n";
    }
    else
    {
        std::cout << front->data << std::endl;
    }
}

void Print()
{
    Node *temp = front;
    while (temp != NULL)
    {
        std::cout << temp->data << "  ";
        temp = temp->next;
    }
    std::cout << std::endl;
}

int main()
{
    Front();
    IsEmpty();
    Enqueue(2);
    Print();
    Front();
    IsEmpty();
    Enqueue(4);
    Print();
    Front();
    IsEmpty();
    Enqueue(6);
    Print();
    Dequeue();
    Print();
    Enqueue(8);
    Print();
    Front();
    return 0;
}
