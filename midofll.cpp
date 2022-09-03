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
int mid(Node *head)
{
    int len=6;//working for both even and odd but change the length 
    int ans=len/2;
    int cnt=0;
    while(cnt<ans)
    {
        head=head->next;
        cnt++;
    }
    return head->data;
}
int main()
{
    Node *head=input();
    print(head);
    cout<<mid(head);

}
