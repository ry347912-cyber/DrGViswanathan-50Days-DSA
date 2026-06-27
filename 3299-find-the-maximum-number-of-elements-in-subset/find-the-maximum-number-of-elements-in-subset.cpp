#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maximumLength(vector<int>& nums) {
        unordered_map<long long, int> count;
        for (int num : nums) {
            count[num]++;
        }
        
        int max_len = 1;  
        
       
        if (count.count(1)) {
            int c = count[1];
            max_len = max(max_len, (c % 2 != 0) ? c : c - 1);
        }
        
      
        for (auto& [x, _] : count) {
            if (x == 1) continue;
            
            int current_len = 0;
            long long current = x;
            
           
            while (count.count(current) && count[current] >= 2) {
                current_len += 2;
                current = current * current;
                if (current > 1e9) break; 
            }
            
          
            if (count.count(current) && count[current] == 1) {
                current_len += 1;
            } else {
               
                current_len -= 1;
            }
            
            max_len = max(max_len, current_len);
        }
        
        return max_len;
    }
};