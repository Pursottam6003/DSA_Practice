class Solution {
public:
    int countBinarySubstrings(string s) {
        
        int res=0;

        int ct=1,prev=0;
        for(int i=0;i<s.size()-1;i++)
        {
            if(s[i] == s[i+1]){
                ct++;
            }

            else {
                res += min(ct,prev);
                prev = ct;
                // reset
                ct =1;
            }
        }
        return res + min(prev,ct);
    }
};