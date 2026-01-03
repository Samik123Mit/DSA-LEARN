https://leetcode.com/problems/expression-add-operators/submissions/1873631621/

har index k liye store krlo, idx, cur, last ->last only for the case of *, for every index we will try +,- and* and evalutaig the expression if equal to target by applying dfs to it , nd there we will in *, we will subtract last and add val*last to it to follow the precedence of * first, and then doin the leading zeros check n break if they come

class Solution {
public:
    vector<string> res;

    void dfs(string &num, long target, int idx, long curr, long last, string expr) {
        if (idx == num.size()) {
            if (curr == target)
                res.push_back(expr);
            return;
        }

        for (int i = idx; i < num.size(); i++) {
            if (i > idx && num[idx] == '0') break;

            string part = num.substr(idx, i - idx + 1);
            long val = stol(part);

            if (idx == 0) {
                dfs(num, target, i + 1, val, val, part);
            } else {
                dfs(num, target, i + 1, curr + val, val, expr + "+" + part);
                dfs(num, target, i + 1, curr - val, -val, expr + "-" + part);
                dfs(num, target, i + 1,
                    curr - last + last * val,
                    last * val,
                    expr + "*" + part);
            }
        }
    }

    vector<string> addOperators(string num, int target) {
        dfs(num, target, 0, 0, 0, "");
        return res;
    }
};
