// https://leetcode.com/problems/build-an-array-with-stack-operations

class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        target.insert(target.begin(), 0);
        int k = target.size();
        vector<string> ret;
        for(int i = 1; i < k; i++) {
            int d = (target[i] - target[i-1]) - 1;
            for(int j = 0; j < d; j++) {
                ret.push_back("Push");
                ret.push_back("Pop");
            }
            ret.push_back("Push");
        }
        return ret;
    }
};