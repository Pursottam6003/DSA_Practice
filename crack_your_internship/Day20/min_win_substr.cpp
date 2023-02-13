// https://leetcode.com/problems/minimum-window-substring/solutions/26808/here-is-a-10-line-template-that-can-solve-most-substring-problems/?orderBy=most_votes

class Solution {
public:
    string minWindow(string s, string t) {
        
        // map for storing the characters assigned 128 to store it as asci characters
        // s contains all strings 
        // t contains desired strings

        vector <int> map(128,0); 
        for(auto c: t) 
        {
            map[c]++;
        }
        // counter for max size of string len 
        // begin and end are two pointer 
        // d is distance covered ie max distance will be min at the end 
        // head is the pointer from which it will start once again


        int counter = t.size(), begin = 0,end =0, d=INT_MAX,head =0;

        while(end < s.size())
        {
            if(map[s[end++]]-- >0 ) counter--; 

            while(counter ==0 )// valid
            {   // update d 
                if(end-begin < d) d = end - (head=begin);
                if(map[s[begin++]]++ ==0 )
                {
                    counter++; // make it invalid
                }
            }
        }

        return d==INT_MAX ? "" : s.substr(head,d);

    }
};