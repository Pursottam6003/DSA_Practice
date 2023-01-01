/// we find subarray sum from from i to j by 
// SUM[i-1] - SUM[j]
// if it has to be div by K then 
// SUM[i-1] - SUM[j] = K*something
// OR (SUM[i-1] - SUM[j]) %K  = (K*something) %K = 0
// OR SUM[i-1] % k == SUM[j]%k
// So basically for any SUM[i] if its remainder is same as remainder of any other SUM[ some index] then their sum % k == 0


class Solution {
public:
    int subarraysDivByK(vector<int>& A, int K) {
	
//         setting count for only 0th element of array count_rem to be 1
//         because we have sub array =  [ ]  which has sum of 0.
        int count_rem[10000]={1};
        
        int sum = 0,count=0;
        for(auto e:A){
            sum+=e;
//             plus K beacuse there are negative nums too
            int rem = ( (sum % K ) + K)%K;
			//Now to the main count we are adding the no. of sub arrays 
			// that we have already seen that they have remainder ==  rem
            count += count_rem[rem];
            count_rem[rem]++;
        }
        return count;
    }
};