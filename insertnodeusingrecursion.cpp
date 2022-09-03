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
    public:
  /*  ~Node()
    {
        int value=this->data;
        if(this->next!=NULL)
        {
            delete next;
            this->next=NULL;
        }
    }*/
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
/*Node *insertatnode(Node *head,int k,int data)
{
    if(head==NULL)
    {
        return head;
    }
    if(k==1)
    {
        Node *newNode=new Node(data);
        newNode->next=head;
        head=newNode;
        return head;
    }
    else
    {
        head->next=insertatnode(head->next,k-1,99);
        return head;
    }
}*/
Node *deletenode(Node *head,int k)
{
    if(head==NULL)
    {
        return head;
    }
    if(k==1)
    {
        int cnt=1;
        Node *curr=head;
        Node *previous=NULL;
        while(cnt<=k)
        {
            previous=curr;
            curr=curr->next;
            cnt++;
        }
        previous->next=curr->next;
        curr->next=NULL;
        delete curr;
        return previous;
    }
    else
    {
        head->next=deletenode(head->next,k-1);
        return head;
    }
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
int main()
{
    Node *head = input();
	print(head);
    //insertatnode(head,3,99);
   // print(head);
    deletenode(head,3);
    print(head);

}