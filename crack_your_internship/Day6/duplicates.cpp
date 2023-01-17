
class Solution 
{
    public:
    vector <int> findDuplicates(vector <int> &arr)
    {
        // we need to check the element 
        // since the elements present inside the array is from 1-n 4
        vector <int> dupList;
        for(int i=0;i<arr.size();i++)
        {
            // since it is zero based array
            // abs becuase since we are negating the element
            // there is chances of getting -ve indexs
            int ind= abs(arr[i])-1;

            // negate the element 
            arr[ind] = -arr[ind];

            // if it is found to be +ve even after negation it means it is duplicate one

            // so add into our duplicate list
            if(arr[ind] >0)
            {
                dupList.push_back(ind+1);
            }
        }
        return dupList;
    }
};

