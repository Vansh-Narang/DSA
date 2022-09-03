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
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
Node *solve(Node *first,Node *second)
{
    Node *curr1=first;
    Node *next1=curr1->next;
    Node *curr2=second;
    Node *next2=curr2->next;
    while(next1!=NULL && curr2!=NULL)
    {
        if((curr2->data >=curr1->data) && (curr2->data<=next1->data))
        {
            curr2->next=next1;
            curr1->next=curr2;
            next2=curr2->next;

            curr1=curr2;
            curr2=next2;
        }
        else
        {
            curr1=curr1->next;
            next1=next1->next;
            if(next1==NULL)
            {
                curr1->next=curr2;
                return first;
            }
        }
        return first;
    }
   // return first;
}
Node *merge(Node *first,Node *second)
{
    if(first==NULL)
    {
        return second;
    }
    if(second==NULL)
    {
        return first;
    }
    if(first->data<=second->data)
    {
        return solve(first,second);
    }
    else
    {
        return solve(second,first);
    }
}
int main()
{
    Node *head=input();
    print(head);
    Node *head1=input();
    print(head1);
    Node *header3=merge(head,head1);
    print(header3);
}

