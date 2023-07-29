// better solution
class Solution
{
public:
    int leastInterval(vector<char> &tasks, int n)
    {

        unordered_map<int, int> mpp;
        int ct = 0;
        for (int i = 0; i < tasks.size(); i++)
        {
            // increament the map value
            mpp[tasks[i]]++;
            // will get the maximum value of freq
            ct = max(ct, mpp[tasks[i]]);
        }
        // max possible res
        int ans = (ct - 1) * (n + 1);

        for (auto e : mpp)
        {
            if (e.second == ct)
            {
                ans++;
            }
        }

        return max((int)tasks.size(), ans);
    }
};

class Solution
{
public:
    int leastInterval(vector<char> &tasks, int n)
    {

        int counter[26] = {0};

        for (char task : tasks)
        {
            counter[task - 'A']++;
        }

        priority_queue<int> pq;
        for (int i = 0; i < 26; i++)
        {
            if (counter[i])
            {
                pq.push(counter[i]);
            }
        }

        int time = 0;

        while (!pq.empty())
        {
            vector<int> remaining;
            int all = n + 1;

            while (all && !pq.empty())
            {
                int counts = pq.top();
                pq.pop();

                if (--counts)
                {
                    remaining.push_back(counts);
                }
                time++;
                all--;
            }
            for (int count : remaining)
            {
                pq.push(count);
            }
            if (pq.empty())
            {
                break;
            }
            time += all;
        }
        return time;
    }
};