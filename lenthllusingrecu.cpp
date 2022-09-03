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
int count(Node *head)
{
    Node *temp=head;
    if(temp==NULL)
    {
        return 0;
    }
    else
    {
        return 1+count(head->next);
    }
}
int main()
{
 Node *head = input();
	print(head);
   cout<<count(head);
   

}
