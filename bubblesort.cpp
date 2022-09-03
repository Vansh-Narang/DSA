#include<iostream>
using namespace std;
class Node
{
    public:
    int data;
    Node *next=NULL;
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
Node *bubblesort(Node *head)
{
    Node*temp=head;
    Node *curr=head;
    Node *prev=NULL;
    Node *next=head->next;
    while(temp!=NULL && temp->next!=NULL)
    {
        if(curr->data < next->data)
        {
        swap(curr->data,next->data);
      //  Node *t1=next->next;
     //   next->next=curr->next;
      //  prev->next=curr->next;
    //    curr->next=temp;
        temp=temp->next;
        }
        else
        {
            prev=curr;
            curr=next;
            next=next->next;
            temp=temp->next;
            return prev;
        }
    }
    return prev;
}
int main()
{
    Node *head=input();
    print(head);
    Node *head1=bubblesort(head);
    print(head1);
}