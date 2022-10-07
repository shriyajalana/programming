#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node *next;
};
Node *head = NULL;
void insert(int data)
{
    Node *temp = new Node;
    temp->data = data;
    temp->next = NULL;
    temp->next = head;
    head = temp;
    return;
}

void print()
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void secondLast()
{
    Node *temp = head;
    temp = temp->next;
    if (temp->next->next->next->data == 2)
    {
        cout << "Yes it is equal to two\n";
    }
    cout << temp->data << endl;
}
void swap()
{
    Node *temp1 = head;
    Node *temp2 = temp1->next;
    while (temp1 != NULL && temp2->next != NULL)
    {
        int x;
        x = temp1->data;
        temp1->data = temp2->data;
        temp2->data = x;
        temp1 = temp2->next;
        temp2 = temp1->next;
    }
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    insert(4);
    print();
    insert(2);
    print();
    insert(5);
    print();
    insert(8);
    print();
    insert(1);
    print();
    insert(9);
    print();
    // insert(11);
    // print();
    swap();
    return 0;
}
