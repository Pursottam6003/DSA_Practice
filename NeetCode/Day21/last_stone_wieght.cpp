// https://leetcode.com/problems/last-stone-weight/description/
class Solution
{
public:
    int lastStoneWeight(vector<int> &stones)
    {

        // create a pq
        priority_queue<int, vector<int>> pq;

        for (int i = 0; i < stones.size(); i++)
        {
            // lets push all the elements int priority queue
            pq.push(stones[i]);
        }

        while (pq.size() > 1)
        {
            int x = pq.top();
            pq.pop();
            int y = pq.top();
            pq.pop();

            if (x > y)
                pq.push(x - y);
        }

        return pq.empty() ? 0 : pq.top();
    }
};