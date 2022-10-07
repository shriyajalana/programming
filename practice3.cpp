// Inserting a new node at nth position of the list

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct Node
{
    int data;
    Node *next;
};
Node *head;

void Insert(int data, int n)
{
    Node *temp1 = new Node;
    temp1->data = data;
    temp1->next = NULL;
    if (n == 1)
    {
        temp1->next = head;
        head = temp1;
        return;
    }
    Node *temp2 = head;
    for (int i = 0; i < n - 2; i++)
    {
        temp2 = temp2->next;
    }
    temp1->next = temp2->next;
    temp2->next = temp1;
}

void Print()
{
    Node *temp = head;
    cout << "the list is...  ";
    while (temp != NULL)
    {
        cout << temp->data << "  ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    head = NULL;
    int n, data, num;
    int k = n;
    cout << "how many number do you wanted to insert?\n";
    cin >> num;
    while (n > 0)
    {
        cout << "enter number\n";
        cin >> data;
        cout << "at which position\n";
        cin >> n;
        Insert(data, n);
        n--;
    }
    Print();

    return 0;
}
