#include<iostream>
using namespace std;
class Node
{
    public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data=data;
        this->next=NULL;
    }
};
Node *input()//function of node type bcz returning head
{
    cout<<"ENTER The data for the list"<<endl;
    int data;
    cin>>data;
    Node *head=NULL;
    Node *tail=NULL;
    while(data!=-1)
    {
        Node *newNode=new Node(data);
        if(head==NULL)
        {
            head=newNode;
            tail=newNode;
        }
        else
        {
            tail->next=newNode;
            tail=newNode;
        }
        cin>>data;
    }
    return head;
}
void print(Node *head)
    {
        Node *temp=head;
        while(head!=NULL)
        {
            cout<<head->data<<" ";
            head=head->next;
        }
        cout<<endl;
    }
Node *merge(Node *h1,Node *h2)
{
    Node *finalhead=NULL;
    Node *finaltail=NULL;
    if(h1->data < h2->data)
    {
        finalhead=h1;
        finaltail=h1;
        h1=h1->next;
    }
    else
    {
        finalhead=h2;
        finaltail=h2;
        h2=h2->next;
    }
    while(h1->next!=NULL || h2->next!=NULL)
    {
        Node *temp;
        if(h1->data<h2->data)
        {
            temp=h1;
            h1=h1->next;
        }
        else
        {
            temp=h2;
            h2=h2->next;
        }
        finaltail->next=temp;
        finaltail=temp;
    }
    return finalhead;
}
int main()
{
    Node *h1=input();
    print(h1);
    Node *h2=input();
    print(h2);
    Node *final=merge(h1,h2);
    print(final);
} 