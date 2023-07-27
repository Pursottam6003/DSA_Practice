// upar se gya code
class Solution
{
public:
    int findKthLargest(vector<int> &nums, int k)
    {
        buildMaxHeap(nums);
        for (int i = 0; i < k - 1; i++)
        {
            swap(nums[0], nums[--heapSize]);
            maxHeapify(nums, 0);
        }
        return nums[0];
    }

private:
    int heapSize;

    int left(int i)
    {
        return (i << 1) + 1;
    }

    int right(int i)
    {
        return (i << 1) + 2;
    }

    void maxHeapify(vector<int> &nums, int i)
    {
        int largest = i, l = left(i), r = right(i);
        if (l < heapSize && nums[l] > nums[largest])
        {
            largest = l;
        }
        if (r < heapSize && nums[r] > nums[largest])
        {
            largest = r;
        }
        if (largest != i)
        {
            swap(nums[i], nums[largest]);
            maxHeapify(nums, largest);
        }
    }

    void buildMaxHeap(vector<int> &nums)
    {
        heapSize = nums.size();
        for (int i = (heapSize >> 1) - 1; i >= 0; i--)
        {
            maxHeapify(nums, i);
        }
    }
};

// efficient solution
class Solution
{
public:
    int findKthLargest(vector<int> &nums, int k)
    {

        int left = 0, right = nums.size() - 1, kth = 0;

        while (true)
        {
            int idx = partition(nums, left, right);

            if (idx == k - 1)
            {
                kth = nums[idx];
                break;
            }
            if (idx < k - 1)
            {
                left = idx + 1;
            }

            else
            {
                right = idx - 1;
            }
        }
        return kth;
    }

private:
    int partition(vector<int> &nums, int left, int right)
    {
        int pivot = nums[left], l = left + 1, r = right;

        while (l <= r)
        {
            if (nums[l] < pivot && nums[r] > pivot)
            {
                swap(nums[l++], nums[r--]);
            }

            if (nums[l] >= pivot)
            {
                l++;
            }

            if (nums[r] <= pivot)
            {
                r--;
            }
        }
        // swap prev left,with curr right
        swap(nums[left], nums[r]);
        return r;
    }
};

class Solution
{
public:
    int findKthLargest(vector<int> &nums, int k)
    {

        priority_queue<int, vector<int>, greater<int>> pq;

        for (int i = 0; i < nums.size(); i++)
        {
            pq.push(nums[i]);

            if (pq.size() > k)
            {
                pq.pop();
            }
        }

        // for(int i=0;i<)
        return pq.top();
    }
};