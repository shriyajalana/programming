//stack using linkedlist at the beginning of the list O(1) i.e. constant time complexity
#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node *next;
};
Node *head;

void PushAtBeginning(int data)
{
    Node *temp = new Node;
    temp->data = data;
    temp->next = NULL;
    temp->next = head;
    head = temp;
}

void Poping()
{
    if (head == NULL)
    {
        cout << "Poping not possible\n";
        return;
    }
    Node *temp = head;
    cout << "Pop item is: " << head->data << endl;
    head = head->next;
    free(temp);
}
void Print()
{
    Node *temp;
    temp = head;
    cout << "items is...  ";
    while (temp != NULL)
    {
        cout << temp->data << "  ";
        temp = temp->next;
    }
    cout << "\n";
}

int main()
{
    head = NULL;
    Print();
    Poping();
    PushAtBeginning(5);
    Print();
    Poping();
    PushAtBeginning(3);
    Print();
    PushAtBeginning(7);
    Print();
    Poping();
    PushAtBeginning(4);
    Print();
    Poping();
    Print();
    return 0;
}
