#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    // constructor
    Node(int data)
    {
        this->data=data;
        this->next=NULL;
    }
};
/*Node *insertathead(Node *&head, int data)
{
    Node *temp = new Node(data);
    temp->next = head;
    head = temp;
}*/
Node *insertattail(Node *& tail,int data)
{
    Node *temp=new Node(data);
    tail->next=temp;
    tail=temp;
}
void insertatposition(Node *head,int position,int data)
{
    Node *temp=head;
    int cnt=0;
    while(cnt<position-1)
    {
        temp=temp->next;
        cnt++;
    }
    Node *nodetoinsert=new Node(data);
    nodetoinsert->next=temp->next;
    temp->next=nodetoinsert; 
}
void print(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}
int main()
{
    Node *node1=new Node(10);
    Node *head=node1;
    Node *tail=node1;
    print(head);
    insertattail(tail,12);
    print(head);
    insertatposition(head,1,22);
    print(head);
}
