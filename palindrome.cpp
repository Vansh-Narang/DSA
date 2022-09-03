/*class Solution{
  public:
    //Function to check whether the list is palindrome.
    Node *mid(Node *head)
    {
        Node *slow=head;
        Node *fast=head->next;
        while(fast!=NULL && fast->next!=NULL)
        {
            fast=fast->next->next;
            slow=slow->next;
        }
        return slow;
    }
    Node *reverse(Node *head)
    {
        Node *curr=head;
        Node *prev=NULL;
        Node *next=NULL;
        while(curr!=NULL)
        {
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return prev;
    }
    bool isPalindrome(Node *head)
    {
        if(head==NULL || head->next==NULL)
        {
            return true;
        }
        //Your code here
        //Middle
       Node *middle=mid(head); 
        
        //reverse
        Node *temp=middle->next;
        middle->next=reverse(temp);
        
        
        //compare
        Node *head1=head;
        Node *head2=middle->next;
        while(head2!=NULL)
        {
            if (head1->data!=head2->data)
            {
                return false;
            }
            head1=head1->next;
            head2=head2->next;
        }
        return true;
    }
};*/
