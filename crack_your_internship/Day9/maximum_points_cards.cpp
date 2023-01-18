// https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards/description/
class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {

        // in this problem we have to find the maximum  subarray sum 
        // if we choose elements from beggingn or from end
        int totalSum=0;
        for(int i=0;i<cardPoints.size();i++)
        {
            totalSum += cardPoints[i];
        }

        // so we first calculate the totalsum and from the quesiton 
        // it is undestood that there is continuous subarray which has not been selected due to less sum

        // calculating the mininum subarray sum and subtracting from the total sum would gives us result

        int minimumSum=INT_MAX,runningSum=0;
        int rem = cardPoints.size()-k;
        for(int i=0;i<cardPoints.size()-k;i++)
        {
            runningSum+=cardPoints[i];
        }
        minimumSum = min(minimumSum,runningSum);

        for(int i=0;i<k;i++)
        {
            runningSum = runningSum-cardPoints[i];
            runningSum += cardPoints[rem+i];
            minimumSum = min(minimumSum,runningSum);
        }

        return (totalSum - minimumSum);

    }
};