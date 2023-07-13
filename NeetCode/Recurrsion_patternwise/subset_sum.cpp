// https://www.codingninjas.com/studio/problems/subset-sum_3843086?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTab=0
void recursion(int ind,int subarSum,vector<int> &arr,vector <int> &ds)
{
	if(ind == arr.size())
	{
		ds.push_back(subarSum);
		return;
	}
	
	// pick the sum 
	subarSum += arr[ind];
	recursion(ind+1,subarSum,arr,ds);

	// not pick 
	subarSum -= arr[ind];
	recursion(ind+1,subarSum,arr,ds);
}

vector<int> subsetSum(vector<int> &num){
	// Write your code here.	
	vector <int> res;
	// res.push_back(0);
	recursion(0,0,num,res);
	sort(res.begin(),res.end());
	return res;
}