class Solution
{
public:
    int ladderLength(string beginWord, string endWord, vector<string> &wordList)
    {

        queue<pair<string, int>> que;

        unordered_set<string> s(wordList.begin(), wordList.end());

        // i think we need to push the letter
        que.push({beginWord, 1});

        s.erase(beginWord);

        while (!que.empty())
        {
            string word = que.front().first;
            int steps = que.front().second;
            que.pop();

            if (word == endWord)
            {
                return steps;
            }

            for (int i = 0; i < word.size(); i++)
            {
                char original = word[i];

                for (char ch = 'a'; ch <= 'z'; ch++)
                {
                    word[i] = ch; // daal dalke dekh rhe h

                    if (s.find(word) != s.end())
                    {
                        s.erase(word);
                        que.push({word, steps + 1});
                    }
                }

                // again update from original
                word[i] = original;
            }
        }

        return 0;
    }
};