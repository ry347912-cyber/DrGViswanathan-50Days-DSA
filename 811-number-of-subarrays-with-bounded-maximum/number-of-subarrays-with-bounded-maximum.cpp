#include <vector>

class Solution {
private:
    // Helper function to count subarrays where all elements are <= bound
    int countSubarraysLessThanOrEqualTo(const std::vector<int>& nums, int bound) {
        int count = 0;
        int current_window_len = 0;
        
        for (int num : nums) {
            if (num <= bound) {
                current_window_len++;
                count += current_window_len;
            } else {
                current_window_len = 0; // Window breaks
            }
        }
        
        return count;
    }

public:
    int numSubarrayBoundedMax(std::vector<int>& nums, int left, int right) {
        // Subarrays with max <= right MINUS subarrays with max < left
        return countSubarraysLessThanOrEqualTo(nums, right) - 
               countSubarraysLessThanOrEqualTo(nums, left - 1);
    }
};