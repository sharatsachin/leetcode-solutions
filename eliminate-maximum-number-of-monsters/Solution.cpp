// https://leetcode.com/problems/eliminate-maximum-number-of-monsters

class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed)
    {
        int n = dist.size();
        vector<float> time(n, 1);
        for (int i = 0; i < n; i++)
            time[i] = (float)dist[i] / (float)speed[i];
        sort(time.begin(), time.end());
        for (int i = 0; i < n; i++)
            time[i] = time[i] - i;
        for (int i = 0; i < n; i++)
            if (time[i] <= 0)
                return i;
        return n;
    }
};