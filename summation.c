// insert a node at the beginning of the list
#include <iostream>
using namespace std;

struct Node
{
    int data; //creating a node with two variable one is data and another one is pointer
    Node *next;
};

Node *Insert(Node *head, int x)
{
    Node *temp = new Node; //creating a node
    temp->data = x;        //storing data in the node
    temp->next = NULL;     //storing address in the node

    temp->next = head; // linking node with other node         phle jodo
    head = temp;       // breaking a link and adding with the head   phir todo
    return head;
}

void Print(Node *temp)
{
    cout << "Here is the list: ";
    while (temp->next != NULL)
    {
        temp = temp->next;
        cout << temp->data << " -> ";
    }
    cout << endl;
    cout << temp->data << "  ";
    cout << "\n";
}

int main()
{
    Node *head = NULL;
    int i, n, x;
    cout << "How many number?\n";
    cin >> n;
    for (i = 0; i < n; i++)
    {
        cout << "Enter Number\n";
        cin >> x;
        head = Insert(head, x);
    }
    Print(head);
    return 0;
}
