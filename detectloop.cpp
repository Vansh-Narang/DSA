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
Node *detectloop(Node *head)
{
    Node *slow=head;
    Node *fast=head;
    if(head ==NULL && head->next==NULL)
    {
        return NULL;
    }
    while(fast!=NULL && slow!=NULL)
    {
        fast=fast->next;
        if(fast->next !=NULL)
        {
            fast=fast->next;
        }
        slow=slow->next;
        if (fast==slow)
        {
            return slow;
        }
    }
    return NULL;
}
Node *startnodeloop(Node *head)
{
    Node *intersection=detectloop(head);
    Node *slow=head;
    while(slow!=intersection)
    {
        slow=slow->next;
        intersection=intersection->next;
    }
    return slow;
}
void removeloop(Node *head)
{
    if(head==NULL)
    {
        return ;
    }
    Node *startloop=startnodeloop(head);
    Node *temp=startloop;
    while(temp->next!=startloop)
    {
        temp=temp->next;
    }
    temp->next=NULL;
}
/*
Node *detectloop(Node *head)
{
    Node *slow=head;
    Node *fast=head;
    if(head ==NULL)
    {
        return NULL;
    }
    while(fast!=NULL && slow!=NULL)
    {
        fast=fast->next;
        if(fast!=NULL)
        {
            fast=fast->next;
        }
        slow=slow->next;
        if (fast==slow)
        {
            return slow;
        }
    }
    return NULL;
}
Node *startnodeloop(Node *head)
{
    Node *intersection=detectloop(head);
    if (intersection==NULL)
    {
        return NULL;
}
    Node *slow=head;
    while(slow!=intersection)
    {
        slow=slow->next;
        intersection=intersection->next;
    }
    return slow;
}
Node *removeLoop(Node *head)
{
    // Write your code here.
      if(head==NULL)
    {
        return NULL;
    }
    Node *startloop=startnodeloop(head);
    if (startloop==NULL)
    {
        return head;
}
    Node *temp=startloop;
    while(temp->next!=startloop)
    {
        temp=temp->next;
    }
    temp->next=NULL;
    return head;
}*/
int main()
{
    Node *head=input();
    print(head);
}