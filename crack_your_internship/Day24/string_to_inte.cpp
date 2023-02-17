// https://leetcode.com/problems/string-to-integer-atoi/solutions/1402936/java-c-simple-pictorial-explanation-32-bit-int-easy/?orderBy=most_votes
class Solution {
public:
    int myAtoi(string s) {
        
        const int len = s.size();
        
        if(len == 0){
            return 0;
        }
        
        int index = 0;
        while(index < len && s[index] == ' '){
            ++index;
        }

        if(index == len){
            return 0;
        }
        
        char ch;
        bool isNegative = (ch = s[index]) == '-';
        
        if(isNegative || ch == '+'){
            ++index;
        }
		
        const int maxLimit = INT_MAX / 10;
        int result = 0;
        while(index < len && isDigit(ch = s[index])){ 

            int digit = ch - '0';

            if(result > maxLimit || (result == maxLimit && digit > 7)){
                return isNegative ? INT_MIN : INT_MAX;
            }

            result = (result * 10) + digit;
            
            ++index;
        }
        
        return isNegative ? -result : result;
    }
    
    private:
    bool isDigit(char ch){
        return ch >= '0' && ch <= '9';
    }
};