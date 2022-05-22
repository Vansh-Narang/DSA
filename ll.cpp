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
Node *takeinput()
{
    int data;
    cin>>data;
    Node *head=NULL;
    while(data!=-1)
    {
        Node *newNode=new Node(data);
        if(head==NULL)
        {
            head=newNode;
        }
        else
        {
            Node *temp=head;
            while(temp->next!=newNode)
            {
                temp=temp->next;
            }
            temp->next=newNode;
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
      /*   while(head!=NULL)//ek baar print kyunki head ki value null ho gyi isliye temp variable 
         //use krna hai
        {
            cout<<head->data<<endl;
            head=head->next;
        }*/
    }
 int main()
{
    Node *head = takeinput();
	print(head);

}


   /* Node n1(1);//creating object with value 1
    Node *head=&n1;//storing address of node n1 to access other elements
    Node n2(2);//creating object with value 1
    n1.next=&n2;//copy address of n2 in (one ke next me jaha pr address store hota hai)
    Node n3(3);
    Node n4(4);
    n2.next=&n3;
    n3.next=&n4;
    print(head);
   // print(head);


  //  cout<<n1.data<<" "<<n2.data<<endl;
 //   cout<<n1.next<<endl;
  //  cout<<n2.next;
}*/