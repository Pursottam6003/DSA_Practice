#include <bits/stdc++.h>
using namespace std;

int main()
{
    string str;
    cin>>str; 

    int flag=0;
    string res="";
	for(int i=0;i<str.size();i++)
	{
        if(str[i]=='W'&& str[i+1]=='U' && str[i+2]=='B')
        {
            if(flag==0)
                res +=" ";
            i+=2;
            flag=1;
            
        }
        else
        {
            flag=0;
            res +=str[i];
        }
    }
    cout<<res<<endl;
}