// https://leetcode.com/problems/take-gifts-from-the-richest-pile

class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        std::priority_queue<int> q1;
        for (int n : gifts) q1.push(n);
        for(int i = 0; i < k; i++) {
            int x = q1.top();
            q1.pop();
            q1.push(floor(sqrt(x)));
        }
        long long s=0;
        for (; !q1.empty(); q1.pop()) s+=q1.top();
        return s;
    }
};