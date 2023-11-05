// https://leetcode.com/problems/find-the-winner-of-an-array-game

class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int n = arr.size();
        list<int> sim(arr.begin(), arr.end());
        int wins = 0;
        while(true) {
            int a = sim.front();
            sim.pop_front();
            int b = sim.front();
            sim.pop_front();
            if (a > b) {
                sim.push_front(a);
                sim.push_back(b);
                wins++;
            } else {
                sim.push_front(b);
                sim.push_back(a);
                wins = 1;
            }
            if (wins == k || wins == n) return sim.front();
        }
        return -1;
    }
};