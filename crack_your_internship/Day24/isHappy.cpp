// https://leetcode.com/problems/happy-number/description/

class Solution {
public:
    bool isHappy(int n) {
        
        unordered_set <int> myset;
        int val=0,t=0;

        while(true)
        {   val=0;
            while(n)
            {
                t = n%10;
                val+= t*t;
                n = n/10;
            }
            if(val ==1) return true;
            else if(myset.count(val))
            {
                return false;
            }
            else myset.insert(val);
            n=val;
        }

        return false;
    }
};