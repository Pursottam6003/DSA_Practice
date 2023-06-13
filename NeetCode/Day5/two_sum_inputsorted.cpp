// https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/description/
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        
        vector <int> res(2,0);

        int i=0,j=numbers.size()-1;

        while(i < j)
        {   
            int val = numbers[i]+numbers[j];
            if(val == target)
            {
                res[0] = i+1;
                res[1] = j+1;
                break;
            }

            else if(val < target)
            {
                i++;
            }

            else 
            {
                j--;
            }
        }

        return res;
    }
};