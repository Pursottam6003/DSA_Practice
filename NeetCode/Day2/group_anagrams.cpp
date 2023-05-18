class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        vector <vector<string>> res;
        unordered_map <string,vector<string>> mpp;

        for(string s: strs)
        {
            string val = strSort(s);
            mpp[val].push_back(s);
        }
        for(auto it: mpp)
        {
            res.push_back(it.second);
        }
        return res;
    }


    private: 

    string strSort(string &str)
    {
        vector <int> charAr(26,0);

        for(int i=0;i<str.size();i++)
        {
            charAr[str[i]-'a']++;
        }

        string resultent;

        for(int i=0;i<26;i++)
        {   // converting the response into string
            resultent += string(charAr[i],i+'a');
        }

        return resultent;
    }
};