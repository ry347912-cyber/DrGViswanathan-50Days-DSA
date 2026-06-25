class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        const int MOD = 1e9 + 7;

        vector<int> sums;

        for (int i = 0; i < n; i++) {
            int cur = 0;

            for (int j = i; j < n; j++) {
                cur += nums[j];
                sums.push_back(cur);
            }
        }

        sort(sums.begin(), sums.end());

        long long ans = 0;

        for (int i = left - 1; i < right; i++)
            ans = (ans + sums[i]) % MOD;

        return ans;
    }
};