// 1482. Minimum Number of Days to Make m Bouquets
class Solution {
public:
typedef long long int lli;

    int minDays(vector<int>& A, int m, int k) {
        int n = A.size(), left = 1, right = 1e9;
        int mod=1e7;
        
        if(((lli)m*(lli)k)%right > n) return -1;
        
        while (left < right) {
            int mid = (left + right) / 2, flow = 0, bouq = 0;
            for (int j = 0; j < n; ++j) {
                if (A[j] > mid) {
                    flow = 0;
                } else if (++flow >= k) {
                    bouq++;
                    flow = 0;
                }
            }
            if (bouq < m) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return left;
    }
 
};