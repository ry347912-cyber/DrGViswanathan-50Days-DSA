#include <vector>
#include <algorithm>

class Solution {
public:
    int maxIceCream(std::vector<int>& costs, int coins) {
      
        int max_cost = *std::max_element(costs.begin(), costs.end());
     
        std::vector<int> freq(max_cost + 1, 0);
        for (int cost : costs) {
            freq[cost]++;
        }
        
        int ice_cream_count = 0;
        
      
        for (int price = 1; price <= max_cost; ++price) {
            if (freq[price] == 0) continue;
            
            
            if (coins < price) break;
            
        
            int count_to_buy = std::min(freq[price], coins / price);
            
        
            ice_cream_count += count_to_buy;
            coins -= count_to_buy * price;
        }
        
        return ice_cream_count;
    }
};