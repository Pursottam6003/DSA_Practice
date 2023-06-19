// https://leetcode.com/problems/longest-repeating-character-replacement/description/
/*
class Solution {
public:
    int characterReplacement(string s, int k) {
        
        int res=-1;
        int l=0,r=0;
        int maxi = 0;
        unordered_map<char,int> mpp;

        while(r < s.size())
        {
            // insert into the map
            mpp[s[r]]++;
            // check the maxi element 
            maxi = max(maxi,mpp[s[r]]);

            if((r-l+1) - maxi > k)
            {
                // if it exceeds the maxi element 
                mpp[s[l]]--;
                // increment left 
                l++;
            }
            res = max(res,(r-l+1));
            r++;
        }
        return res;
    }
};
*/














class Solution 
{
    public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int i=0,j=0,maxi=0;
        int res=-1;

        // create a map which stores the frequency of elements 
        unordered_map <char,int> mpp;

        // check r < n codition of loop
        while(j < n)
        {   
            // store into the map
            mpp[s[j]]++;

            // check is it the same window size have the maximum frequency
            maxi = max(maxi,mpp[s[j]]);

            // check the window size 
            if((j-i+1)-maxi > k)
            {
                // decrement the window size of last element from left
                mpp[s[i]]--;
                i++;
            }
            // update the result 
            res = max(res,(j-i+1));
            //increment j
            j++;

        }
        return res;
    }


};   