// https://leetcode.com/problems/crawler-log-folder/submissions/910578457/
class Solution {
public:
    int minOperations(vector<string>& logs) {


        stack <string> stk;
        for(int i=0;i<logs.size();i++)
        {
            if(logs[i] =="../")
            {
                if(!stk.empty())
                {
                    stk.pop();
                }
            }

            else if(logs[i]=="./")
            {
                continue;
            }

            else 
            {
                stk.push(logs[i]);
            }
        }

        return stk.size();
        
    }
};

/**
 * 
 * int minOperations(vector<string>& logs, int steps = 0) {
    for (auto log : logs)
        if (log == "../")
            steps = max(0, steps - 1);
        else if (log != "./")
            ++steps;
    return steps;
}
*/