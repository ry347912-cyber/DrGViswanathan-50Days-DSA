class Solution {
public:
    int subarrayLCM(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = 0;

        for (int i = 0; i < n; i++) {
            long long l = 1;

            for (int j = i; j < n; j++) {
                l = lcm(l, (long long)nums[j]);

                if (l == k)
                    ans++;

                if (l > k || k % l != 0)
                    break;
            }
        }

        return ans;
    }
};