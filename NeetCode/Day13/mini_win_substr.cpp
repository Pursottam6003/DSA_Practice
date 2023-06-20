
// https://leetcode.com/problems/minimum-window-substring/submissions/975611108/
/**
class Solution {
public:
    string minWindow(string s, string t) {

        int s_len = s.size();
        int p_len = t.size();
        
        if(s.size() < t.size()) return "";
        
        vector<int> freq_p(26,0);
        vector<int> window(26,0);
        
        int miniLen = INT_MAX;
        //first window
        for(int i=0;i<p_len;i++){
            window[s[i]-'a']++;
            freq_p[t[i]-'a']++;
        }
        int pos=0;
        int initial=0,final=0;

        if(freq_p == window) 
        {   
            miniLen = s.size();
            initial=0;
            final = s.size();

            return s;// whole string is possible 
        }
        
        for(int i=p_len;i<s_len;i++){
            window[s[i-p_len] - 'a']--;
            window[s[i] - 'a']++;
            
            if(freq_p == window){
                miniLen = min(miniLen,i-p_len+1);

                if(miniLen > i-p_len+1)
                {
                    miniLen = i-p_len+1;
                    initial = i-p_len+1;
                    final = i;
                }
            }
        }
        return (miniLen == INT_MAX) ? "" : s.substr(initial,final);
    }
};

*/

class Solution 
{
    public:
    string minWindow(string s, string t) {

        int n = s.size();
        int m = t.size();

        unordered_map <char,int> mpp;

        // store the seccond element in map 
        for(int i=0;i<m;i++)
        {
            mpp[t[i]]++;
        }

        int maxiCount = mpp.size();

        int i=0,j=0;
        // window size initialisation 
        int k = t.size();

        int miniStart = 0;
        int miniLength = INT_MAX;


        while(j < n)
        {
            if(mpp[s[j]] >0)
            {
                k--;
            }
            mpp[s[j]]--;
            // move j to find a valid window
            j++;

            while(k==0)
            {
                if(j-i < miniLength)
                {   // update the start and end 
                    miniStart = i;
                    miniLength = j-i;
                }

                mpp[s[i]]++;

                if(mpp[s[i]] >0){
                    k++;
                }
                i++;
            }
        }

        if(miniLength != INT_MAX)
        {
            return s.substr(miniStart,miniLength);
        }
        return "";
    }
};
