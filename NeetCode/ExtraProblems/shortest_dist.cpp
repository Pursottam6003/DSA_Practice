// https://leetcode.com/problems/shortest-distance-to-a-character/description/
class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        int n = s.size();

        vector <int> left(n,0),right(n,0);

        int found=INT_MAX;
        for(int i=n-1;i>=0;i--)
        {   
            
            if(s[i] == c) 
            {
                left[i] = 0;
                found=0;
            }

            else 
            {
                if(found <INT_MAX)
                {   found++;
                    left[i] = found;
                }
                else 
                {
                    left[i]  = found;
                }
            }
        }
        found=INT_MAX;
        for(int i=0;i<n;i++)
        {
            if(s[i] == c)
            {
                right[i] =0;
                found=0;
            }

            else 
            {    
                if(found <INT_MAX)
                {   found++;
                    right[i] = found;
                }
                else 
                {
                    right[i]  = found;
                }
                
            }
        }

        vector <int> res(n,0);

        for(int i=0;i<n;i++)
        {
            res[i] = min(left[i],right[i]);
        }

        return res;

    }
};


class Solution {
public:
    vector<int> shortestToChar(string s, char c) {

        int n = s.size(),pos = -n;

        vector <int> res(n,n);

        for(int i=0;i<n;i++)
        {
            if(s[i] == c) pos = i;
            res[i] = i-pos;
        }

        for(int i=pos-1;i>=0;i--)
        {
            if(s[i] == c) pos=i;
            res[i] = min(res[i],pos-i);
        }
        return res;
    }
};