class Solution {
public:
    vector<string> res; // Stores the valid parentheses expressions
    unordered_map<string, int> mp; // Used for memoization to avoid recomputation
    
    // Helper function to calculate the minimum length of parentheses to remove
    int getMinInValid(string s) {
        stack<char> stck;
        int i = 0;
        
        while (i < s.size()) {
            if (s[i] == '(')
                stck.push('(');
            else if (s[i] == ')') {
                if (stck.size() > 0 && stck.top() == '(')
                    stck.pop();
                else
                    stck.push(')');
            }
            i++;
        }
        
        return stck.size();
    }
    
    // Recursive function to find all valid parentheses expressions
    void solve(string s, int minInv) {
        if (mp[s] != 0)
            return; // Skip if the current expression is already computed
        else
            mp[s]++; // Mark the expression as computed
        
        // Base case: if minimum invalid count is less than 0, the expression is invalid
        if (minInv < 0) {
            return;
        }
        
        // Base case: if minimum invalid count is 0 and the expression is valid,
        // add it to the result vector
        if (minInv == 0) {
            if (!getMinInValid(s))
                res.push_back(s);
            return;
        }
        
        // Recursive case: remove parentheses one by one and recursively call the function
        for (int i = 0; i < s.size(); i++) {
            string left = s.substr(0, i); // Expression before the current parentheses
            string right = s.substr(i + 1); // Expression after the current parentheses
            solve(left + right, minInv - 1);
        }
        
        return;
    }
    
    // Main function to remove invalid parentheses
    vector<string> removeInvalidParentheses(string s) {
        solve(s, getMinInValid(s)); // Start the recursive process
        return res; // Return the valid parentheses expressions
    }
};
