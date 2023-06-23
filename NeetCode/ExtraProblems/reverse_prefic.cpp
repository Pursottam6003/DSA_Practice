class Solution {
public:
    string reversePrefix(string word, char ch) {
        int pos=0;

        for(int i=0;i<word.size();i++)
        {
            if(word[i]==ch) 
            {
                pos=i+1;
                break;
            }
        }

        for(int i=0;i<pos/2;i++)
        {
            char ch = word[i];
            word[i] = word[pos-i-1];
            word[pos-i-1] = ch;
        }
        return word;
    }
};