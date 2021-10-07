#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node *next;
};

//Inserts a Node at head of singly linked list
Node *InsertAtHead(Node *head, int data)
{
    Node *temp = new Node;
    temp->data = data;
    temp->next = head;
    head = temp;
    return head;
}

//Inserts a Node at tail of singly linked list
Node *InsertAtTail(Node *head, int data)
{
    Node *temp = new Node;
    temp->data = data;
    temp->next = NULL;
    {
        Node *LastNode = head;
        while (LastNode->next != NULL)
        {
            LastNode = LastNode->next;
        }
        LastNode->next = temp;
    }
    return head;
}

//Delete a Node of linked list at any position
Node *DeleteNode(Node *head, int position)
{
    Node *temp = head;
    cout << "deleted element from " << position << " position: ";
    if (position == 1)
    {
        cout << temp->data << endl;
        head = head->next;
        free(temp);
    }
    else
    {
        for (int i = 0; i < position - 2; i++)
        {
            temp = temp->next; //n-1         3 4 5
        }
        Node *temp1 = temp->next; //n
        cout << temp->data << endl;
        temp->next = temp1->next;
        free(temp1);
    }
    return head;
}

//Traverse to the second last node of linked list
void TraverseToSecondLastNode(Node *head)
{
    cout << "second last element: ";
    while (head->next->next != NULL)
    {
        head = head->next;
    }
    cout << head->data << endl;
}

// Reverse a linked list using Iterative method
Node *IterativeReverse(Node *head)
{
    Node *current = head;
    Node *previous = NULL;
    Node *Next;
    cout << "iterative reverse: ";
    while (current != NULL)
    {
        Next = current->next;
        current->next = previous;
        previous = current;
        current = Next;
    }
    head = previous;
    return head;
}

// Reverse a linked list Recursive method
Node *RecursiveReverse(Node *ptr)
{
    Node *head;
    if (ptr->next == NULL)
    {
        head = ptr;
        return head;
    }
    head = RecursiveReverse(ptr->next);
    Node *temp = ptr->next;
    temp->next = ptr;
    ptr->next = NULL;
    return head;
}

//Prints all elements in linked list in forward traversal order.
void Print(Node *head)
{
    Node *traverse = head;
    //cout << "linked list: ";
    while (traverse->next != NULL)
    {
        cout << traverse->data << " -> ";
        traverse = traverse->next;
    }
    cout << traverse->data << endl;
}

//Prints all elements in linked list in reverse order using recursion.
void ReversePrint(Node *head)
{
    if (head == NULL)
    {
        return;
    }
    ReversePrint(head->next);
    cout << head->data << " ";
}

int main()
{
    Node *head = NULL;
    head = InsertAtHead(head, 40);
    head = InsertAtTail(head, 50);
    head = InsertAtHead(head, 30);
    head = InsertAtTail(head, 60);
    head = InsertAtHead(head, 20);
    head = InsertAtTail(head, 70);
    head = InsertAtHead(head, 10);
    head = InsertAtTail(head, 80);
    head = InsertAtHead(head, 5);
    head = InsertAtTail(head, 90);
    Print(head);
    head = DeleteNode(head, 1);
    Print(head);
    head = DeleteNode(head, 4);
    Print(head);
    TraverseToSecondLastNode(head);
    head = IterativeReverse(head);
    Print(head);
    cout << "reverse print: ";
    ReversePrint(head);
    cout << endl;
    cout << "reverse recursion: ";
    head = RecursiveReverse(head);
    Print(head);
    return 0;
}

/*
Output:

5 -> 10 -> 20 -> 30 -> 40 -> 50 -> 60 -> 70 -> 80 -> 90
deleted element from 1 position: 5
10 -> 20 -> 30 -> 40 -> 50 -> 60 -> 70 -> 80 -> 90
deleted element from 4 position: 30
10 -> 20 -> 30 -> 50 -> 60 -> 70 -> 80 -> 90
second last element: 80
iterative reverse: 90 -> 80 -> 70 -> 60 -> 50 -> 30 -> 20 -> 10
reverse print: 10 20 30 50 60 70 80 90 
reverse recursion: 10 -> 20 -> 30 -> 50 -> 60 -> 70 -> 80 -> 90

*/
