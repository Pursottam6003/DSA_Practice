// https://www.codingninjas.com/studio/problems/get-all-unique-subsets_624393?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTab=0
void recurssion(int ind,vector <int> &arr,vector <int> &ds,vector <vector <int>> &res)
{
    // base case 
    res.push_back(ds);

    for(int i=ind;i<arr.size();i++)
    {
        if(i!=ind && arr[i] == arr[i-1]) continue;
        ds.push_back(arr[i]);
        recurssion(i+1,arr,ds,res);
        ds.pop_back();
    }
}
vector<vector<int>> getUniqueSubsets(vector<int>& arr) {
    // Write Your Code Here    

    vector <vector<int>> res;
    vector <int> ds;
    sort(arr.begin(),arr.end());
    recurssion(0,arr,ds,res);
    return res;
}