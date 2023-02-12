/*
class Solution {
public:
    int calculate(string s) {

        stack <int> stk;
        int currentNum=0,len = s.size();

        if(len ==0) return 0;
        char operation='+';
        for(int i=0;i<s.size();i++)
        {
            char currentChar = s[i];

            if(isdigit(currentChar)){
                currentNum = (currentNum *10) + (currentChar -'0');
            }
            if(! isdigit(currentChar) && !iswspace(currentChar) || i == len-1)
            {
                if(operation =='-')
                {
                    stk.push(-currentNum);
                }

                else if(operation =='+')
                {
                    stk.push(currentNum);
                }
                else if(operation =='*')
                {
                    int stkTop= stk.top();
                    stk.pop();
                    stk.push(stkTop * currentNum);
                }

                else if(operation =='/')
                {
                    int stkTop = stk.top();
                    stk.pop();
                    stk.push(stkTop /currentNum);
                }

                operation = currentChar;
                currentNum=0;
            }

        }

        int res =0;
        while(!stk.empty())
        {
            res += stk.top();
            stk.pop();
        }
        return res;
    }
};

*/

class Solution {
public:
    int calculate(string s) {
        int length = s.length();
        if (length == 0) return 0;
        int currentNumber = 0, lastNumber = 0, result = 0;
        char sign = '+';
        for (int i = 0; i < length; i++) {
            char currentChar = s[i];
            if (isdigit(currentChar)) {
                currentNumber = (currentNumber * 10) + (currentChar - '0');
            }
            if (!isdigit(currentChar) && !iswspace(currentChar) || i == length - 1) {
                if (sign == '+' || sign == '-') {
                    result += lastNumber;
                    lastNumber = (sign == '+') ? currentNumber : -currentNumber;
                } else if (sign == '*') {
                    lastNumber = lastNumber * currentNumber;
                } else if (sign == '/') {
                    lastNumber = lastNumber / currentNumber;
                }
                
                sign = currentChar;
                currentNumber = 0;
            }
        }
        result += lastNumber;
        
        return result;  
    }
};