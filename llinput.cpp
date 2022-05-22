#include<iostream>
using namespace std;
class Node
{
    public:
    int data;
    Node *next;//storing a address
    Node(int data)//creating a parameterised constructor
    {
        this->data=data;//storing data
        next=NULL;//next element me null
    }
};
Node *input()
{
    cout<<"ENTER The data for the list";
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
            cout<<head->data<<endl;
            head=head->next;
        }
    }
int main()
{
    Node *head = input();
	print(head);
}