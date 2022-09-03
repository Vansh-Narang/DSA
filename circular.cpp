/*************************************************/
     //   Following is the structure of class Node:
    #include<iostream>
    using namespace std;

        class Node{
        public:
            int data;
            Node* next;
            
            Node(int data){
                this->data = data;
                this->next = NULL;
            }
            
        };
/**************************************************/
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
bool isCircular(Node* head){
    // Write your code here.
    Node *temp=head->next;
    while(temp!=NULL && temp!=head)
    {
        temp=temp->next;
    }
    if (temp==head)
    {
        return true;
    }
    return false;
}
int main()
{
Node *head=input();
print(head);
bool a=isCircular(head);
cout<<a<<endl;
}
