
// https://leetcode.com/problems/letter-combinations-of-a-phone-number/description/
class Solution {
public:

    void letterCombinations(int ind,string digits,string ds,vector<string> &dailer,vector <string> &res)
    {
        if(ind == digits.size())
        {
            res.push_back(ds);
            return;
        }

        string value = dailer[digits[ind]-'0'];

        for(int i=0;i<value.size();i++)
        {
            ds.push_back(value[i]);
            letterCombinations(ind+1,digits,ds,dailer,res);
            ds.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        vector <string> res;

        if(digits.empty())
        {
            return {};
        }

        vector <string> dailer={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};

        string temp;

        letterCombinations(0,digits,temp,dailer,res);
        return res;
    }
};