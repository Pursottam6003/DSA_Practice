/*
If we calculate all distances between 4 points, 4 smaller distances should be equal (sides), and 2 larger distances should be equal too (diagonals). As an optimization, we can compare squares of the distances, so we do not have to deal with the square root and precision loss.

Therefore, our set will only contain 2 unique distances in case of square (beware of the zero distance though).
*/

// https://leetcode.com/problems/valid-square/description/
class Solution {
public:
    int calcDist(vector <int> &p1,vector <int> &p2)
    {
        int dist = (p1[0] - p2[0]) * (p1[0] - p2[0]) + (p1[1]-p2[1]) * (p1[1]-p2[1]);
        return dist;
    }
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
     
        unordered_set <int> s({calcDist(p1,p2), calcDist(p1,p3),calcDist(p1,p4),calcDist(p2,p3),calcDist(p2,p4),calcDist(p3,p4)});

        return !s.count(0) && s.size()==2;
    }
};