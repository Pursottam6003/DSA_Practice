// https://leetcode.com/problems/minimum-cost-tree-from-leaf-values/submissions/911308315/
class Solution {
public:
    int mctFromLeafValues(vector<int>& arr) {
        
        int res=0;

        vector <int> stk ={INT_MAX};
        for(int a : arr)
        {
            while(stk.back() <= a)
            {
                int mid = stk.back();
                stk.pop_back();
                res += mid * min(stk.back(),a);
            }
            stk.push_back(a);
        }


        for(int i=2;i<stk.size();i++)
        {
            res += stk[i] * stk[i-1];
        }

        return res;
    }
};