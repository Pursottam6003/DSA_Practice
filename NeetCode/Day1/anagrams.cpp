#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        // using map approach 

        unordered_map <char,int> mpp;
        for(int i=0;i<s.size();i++)
        {   // store the result in some array
            mpp[s[i]]++;
        }

        for(int i=0;i<t.size();i++)
        {
            mpp[t[i]]--;
        }

        for(auto it:mpp)
        {
            if(it.second !=0) return false;
        }

        return true;
    }
};

class Solution2 {
public:
    bool isAnagram(string s, string t) {
        
        vector <int> mpp(26,0);
        int i=0;
        for(i=0;i<s.size();i++)
        {
            mpp[s[i]-'a']++;
        }
        i=0;
        for(i=0;i<t.size();i++)
        {
            mpp[t[i]-'a']--;
        }

        for(int i=0;i<26;i++) 
        {
            if(mpp[i] !=0) return false;
        }
        return true;
    }
};