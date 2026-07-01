class Solution {
public:
    string minRemoveToMakeValid(string s) {
        vector<int> open_indices;
        
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                open_indices.push_back(i);
            } else if (s[i] == ')') {
                if (!open_indices.empty()) {
                    open_indices.pop_back();
                } else {
                    s[i] = '*'; 
                }
            }
        }
        for (int index : open_indices) {
            s[index] = '*';
        }
        
        string result = "";
        for (char c : s) {
            if (c != '*') result += c;
        }
        
        return result;
    }
};