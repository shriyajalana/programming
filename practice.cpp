
#include <iostream>
#include <vector>
using namespace std;

int addRungs(vector<int> &rungs, int dist)
{
    int height = 0;
    int ans = 0;
    int h;
    for (int i = 0; i < rungs.size(); i++)
    {
        h = rungs[i] - height;
        if (h > dist)
        {
            if (dist == 1)
            {
                ans += h - 1;
            }
            else
            {
                ans += h / dist;
            }
        }
        height = rungs[i];
    }
    return ans;
}
int main()
{
    vector<int> rungs = {4, 8, 12, 16};
    int dist = 3;
    cout << addRungs(rungs, dist) << endl;
    return 0;
}
=======

#include<iostream>
#include<list>
using namespace std;
void display(list<int> &li){
    list<int> :: iterator it;
    for(it=li.begin();it!=li.end();it++){
        cout<<*it<<"  ";
    }
    cout<<endl;
}
int main(){
    list<int> l;
    l.push_back(6);
    l.push_back(4);
    l.push_back(2);
    l.push_back(8);
    display(l);
    list<int> lis;
    list<int> :: iterator it;
    it=lis.begin();
    
    // vector<int> v;
    // v.push_back(5);
    // v.push_back(5);
    // cout<<(*max_element(v.begin(),v.end()))<<endl;
    // v[2]=7;
    // for(int i=0;i<v.size();i++){
    //     cout<<v.at(i)<<endl;
    // }
    // int i;
    // for(i=1;i<10;i++){
    //     v.push_back(i);
    // }
    // for(i=0;i<v.size();i++){
    //     cout<<v[i];
    // }
    // cout<<endl;
    // if(v.empty()){
    //     cout<<"vector is empty  \n";
    // }
    // else{
    //     cout<<"vector is not  empty\n";
    // }
    // cout<<endl;
    // cout<<"vector size is:  "<<v.size()<<"  vector capacity:  "<<v.capacity()<<"\n";
=======
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
}