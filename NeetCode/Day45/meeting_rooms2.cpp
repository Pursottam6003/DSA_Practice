#include <bits/stdc++.h>
using namespace std;

class Solution 
{
    public:
    int meetingRoom2(vector<vector<int>> intervals)
    {   
        int res=0;

        vector <int> start,end;
        int n = intervals.size();

        for(int i=0;i<n;i++)
        {
            start.push_back(intervals[i][0]);
            end.push_back(intervals[i][1]);
        }

        sort(start.begin(),start.end());
        sort(end.begin(),end.end());
        int cnt=0;
        int s=0,e=0;
        while(s < n)
        {
            if(start[s++] < end[e])
            {
                cnt++;
            }
            else {cnt--;
                e++;
            }
            res = max(res,cnt);
        }
        return res;
    }
};
int main()
{
    Solution sol;
    vector <vector<int>> interval= {{0, 30},{5, 10},{15, 20}};
    cout<<sol.meetingRoom2(interval)<<endl;
    return 0;
}