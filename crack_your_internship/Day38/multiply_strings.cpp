//https://leetcode.com/problems/multiply-strings/submissions/908157331/
class Solution {
public:
    string multiply(string num1, string num2) {
        
        int n  = num1.size(), m  = num2.size();


        string res;    

        vector <int> pos(m+n,0);
        int cr=0; 
        for(int i=n-1;i>=0;i--)
        {
            for(int j = m-1;j>=0;j--)
            {
                int p1 = i+j;
                int p2 = i+j+1;
    
                int mul = (num1[i]-'0') * (num2[j]-'0');
                
                int sum = pos[p2]+mul;
                pos[p1] += sum /10;
                pos[p2] = sum%10;
            }
        }

        for(int i=0;i<pos.size();i++)
        {   if(i==0 && pos[i]==0) continue;
            else res.push_back(pos[i] +'0');
        }

        if(num1=="0" || num2=="0") return "0";
        return res;
        
    }
};