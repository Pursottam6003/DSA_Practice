// https://leetcode.com/problems/long-pressed-name/description/
class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        int itr=0;
        for(int j=0;j<typed.size();j++)
        {
            if(itr < name.size() && name[itr] == typed[j])
            {
                itr++;
            }
            else if(!j || (typed[j] != typed[j-1])) return false;
        }
        return itr==name.size();
    }
};