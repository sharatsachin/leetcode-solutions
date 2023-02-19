// https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal

class Solution {
public:
    vector<vector<int> > zigzagLevelOrder(TreeNode* root)
    {
        vector<vector<int> > ret;
        if (root == NULL)
            return ret;
        queue<TreeNode*> q;
        q.push(root);
        bool ltr = true;
        while (!q.empty()) {
            int size = q.size();
            vector<int> ds(size);
            for (int i = 0; i < size; i++) {
                TreeNode* t = q.front();
                q.pop();

                int ind = (ltr) ? i : (size - 1 - i);
                ds[ind] = t->val;

                if (t->left)
                    q.push(t->left);
                if (t->right)
                    q.push(t->right);
            }
            ltr = ltr ^ 1;
            ret.push_back(ds);
        }
        return ret;
    }
};