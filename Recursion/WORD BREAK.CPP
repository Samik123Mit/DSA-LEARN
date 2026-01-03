https://leetcode.com/problems/word-break/submissions/1873575025/

class Solution {
public:
vector<int> dp;

    bool solve(int idx, string &s, unordered_set<string> &dict) {
        if (idx == s.size()) return true;
         if (dp[idx] != -1) return dp[idx];

        string temp = "";
        for (int i = idx; i < s.size(); i++) {
            temp.push_back(s[i]);//building words char by char
            if (dict.count(temp)) {//if tht word exists
                if (solve(i + 1, s, dict)) return dp[idx] = 1;//if valid, break the remaining string , n start with next idx
            }
        }
       return dp[idx] = 0;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());//we r using this since it lets us check if the word is present in the dict in O(1)time using dict .count!!!!-> vector would have taken O(n) time uk!
        dp.assign(s.size(), -1);
        return solve(0, s, dict);
    }
};
