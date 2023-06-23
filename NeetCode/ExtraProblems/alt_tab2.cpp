#include <bits/stdc++.h>
using namespace std;

typedef long long int lli;

int main()
{
    lli n;
    cin>>n;

    unordered_map <string,int> mpp;
    stack <string> stk;


    for(int i=0;i<n;i++)
    {   
        string str;
        cin>> str;
        
        if(mpp.find(str) != mpp.end())
        {
            // if found 
            stk.push(str);
        }

        else 
        {   
            // insert into the map 
            mpp[str]=1;
            stk.push(str);
        }
    }

    cout<<"Output string"<<endl;

    string res;
    while(!stk.empty())
    {   
        string s = stk.top();
        int n = s.size();

        if(mpp[s]>0)
        {   // remove the element 
            res.push_back(s[n-2]);
            res.push_back(s[n-1]);

            // remove from the list 
            mpp[s]=0;
        }
        // NEALMPUSOXIT
        stk.pop();
    }

    cout<<res<<endl;
}

/**
WINE
TERMINAL
GIMP
WINE
NAUTILUS
FIREFOX
GEDIT
FIREFOX
NAUTILUS
*/