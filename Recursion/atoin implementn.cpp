//atoi implementn
https://leetcode.com/problems/string-to-integer-atoi/submissions/1870398633/

O(n,1)

class Solution {
public:
    int myAtoi(string s) {
        int i = 0, n = s.size();
        int sign = 1;
        long long num = 0;

//1.remove whitespaces
        while (i < n && s[i] == ' ') i++;

        //check for sign
        if (i < n && (s[i] == '+' || s[i] == '-')) {
            if (s[i] == '-') sign = -1;
            i++;
        }

        //char to dig convert 
        while (i < n && s[i] >= '0' && s[i] <= '9') {
            num = num * 10 + (s[i] - '0');//build the no.
            //check for overflow
            if (sign == 1 && num > INT_MAX) return INT_MAX;
            if (sign == -1 && -num < INT_MIN) return INT_MIN;
            i++;
        }

        return sign * num;
    }
};
