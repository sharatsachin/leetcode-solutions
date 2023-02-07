// https://leetcode.com/problems/fruit-into-baskets

class Solution {
public:

    bool checkPossible(vector<int>& fruits, int k) {
        map<int, int> mp;
        int n = fruits.size();
        for(int i = 0; i < k; i++) mp[fruits[i]]++;
        if (mp.size() <= 2) return true;
        if (k >= n) return false;

        for(int i = k; i < n; i++) {
            mp[fruits[i]]++;
            mp[fruits[i-k]]--;
            if (mp[fruits[i-k]] == 0) mp.erase(fruits[i-k]);
            
            if (mp.size() <= 2) return true;
        }
        return false;
    }

    int totalFruit(vector<int>& fruits) {
        int li = 2, ri = fruits.size();
        int mi;
        while(li <= ri){
            int mi = (li + ri) / 2;
            if (checkPossible(fruits, mi)) li = mi + 1;
            else ri = mi - 1;
        }
        return li - 1;
    }
};