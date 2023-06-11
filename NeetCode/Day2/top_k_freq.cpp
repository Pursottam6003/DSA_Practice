// https://leetcode.com/problems/top-k-frequent-elements/description/
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        unordered_map <int,int> mpp;
        vector <int> res;
        for(int i=0;i<nums.size();i++)
        {
            mpp[nums[i]]++;
        }

        priority_queue <pair<int,int>> pq;

        for(auto it: mpp)
        {
            pq.push(make_pair(it.second,it.first));
        }    

        while(!pq.empty() && k--)
        {
            pair<int,int> p = pq.top();
            res.push_back(p.second);
            pq.pop();
        }
    
        return res;
    }
};

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        

        // creating an unordered map to store the eleements 

        unordered_map <int,int> mpp;

        // populate the elements inside the map 

        for(int i=0;i<nums.size();i++)
        {   // here i am storing the frequency of elements associated
            // with map structure 
            mpp[nums[i]]++;
        }

        // using the pq concept to evaluate the results 

        vector <int> res;
        // create a priority queue of pairs
        // the frequency help to store the elements with priority 
        // and helps in smooth retrieval 

        priority_queue <pair<int,int>> pq;
        // iterate over map and store the elements into the map 

        for(auto i: mpp)
        {
            pq.push(make_pair(i.second,i.first));
            if(pq.size() > mpp.size()-k)
            {   
                auto t = pq.top();
                res.push_back(t.second);
                // pop the elemeent afterthat 
                pq.pop();
            }
            // otherwise store into it 
        } 

        
  

        return res;
        //vector <vector<int>> bucket(0,vector <int> (nums.size()+1,0));
    }
};

class Solution {
public:
    /*
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        unordered_map <int,int> mpp;
        vector <int> res;
        for(int i=0;i<nums.size();i++)
        {
            mpp[nums[i]]++;
        }

        priority_queue <pair<int,int>> pq;

        for(auto it: mpp)
        {
            pq.push(make_pair(it.second,it.first));

            if(pq.size() > (int)mpp.size()-k)
            {
                res.push_back(pq.top().second);
                pq.pop();
            }

        }    
        return res;
    }
    */

    vector <int> topKFrequent(vector<int> &nums,int k)
    {
        unordered_map <int,int> m;
        for(int num: nums)
        {
            ++m[num];
        }

        vector <vector<int>> buckets (nums.size()+1);

        for(auto p: m)
        {
            buckets[p.second].push_back(p.first);
        }
        vector <int> res;

        for(int i=buckets.size()-1;i>=0 && res.size() <k;--i )
        {
            for(int num: buckets[i])
            {
                res.push_back(num);
                if(res.size()==k) 
                {
                    break;
                }
            }
        }

        return res;
      
    }
};



// https://leetcode.com/problems/top-k-frequent-elements/description/
