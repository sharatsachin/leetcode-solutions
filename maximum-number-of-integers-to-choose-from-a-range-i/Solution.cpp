// https://leetcode.com/problems/maximum-number-of-integers-to-choose-from-a-range-i

class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum)
    {

        vector<int> all;
        for (int i = 1; i <= n; i++)
            all.push_back(i);
        sort(all.begin(), all.end());
        sort(banned.begin(), banned.end());
        vector<int> di;
        set_difference(
            all.begin(), all.end(),
            banned.begin(), banned.end(),
            back_inserter(di));
        sort(di.begin(), di.end());
        int sm = 0;
        int i;
        for(i = 0; i < di.size(); i++) {
            sm += di[i];
            if (sm > maxSum) break;
        }
        return i;
    }
};