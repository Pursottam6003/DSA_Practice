#include <bits/stdc++.h>
int wordLadder(string begin, string end, vector<string> &dict)
{
    // Write your code here
    queue<pair<string, int>> que;

    unordered_set<string> s(dict.begin(), dict.end());

    // insert into the queue
    que.push({begin, 1});
    s.erase(begin);

    while (!que.empty())
    {
        string word = que.front().first;
        int steps = que.front().second;

        que.pop();
        if (word == end)
            return steps;

        for (int i = 0; i < word.size(); i++)
        {

            char original = word[i];

            // now check for all alternatives
            for (char ch = 'a'; ch <= 'z'; ch++)
            {
                word[i] = ch;

                if (s.find(word) != s.end())
                {
                    que.push({word, steps + 1});
                    s.erase(word);
                }
            }

            word[i] = original;
        }
    }

    return -1;
}