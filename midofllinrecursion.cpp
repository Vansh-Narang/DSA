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
/*int mid(Node *head)
{
    if(head==NULL || head->next==NULL)
    {
        return head->data;
    }
    Node *slow=head;
    Node *fast=head->next;
    while(fast!=NULL)
    {
        fast=fast->next;
        if(fast!=NULL)
        {
            fast=fast->next;
        }
        slow=slow->next;
    }
    return slow->data;
}*/
int mid(Node *head)
{
    if(head==NULL || head->next==NULL)
    {
        return head->data;
    }
    Node *fast=head->next;
    Node *slow=head;
    while(fast!=NULL)
    {
        if(fast!=NULL)
        {
        fast=fast->next->next;
        }
        slow=slow->next;
    }
    return slow->data;
}
int main()
{
    Node *head=input();
    print(head);
    cout<<mid(head);

}
