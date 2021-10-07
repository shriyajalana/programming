//Double linkedlist
#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node *next;
    Node *prev;
};
Node *head;
Node *GetNewNode(int data)
{
    Node *NewNode = new Node;
    NewNode->data = data;
    NewNode->next = NULL;
    NewNode->prev = NULL;
    return NewNode;
}
void InsertAtHead(int data)
{
    Node *NewNode = GetNewNode(data);
    if (head == NULL)
    {
        head = NewNode;
        return;
    }
    NewNode->next = head;
    head->prev = NewNode;
    head = NewNode;
}

void Print()
{
    Node *temp;
    temp = head;
    while (temp->next != NULL)
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << temp->data << endl;
}

void ReversePrint()
{
    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    while (temp->prev != NULL)
    {
        cout << temp->data << " -> ";
        temp = temp->prev;
    }
    cout << temp->data << endl;
}
void InsertAtTail(int data)
{
    Node *temp = GetNewNode(data);
    if (head == NULL)
    {
        head = temp;
        return;
    }
    Node *temp1 = head;
    while (temp1->next != NULL)
    {
        temp1 = temp1->next;
    }
    temp->prev = temp1;
    temp1->next = temp;
}
void InsertionAtAnyPosition(int data, int position)
{
    Node *newNode = GetNewNode(data);
    if (position == 1)
    {
        // insertion at head
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
        return;
    }
    Node *temp = head;
    while (position-- > 2)
    {
        temp = temp->next;
    }
    if (temp->next == NULL)
    {
        newNode->prev = temp;
        temp->next = newNode;
    }
    else
    {
        Node *temp1 = temp->next;

        newNode->prev = temp;
        newNode->next = temp1;

        temp->next = newNode;
        temp1->prev = newNode;
    }
}

int main()
{
    head = NULL;
    InsertAtHead(2);
    InsertAtHead(7);
    InsertAtHead(5);
    Print();
    InsertAtTail(9);
    InsertAtTail(1);
    InsertAtTail(4);
    InsertAtTail(12);
    Print();
    //ReversePrint();
    InsertionAtAnyPosition(786, 5);
    Print();
    InsertionAtAnyPosition(92, 1);
    Print();
    InsertionAtAnyPosition(1192, 10);
    InsertionAtAnyPosition(12, 10);
    InsertionAtAnyPosition(144, 12);
    Print();
    return 0;
}
