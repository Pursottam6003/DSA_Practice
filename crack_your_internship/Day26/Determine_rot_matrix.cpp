// https://leetcode.com/problems/determine-whether-matrix-can-be-obtained-by-rotation/description/
class Solution {
public:

    vector<vector<int>> rotate(vector <vector<int>> &mat)
    {
        for(int i=0;i<mat.size();i++)
        {
            for(int j=0;j<i;j++)
            {
                swap(mat[i][j],mat[j][i]);
            }
        }

        for(int i=0;i<mat.size();i++)
        {
            for(int j=0;j<mat[i].size()/2;j++)
            {
                swap(mat[i][j],mat[i][mat[i].size()-j-1]);
            }
        }
        return mat;
    }

    bool check(vector<vector<int>> &mat,vector<vector<int>> &target)
    {
        int n=mat.size(),m=target[0].size();

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(mat[i][j] != target[i][j])
                    return false;
            }
        }

        return true;
    }
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        
        // rotate 1 st time
        mat = rotate(mat);
        bool res1= check(mat,target);

        if(res1) return true;
        // rotate 2nd time
        mat =rotate(mat);
        res1 = check(mat,target);
        if(res1) return true;

        // third
        rotate(mat);
        res1 = check(mat,target);
        if(res1) return true;

        // forth
        rotate(mat);
        res1 = check(mat,target);
        if(res1) return true;

        return false;

        
    }
};