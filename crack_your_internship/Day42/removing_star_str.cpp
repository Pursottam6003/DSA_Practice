//https://leetcode.com/problems/removing-stars-from-a-string/description/
class Solution {
public:
    string removeStars(string s) {

        string res;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='*')
            {
                if(res.size() !=0)
                {
                    res.pop_back();
                }
            }
            else 
            {
                res.push_back(s[i]);
            }
        }   
        return res;
    }
};