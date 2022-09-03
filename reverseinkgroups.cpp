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
Node *reversekgroups(Node *head,int k)
{
    Node *prev=NULL;
    Node *curr=head;
    Node *next=NULL;
    if(head==NULL)
    {
        return NULL;
    }
    int cnt=0;
    while(cnt<k && curr!=NULL)
    {
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
            cnt++; 
    }
    if(next!=NULL)
    {
    head->next=reversekgroups(next,k);
}
return prev;
} 
int main()
{
    Node *head=input();
    print(head);
    Node *rev=reversekgroups(head,2);
    print(rev);
}