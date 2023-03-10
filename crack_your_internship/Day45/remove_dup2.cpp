// 

// approach 1 
class Solution {
public:
    
    string removeDuplicates(string s, int k) {
        int i = 0, n = s.length();
        vector<int> count(n);
        for (int j = 0; j < n; ++j, ++i) {
            s[i] = s[j];
            count[i] = i > 0 && s[i - 1] == s[j] ? count[i - 1] + 1 : 1;
            if (count[i] == k) i -= k;
        }
        return s.substr(0, i);
    }
};

class Solution 
{
    public:
    string removeDuplicates(string s,int k)
    {
        int n= s.size();
        stack <pair<char,int>> stk;
        for(int i=0;i<n;i++)
        {
            if(stk.empty() || stk.top().first != s[i])
            {
                stk.push({s[i],1});
            }

            else 
            {
                auto prev = stk.top();
                stk.pop();
                stk.push({prev.first,prev.second+1});
            }

            if(stk.top().second == k) stk.pop();
        }
 
        string ans = "";
        while(!stk.empty()){
            auto cur = stk.top();
            stk.pop();
            while(cur.second--){
                ans.push_back(cur.first);
            }
        }
        reverse(ans.begin(), ans.end());

        return ans;
    }
};