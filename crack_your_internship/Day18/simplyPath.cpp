class Solution {
public:
    string simplifyPath(string path) {
        string res;

        stack <string> stk;

        for(int i=0;i<path.size();i++)
        {
            if(path[i] =='/')
            {
                continue;
            }
            
            string temp;

            while(i< path.size() && path[i] != '/')
            {
                temp.push_back(path[i]);
                i++;
            }

            // if it is single path 
            if(temp ==".")
            {
                continue;
            }
            else if(temp =="..")
            {
                // check the stack is empty or not 
                if(!stk.empty())
                {
                    // pop the string 
                    stk.pop();
                }
            }

            // otherwise push the element into the stack 
            else 
            {
                stk.push(temp);
            }
        }

        // asigning something
        
        
        while(!stk.empty())
        {
            res = "/"+ stk.top()+ res;
            stk.pop();
        }

        if(res.empty()) res="/";
        return res;
    }
};