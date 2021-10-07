// insert a node at the end of the list

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct Node
{
    int data;
    Node *next;
};

Node *Insert(Node *head, int x)
{
    Node *temp = new Node;
    temp->data = x;
    temp->next = NULL;
    if (head == NULL)
    {
        head = temp;
        return head;
    }
    Node *temp1 = head;
    while (temp1->next != NULL)
    {
        temp1 = temp1->next;
    }
    temp1->next = temp;
    return head;
}

void Print(Node *head)
{
    Node *temp = head;
    cout << "Here is the list...  ";
    while (temp->next != NULL)
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << temp->data << endl;
}

void SecondLastNode(Node *head)
{
    while (head->next->next != NULL)
    {
        head = head->next;
    }
    cout << "second last element  " << head->data << endl;
}

int main()
{
    Node *head = NULL;
    int i, n, x;
    cout << "How many number?\n";
    cin >> n;
    int k = n;
    for (i = 0; i < n; i++)
    {
        cout << "Enter Number\n";
        cin >> x;
        head = Insert(head, x);
    }
    Print(head);

    vector<int> v;
    Node *temp = head;
    Node *temp1;
    for (int i = 0; i < k; i++)
    {
        while (temp != NULL)
        {
            temp1 = temp;
            v.push_back(temp->data);
            temp = temp->next;
            head = temp;
            free(temp1);
        }
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < v.size(); i++)
    {
        head = Insert(head, v[i]);
    }
    Print(head);
    SecondLastNode(head);
    return 0;
}
