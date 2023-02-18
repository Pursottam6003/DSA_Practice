// https://leetcode.com/problems/max-points-on-a-line/description/
/*
class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        if (n == 1) {
            return 1;
        }
        int result = 2;
        for (int i = 0; i < n; i++) {
            unordered_map<double, int> cnt;
            for (int j = 0; j < n; j++) {
                if (j != i) {
                    cnt[atan2(points[j][1] - points[i][1], points[j][0] - points[i][0])]++;
                }
            }
            for (auto [h, count] : cnt) {
                result = max(result, count + 1);
            }
        }
        return result;
    }
};
*/

class Solution 
{
    public:

    int maxPoints(vector <vector<int>> &points)
    {
        unordered_map <float,int> mpp;
        int max=0;
        for(int i=0;i<points.size()-max-1;i++)
        {   int i_max=0;
            for(int j=i+1;j<points.size();j++)
            {   float slope;
                if(points[j][0]- points[i][0] ==0)
                    slope = INT_MAX;
                else slope = (float)(points[j][1] - points[i][1])/(float)(points[j][0]- points[i][0]);
                if(mpp.find(slope) != mpp.end())
                    mpp[slope]++;
                // insert new slope into the mapp
                else   mpp[slope]++;

                i_max = (i_max > mpp[slope]) ? i_max : mpp[slope];
            }

            max = (max > i_max) ? max : i_max;
            mpp.clear();
        }
        return max+1;
    }
};