//https://leetcode.com/problems/generate-parentheses/submissions/1505157479/

class Solution {
public:
 void generate(int n, string &s, int open, int close, vector<string> &valid) {
        if (open == 0 && close == 0) {
            valid.push_back(s);
            return;
        }
        if (open > 0) {
            s.push_back('(');
            generate(n, s, open - 1, close, valid);
            s.pop_back();
        }
        if (close > open) {
            s.push_back(')');
            generate(n, s, open, close - 1, valid);
            s.pop_back();
        }
 }

    vector<string> generateParenthesis(int n) {
        vector<string> valid;
        string s;
        generate(n, s, n, n, valid);
        return valid;
    }

   
    
};
