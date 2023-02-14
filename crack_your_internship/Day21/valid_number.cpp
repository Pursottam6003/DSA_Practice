// https://leetcode.com/problems/valid-number/solutions/23738/clear-java-solution-with-ifs/?orderBy=most_votes
class Solution {
public:
    bool isNumber(string s) {
        bool dot = false, e = false, numBeforeE = false, numAfterE = false;
        s = trim(s);
        for(int i = 0; i < s.size(); i++) {
            char c = s[i];
            if(c >= '0' && c <= '9') {
                if(!e) numBeforeE = true;
                else numAfterE = true;
            } else if(c == '-' || c == '+') {
                if(i != 0 && s[i-1] != 'e') return false;
            } else if(c == '.') {
                if(e || dot) return false;
                dot = true;
            } else if(c == 'e') {
                if(e) return false;
                e = true;
            } else {
                return false;
            }
        }
        return e ? (numBeforeE && numAfterE) : numBeforeE;
    }
    
private:
    string trim(string s) {
        int begin = s.find_first_not_of(' '), end = s.find_last_not_of(' ');
        if(begin == -1) return "";
        return s.substr(begin, end-begin+1);
    }
};