class Solution 
{
public:
    bool validPalindrome(string str)
    {
        for(int i=0,j=str.size()-1;i<j;i++,j--)
        {   // check its adjacent are pallindrome or not 
            if(str[i] != str[j]) return finalchecking(str,i+1,j) || finalchecking(str,i,j-1);
        }

        return true;

         
    }

    bool finalchecking(string s,int l,int r)
    {
        for(int i=l,j=r;i<r;i++,r--)
        {
            if(s[i] != s[r]) return false;
        }
        return true;
    }
};