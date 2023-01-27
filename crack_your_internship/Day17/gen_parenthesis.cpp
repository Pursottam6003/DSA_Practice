/*
class Solution {
    public List<String> generateParenthesis(int n) {
        List<String> ans = new ArrayList();
        backtrack(ans, new StringBuilder(), 0, 0, n);
        return ans;
    }

    public void backtrack(List<String> ans, StringBuilder cur, int open, int close, int max){
        if (cur.length() == max * 2) {
            ans.add(cur.toString());
            return;
        }

        if (open < max) {
            cur.append("(");
            backtrack(ans, cur, open+1, close, max);
            cur.deleteCharAt(cur.length() - 1);
        }
        if (close < open) {
            cur.append(")");
            backtrack(ans, cur, open, close+1, max);
            cur.deleteCharAt(cur.length() - 1);
        }
    }
}

*/
// https://leetcode.com/problems/generate-parentheses/description/

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        
        vector <string> res;
        string curr="";
        backtrack(res,curr,0,0,n);
        return res;
    }

    void backtrack(vector <string> &ans,string curr,int open,int close,int max)
    {
        if(curr.size() == max*2)
        {
            ans.push_back(curr);
            return;
        }

        if(open < max)
        {
            curr.push_back('(');
            backtrack(ans,curr,open+1,close,max);
            curr.pop_back();
        }

        if(close < open)
        {
            curr.push_back(')');
            backtrack(ans,curr,open,close+1,max);
            curr.pop_back();
        }
    }
};