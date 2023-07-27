
// using quicksort sol effiecient
class Solution
{

    static inline int getsum(const vector<int> &v) { return v[0] * v[0] + v[1] * v[1]; }

    static inline bool comp(const vector<int> &l, const vector<int> &r)
    {
        return getsum(l) <= getsum(r);
    }

public:
    // standard quicksort algo

    int partition(vector<vector<int>> &arr, int left, int right)
    {
        vector<int> pivot = arr[right];

        int partitionIndex = left;
        for (int i = left; i < right; i++)
        {
            if (comp(arr[i], pivot))
            {
                swap(arr[i], arr[partitionIndex]);
                partitionIndex++;
            }
        }

        swap(arr[partitionIndex], arr[right]);
        return partitionIndex;
    }

    void quickselect(vector<vector<int>> &res, int l, int r, int k)
    {
        while (l <= r)
        {
            int mid = partition(res, l, r);
            if (mid == k)
                return;
            if (mid < k)
                l = mid + 1;
            else
                r = mid - 1;
        }
    }
    vector<vector<int>> kClosest(vector<vector<int>> &points, int k)
    {
        quickselect(points, 0, points.size() - 1, k);

        return vector<vector<int>>(points.begin(), points.begin() + k);
    }
};

class Solution
{
public:
    vector<vector<int>> kClosest(vector<vector<int>> &points, int k)
    {

        vector<vector<int>> res;
        // first store the values into a orderred map
        priority_queue<vector<int>> pq;
        for (int i = 0; i < points.size(); i++)
        {
            int x = points[i][0];
            int y = points[i][1];

            int sqroot = x * x + y * y;

            pq.push({sqroot, x, y});

            if (pq.size() > k)
            {
                pq.pop();
            }
        }

        for (int i = 0; i < k; i++)
        {
            vector<int> topAr = pq.top();
            pq.pop();

            res.push_back({topAr[1], topAr[2]});
        }
        return res;
    }
};