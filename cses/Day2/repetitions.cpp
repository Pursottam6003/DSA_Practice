#include <bits/stdc++.h>
using namespace std;


int main()
{
    string str;
    cin>>str;


    int longest=1,curr_len=1;

    // unordered_set <char> ss = {'A','G','T','C'};
    
    for(int i=1;i<str.size();i++)
    {
        if(str[i] == str[i-1])
        {
            curr_len++;
        }
        else 
        {
            longest = max(longest, curr_len);
            curr_len=1;
        }
    }
    longest = max(longest, curr_len);

    cout<<longest<<endl;
    return 0;
}