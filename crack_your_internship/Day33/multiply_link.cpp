// https://practice.geeksforgeeks.org/problems/multiply-two-linked-lists/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article
#define mod 1000000007
void multiply(Node *head,long long int &res)
{
    while(head)
    {
        // converting into simple number 
        res = ((res*10)+ head->data)%mod;
        head=head->next;
    }
}
long long  multiplyTwoLists (Node* l1, Node* l2)
{
  //Your code here
    long long ans1=0,ans2=0;
    multiply(l1,ans1);
    multiply(l2,ans2);
    
    return (ans1*ans2)%mod;
}