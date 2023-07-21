// class Solution
// {
// public:
//     bool solve(int ind, int size, string s, string ds, vector<string> &dict, unordered_map<string, int> &mpp)
//     {
//         if (size == s.size())
//         {
//             return true;
//         }

//         if (ind > s.size())
//         {
//             return false;
//         }
//         if (mpp[ds]>0)
//         {
//             size += ds.size();
//             ds.clear();
//         }

//         ds.push_back(s[ind]);
//         return solve(ind + 1, size, s, ds, dict, mpp);
//     }
//     bool wordBreak(string s, vector<string> &wordDict)
//     {

//         unordered_map<string, int> mpp;
//         for (int i = 0; i < wordDict.size(); i++)
//         {
//             mpp[wordDict[i]]++;
//         }
//         string ds;

//         bool result = true;

//         return solve(0, 0, s, ds, wordDict, mpp);
//     }
// };

class Solution
{
private:
    bool wordBreak(string s, unordered_set<string> &set, vector<int> &memo, int start)
    {
        if (start == s.size())
        {
            return true;
        }
        if (memo[start] != -1)
        {
            return memo[start];
        }

        for (int i = start; i < s.size(); i++)
        {
            if (set.count(s.substr(start, i + 1 - start)) && wordBreak(s, set, memo, i + 1))
            {
                memo[start] = true;
                return true;
            }
        }

        return memo[start] = false;
    }

public:
    bool wordBreak(string s, vector<string> &wordDict)
    {
        vector<int> memo(s.size(), -1);

        unordered_set<string> set(wordDict.begin(), wordDict.end());
        return wordBreak(s, set, memo, 0);
    }
};

/*
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool solve(int ind, int size, string s, string ds, vector<string> &dict, unordered_map<string, int> &mpp)
    {
        if (size == s.size())
        {
            return true;
        }

        if (ind > s.size())
        {
            return false;
        }
        if (mpp.find(ds) != mpp.end())
        {
            size += ds.size();
            ds.clear();
        }

        ds.push_back(s[ind]);
        return solve(ind + 1, size, s, ds, dict, mpp);
    }
    bool wordBreak(string s, vector<string> &wordDict)
    {

        unordered_map<string, int> mpp;
        for (int i = 0; i < wordDict.size(); i++)
        {
            mpp[wordDict[i]]++;
        }
        string ds;

        bool result = true;

        return solve(0, 0, s, ds, wordDict, mpp);
    }
};

int main()
{
    string s = "aaaaaaa";
    vector<string> word = {"aaaa", "aaa"}

    ;

    class Solution sol;

    cout << sol.wordBreak(s, word) << endl;
}
*/