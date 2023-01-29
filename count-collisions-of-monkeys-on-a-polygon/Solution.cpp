// https://leetcode.com/problems/count-collisions-of-monkeys-on-a-polygon

using ll = long long;
ll M = 1e9+7;

class Solution {
public:
    
    ll binpow(ll a, ll b, ll m) { // finding (a^b)%m in log(b)
        a %= m;
        ll res = 1;
        while (b > 0) {
            if (b & 1)
                res = res * a % m;
            a = a * a % m;
            b >>= 1;
        }
        return res;
    }
    
    int monkeyMove(int n) {
        return (binpow(2, n, M) + M - 2) % M;
    }
};