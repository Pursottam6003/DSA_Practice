
// https://leetcode.com/problems/jump-game/description/
#include <bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    bool canJump(vector <int> &arr)
    {
        int reach=0;// counter to be able to reach the destination or not 

        for(int i=0;i<arr.size();i++)
        {   
            if(reach <i ) return false;
            reach = max(arr[i]+i,reach);
        }
        return true;
    }
};