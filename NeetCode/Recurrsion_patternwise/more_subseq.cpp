int func(string s, int n)
{
    // Initializing 'count' with 1.
    int count = 1;

    // Creating a hashmap of [char, int] 'mp'.
    unordered_map<char, int> m1;

    // Calculating number of distinct subsequences.
    for (int i = 0; i < n; i++)
    {
        if (m1[s[i]] == 0)
        {
            m1[s[i]] = count;
            count *= 2;
        }
        else
        {
            int temp = m1[s[i]];
            m1[s[i]] = count;
            count *= 2;
            count -= temp;
        }
    }
    return count;
}

string moreSubsequence(int n, int m, string a, string b)
{
    if (func(a, n) >= func(b, m))
    {
        return a;
    }
    else
    {
        return b;
    }
}

// set solution 

// void solve(int i,int j,int n,int m,string s1,string s2,string a,string b)
// {
//     if(i==)
// }
string moreSubsequence(int n, int m, string a, string b)
{
    // Write your code here
    unordered_set<char> s1,s2;

    for(int i=0;i<a.size();i++)
    {
        s1.insert(a[i]);
    }

    for(int j=0;j<b.size();j++)
    {
        s2.insert(b[j]);
    }

    if(s1.size() > s2.size()) return a;

    if(s1.size()== s2.size() && a.size() >= b.size()) return a;

    return b;


}