// efficient algo
class KthLargest
{
public:
    priority_queue<int, vector<int>, greater<int>> pq;
    int size = 0;
    KthLargest(int k, vector<int> &nums)
    {
        size = k;
        for (auto i : nums)
        {
            pq.push(i);
            if (pq.size() > k)
                pq.pop();
        }
    }

    int add(int val)
    {

        pq.push(val);

        if (pq.size() > size)
            pq.pop();
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */

// another appproach
class KthLargest
{
public:
    map<int, int, greater<int>> mpp;
    int kth = 0;
    KthLargest(int k, vector<int> &nums)
    {
        kth = k;
        for (int i = 0; i < nums.size(); i++)
        {
            mpp[nums[i]]++;
        }
    }

    int add(int val)
    {

        int temp = 0;
        // insert the new ele into the map

        mpp[val]++;
        for (auto it : mpp)
        {
            temp += it.second;
            if (temp >= kth)
            {
                return it.first;
            }
        }
        return -1;
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */