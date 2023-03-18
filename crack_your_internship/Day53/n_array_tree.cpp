// https://leetcode.com/problems/maximum-depth-of-n-ary-tree/solutions/167010/dfs-bfs-solutions-in-c/?orderBy=most_votes

class Solution {
public:
    int maxDepth(Node* root) {
        if (root == nullptr) return 0;
        int depth = 0;
        for (auto child : root->children) depth = max(depth, maxDepth(child));
        return 1 + depth;
    }
};