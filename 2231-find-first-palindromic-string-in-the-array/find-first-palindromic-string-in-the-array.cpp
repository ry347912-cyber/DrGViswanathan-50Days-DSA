class Solution {
public:
    string firstPalindrome(vector<string>& words) {
        for (const string& word : words) {
            if (isPalindrome(word)) {
                return word; // Found the first palindrome, return it immediately
            }
        }
        return ""; // If no palindrome is found after checking all words
    }

private:
    bool isPalindrome(const string& s) {
        int left = 0;
        int right = s.length() - 1;
        
        while (left < right) {
            if (s[left] != s[right]) {
                return false; // Characters don't match, not a palindrome
            }
            left++;
            right--;
        }
        return true; // All characters matched
    }
};