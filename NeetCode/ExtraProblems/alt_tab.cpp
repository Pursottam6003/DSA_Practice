#include <bits/stdc++.h>
using namespace std;

typedef long long int lli;

int main()
{
    lli n;
    cin>>n;

    unordered_map <string,int> mpp;
    deque<string> dq;


    for(int i=0;i<n;i++)
    {   
        string str;
        cin>> str;
        
        if(mpp.find(str) != mpp.end())
        {
            // if found 
            if(dq.empty())
            {
                dq.push_front(str);
            }

            else 
            {
                dq.remove(str);
                dq.push_front(str);
            }
        }

        else 
        {   
            // insert into the map 
            mpp[str]++;
            dq.push_front(str);
        }
    }

    for(auto it: dq)
    {
        cout<<it<<" ";
    }

    
    
}