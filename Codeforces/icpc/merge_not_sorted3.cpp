#include <bits/stdc++.h>
using namespace std;
void findNGE(int arr[], int n,vector<int> &b)
{
	stack<int> s;
	s.push(0);
	for (int i = 1; i < n; i++) {
 
		if (s.empty()) {
			s.push(i);
			continue;
		}
		while (s.empty() == false && arr[s.top()] <= arr[i]) {
			// cout << s.top() << " --> " << arr[i] << endl;
            b[s.top()]=i;
			s.pop();
		}
		s.push(i);
	}
	while (s.empty() == false) {
		// cout << s.top() << " --> " << -1 << endl;
        b[s.top()] = -1;
		s.pop();
	}
}
 
int main()
{
    int n;cin>>n;
    int arr[(2*n)];
    for(int i=0;i<2*n;i++)cin>>arr[i];
    vector<int> nge(2*n);
    int curr=0;
    bool ok=true;
    vector<vector<int>> ans(2,vector<int>());
	findNGE(arr, 2*n , nge);
    for(int i=0;i<2*n;i++){
        int idx = nge[i];
        int req = n-ans[curr].size();
        if(idx == -1){
            int is = 2*n - i -1;
            if(is>req){ok=false;break;}
            for(int t=i;t<2*n;t++)ans[curr].push_back(arr[t]);
            break;
        }
        // cout<<"i= "<<i<<endl;
        // cout<<"idx = "<<idx<<endl;
        int is = idx - i;
        if(is>req){ok=false;break;}
        for(int t=i;t<idx;t++)ans[curr].push_back(arr[t]);
        curr = (curr+1)%2;
        ans[curr].push_back(arr[idx]);
        i=idx;
    }
    // for(auto e:nge)cout<<e<<" ";cout<<endl;
    if(!ok)cout<<-1;
    else{
        for(auto e:ans[0])cout<<e<<" ";cout<<endl;
        for(auto e:ans[1])cout<<e<<" ";cout<<endl;
    }
	return 0;
}