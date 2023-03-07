/**
 * 1. a max number has the property of decreasing in every digit: 9876
 * 2. find the first non-max substring from the right; ex. in 1234(59876),
     59876 is the first non-max substring from the right
 * 3. sort the max part of 5(9876), by reverse, becames 5(6789);
 * 4. flip 5,6, becames 65789; because 6 is the next smallest digit than 5, in 56789;
 * 5. incase of 66789, you got flip 6 with 7 to make it 76689, to make it bigger.
 */
// https://leetcode.com/problems/next-greater-element-iii/submissions/910821523/
class Solution {
public:
    int nextGreaterElement(int n) {

        string s = to_string(n);
        if (s.length() == 1) {
            return -1;
        }
        /* find the first decreasing digit from the right, eg: 59876, 5 is the first decreasing digit */
        int i = s.length() - 2; // 21 -> i = 0; 59876 -> i = 3
        while(i>=0 && s[i] >= s[i+1])
        {
            i--;
        }
        
        if (i == -1) {  // if a decreasing digit cannot be find, the number cannot be larger.
            return -1;
        }

        reverse(s.begin() + i + 1, s.end());
        for(int j = i+1;j<s.size();j++)
        {
            if(s[j] > s[i])
            {
                swap(s[i],s[j]);
                break;
            }
        }
        long next = stol(s);
        return next == n || next > INT_MAX ? -1 : next;
        
    }
};