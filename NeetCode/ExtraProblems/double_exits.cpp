class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        
        unordered_map <int,int> mpp;
        for(int i=0;i<arr.size();i++)
        {
            // store into the map 
            mpp[arr[i]]++;
        }

        for(auto i: arr)
        {
            int val = 2*i;
            if(i!=0 && mpp.find(val) != mpp.end())
            {
                return true;
            }

            // else if its count is >0
            else if(i==0 && mpp[0]>=2)
            {
                // series of zero 
                return true;
            }
        }
        return false;
    }
};