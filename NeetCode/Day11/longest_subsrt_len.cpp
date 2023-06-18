class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        vector <int> dict(128,-1);
        int maxLen = 0, start =-1;

        for(int i=0;i != s.length();i++)
        {
            if(dict[s[i]] > start)
                start = dict[s[i]];
            // update dict 
            dict[s[i]]  = i;

            maxLen = max(maxLen,i-start);
        }
        return maxLen;
    }
};


class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        int  n = s.size();
        int l=0,r= n-1;

        int maxiStr = 0;
        unordered_set <char> visited;

        for(int r=0;r<n;r++)
        {
            if(visited.find(s[r]) == visited.end())
            {
                // if the element does not found in visited set
                //insert it 
                visited.insert(s[r]);
                // update the max str 
                maxiStr = max(maxiStr,r-l+1);
            }

            else 
            {
                while(l != r && s[l] != s[r])
                {
                    visited.erase(s[l++]);
                    // removing the duplicastes
                }

                // removing and adding a sama element 
                visited.erase(s[l++]);
                visited.insert(s[r]);

                maxiStr = max(maxiStr,r-l+1);
            }
        }

        return maxiStr;
    }
};