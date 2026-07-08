#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        long long MOD = 1e9 + 7;
        int n = s.length();
        
        // Precompute powers of 10 modulo MOD
        vector<long long> pow10(n + 1, 1);
        for (int i = 1; i <= n; ++i) {
            pow10[i] = (pow10[i - 1] * 10) % MOD;
        }
        
        // 1-indexed prefix arrays for easier range queries
        vector<int> cnt(n + 1, 0);       
        vector<long long> pref_sum(n + 1, 0); 
        vector<long long> val(n + 1, 0);      
        
        for (int i = 0; i < n; ++i) {
            int digit = s[i] - '0';
            
            cnt[i + 1] = cnt[i];
            pref_sum[i + 1] = pref_sum[i] + digit;
            
            if (digit != 0) {
                cnt[i + 1]++;
                val[i + 1] = (val[i] * 10 + digit) % MOD;
            } else {
                val[i + 1] = val[i]; 
            }
        }
        
        vector<int> answer;
        answer.reserve(queries.size());
        
        for (const auto& q : queries) {
            int l = q[0];
            int r = q[1];
            
            int k = cnt[r + 1] - cnt[l];
            
            if (k == 0) {
                answer.push_back(0);
                continue;
            }
            
            long long x = (val[r + 1] - (val[l] * pow10[k]) % MOD) % MOD;
            if (x < 0) x += MOD; 
            
            long long current_sum = pref_sum[r + 1] - pref_sum[l];
            
            long long result = (x * current_sum) % MOD;
            answer.push_back(result);
        }
        
        return answer;
    }
};