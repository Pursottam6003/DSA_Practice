// https://leetcode.com/problems/excel-sheet-column-number/description/
class Solution {
public:
    int titleToNumber(string columnTitle) {
        int res=0,t=0;
        for(int i=0;i<columnTitle.size();i++)
        {
            t = (columnTitle[i]-'A')+1;
            res = res*26+t;
       }
        return res;
    }
};