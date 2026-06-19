#include <cmath>

class Solution {
public:
    bool checkPerfectNumber(int num) {
        if (num <= 1) {
            return false;
        }
        
        int divisor_sum = 1;
        
        for (int i = 2; i <= std::sqrt(num); ++i) {
            if (num % i == 0) {
                divisor_sum += i;
                if (i != num / i) {
                    divisor_sum += num / i;
                }
            }
        }
        
        return divisor_sum == num;
    }
};