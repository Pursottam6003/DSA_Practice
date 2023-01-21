// https://www.geeksforgeeks.org/print-all-the-duplicates-in-the-input-string/

#include <bits/stdc++.h>
using namespace std;

class Solution 
{
    public:
    void PrintAllDuplicates(string str)
    {   
        unordered_map <char,int> mpp;
        for(int i=0;i<str.size();i++)
        {
            mpp[str[i]]++;
        }

        // and by the help of map 
        for(auto it:mpp)
        {
            if(it.second ==2) cout<< it.first<<endl;
        }
    }
};