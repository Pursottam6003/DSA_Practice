// https://leetcode.com/problems/excel-sheet-column-title/description/

class Solution {
public:
    string convertToTitle(int n) {
        
        string res;
        char temp;
        while(n)
        {   n--;
            temp = 'A'+ n%26;
            res.push_back(temp);

            n = n/26;
        }
        reverse(res.begin(),res.end());
        return res;
    }
};