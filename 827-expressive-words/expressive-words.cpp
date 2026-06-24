
#include <string>
#include <vector>

class Solution {
private:
    bool isStretchy(const std::string& s, const std::string& word) {
        int i = 0, j = 0;
        int n = s.length(), m = word.length();
        
        while (i < n && j < m) {
            if (s[i] != word[j]) return false;
            
            char c = s[i];
            int len1 = 0, len2 = 0;
            
            // Count length of character group in s
            while (i < n && s[i] == c) {
                len1++;
                i++;
            }
            
            // Count length of character group in word
            while (j < m && word[j] == c) {
                len2++;
                j++;
            }
            
            // Validate the stretchy conditions
            if (len1 < len2) return false;
            if (len1 > len2 && len1 < 3) return false;
        }
        
        // Both pointers must reach the end of their respective strings
        return i == n && j == m;
    }

public:
    int expressiveWords(std::string s, std::vector<std::string>& words) {
        int count = 0;
        for (const std::string& word : words) {
            if (isStretchy(s, word)) {
                count++;
            }
        }
        return count;
    }
};