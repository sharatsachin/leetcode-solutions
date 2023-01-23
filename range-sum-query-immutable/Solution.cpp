// https://leetcode.com/problems/range-sum-query-immutable

class NumArray {
public:
    vector<int> psum;

    NumArray(vector<int>& nums) {
        int n = nums.size();
        psum.assign(n + 1, 0);
        for(int i = 1; i < n + 1; i++) {
            psum[i] = psum[i - 1] + nums[i - 1];
        }
        for(auto& x : psum) {
            cout << x << " ";
        } 
        cout << "\n";
    }
    
    int sumRange(int left, int right) {
        return psum[right + 1] - psum[left];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */