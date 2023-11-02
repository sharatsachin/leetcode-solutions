// https://leetcode.com/problems/count-nodes-equal-to-average-of-subtree

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int averageOfSubtree(TreeNode* root) {
        ret = 0;
        solve(root, 0, 0);
        return ret;
    }

private:
    int ret = 0;
    pair<int, int> solve(TreeNode* node, int sum, int count) {
        if (node == nullptr) return {0, 0};
        sum = 0, count = 0;
        int s1, c1, s2, c2;
        tie(s1, c1) = solve(node->left, sum, count);
        tie(s2, c2) = solve(node->right, sum, count);
        sum = s1 + s2 + node->val;
        count = c1 + c2 + 1;
        if (node->val == sum / count) ret++;
        return {sum, count};
    }
};