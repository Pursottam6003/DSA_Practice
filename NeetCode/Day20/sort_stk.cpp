// 
// https://practice.geeksforgeeks.org/problems/sort-a-stack/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=sort-a-stack
void insert_stk(stack <int> &stk,int temp)
{
    if(stk.empty() || stk.top() <= temp)
    {
        stk.push(temp);
        return;
    }
    
    int val = stk.top();
    stk.pop();
    insert_stk(stk,temp);
    stk.push(val);
}
void SortedStack :: sort()
{
   //Your code here
   if(s.empty()) return;
   
   int temp = s.top();
    s.pop();
    sort();
   insert_stk(s,temp);
   return;
       
}