// https://leetcode.com/problems/group-anagrams/submissions/897139952/

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) 
    {
        unordered_map <string ,vector <string>> mpp;
        for(string s: strs)
        {
            string t = s; // copying the string 
            sort(t.begin(),t.end());
            mpp[t].push_back(s);
        }

        vector <vector <string>> results;
        for(auto p: mpp)
        {
            results.push_back(p.second);
        }

        return results;
    }
};


/// Optimal 

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) 
    {
        unordered_map <string ,vector <string>> mpp;
        for(string s: strs)
        {
            string t = strSort(s); // sorted string will be
            // retured into t 
            mpp[t].push_back(s);
        }

        vector <vector <string>> results;
        for(auto p: mpp)
        {
            results.push_back(p.second);
        }

        return results;
    }
private: 
    string strSort(string s)
    {
        int ct[26] ={0};

        for(char c: s)
        {
            ct[c-'a']++;
        }

        // creating a temp string which will be retured
        string temp;
        for(int c=0;c<26;c++)
        {
            temp += string(ct[c],c+'a');
        }

        return temp;
    }


};