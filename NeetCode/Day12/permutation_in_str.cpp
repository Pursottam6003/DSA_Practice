// https://leetcode.com/problems/permutation-in-string/description/

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        
        int s_len = s1.size();
        int p_len = s2.size();
        
       // if(s2.size() < s1.size()) return false;
        
        vector<int> freq_p(26,0);
        vector<int> window(26,0);
        
        if(s2.size() < s1.size()) return false;
        //first window
        for(int i=0;i<s1.size();i++){
            freq_p[s1[i]-'a']++;
            window[s2[i]-'a']++;
        }
        
        
        int itr=0;
        for(itr=0;itr<26;itr++)
        {
            if(freq_p[itr] != window[itr]) break;
        }        

        if(itr==26) return true;
        for(int i=s_len;i<s2.size();i++){
            window[s2[i-s_len ]- 'a']--;
            window[s2[i] - 'a']++;
            
            if(freq_p == window) return true;
        }
        return false;
    }
};


class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        
        int n = s1.size(),m = s2.size();
        unordered_map <char,int> mpp;

        // store all the elements of s1 into a hashmap
        for(auto it: s1)
        {
            mpp[it]++; //with its frequency
        }

        int maxiCount = mpp.size(); // calculating the size of map 

        int i=0,j=0;
        int k = s1.size(); // window size

        while(j < m)
        {
            if(mpp.find(s2[j]) != mpp.end())
            {
                // if the character is already found in the map 
                // reduce its frequncy by 1 
                mpp[s2[j]]--;
                if(mpp[s2[j]] ==0)
                {
                    maxiCount--;
                }
            }

            // if it is less then window size 

            if(j-i+1 <k)
            {
                j++;
            }

            else if(j-i+1 ==k)
            {
                // it reachs the window size 
                if(maxiCount ==0)
                {
                    return true; // anagram found // permutation found
                }

                if(mpp.find(s2[i]) != mpp.end())
                {
                    mpp[s2[i]]++;
                    if(mpp[s2[i]] ==1)
                    {
                        maxiCount++;
                    }
                }
                i++;
                j++;
            }
        }
        return false;

    }
};