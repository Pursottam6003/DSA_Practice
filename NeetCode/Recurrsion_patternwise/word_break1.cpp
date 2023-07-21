// https://www.codingninjas.com/studio/problems/word-break-1_758963?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTab=1
void solve(int ind, int n, string &str, set<string> &set, string &curr, vector<string> &res)
{
    if (ind == str.size())
    {
        curr.pop_back();
        res.push_back(curr);
        return;
    }
    string temp = "";
    for (int i = ind; i < n; i++)
    {
        temp += str[i];

        if (set.find(temp) != set.end())
        {
            string temp2 = curr + temp + " ";
            solve(i + 1, n, str, set, temp2, res);
        }
    }
}
vector<string> getAllValidSentences(string &s, vector<string> &dict)
{
    //  write your code here.
    set<string> set(dict.begin(), dict.end());
    vector<string> res;
    string temp = "";
    int n = s.size();
    solve(0, n, s, set, temp, res);
    return res;
}