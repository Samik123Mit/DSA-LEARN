https://leetcode.com/problems/powx-n/submissions/1870412082/

Time Complexity: O(log |n|)

Space Complexity: O(1)

class Solution {
public:
    double myPow(double x, int n) {
        double ans=1;
        //long long b=abs(static_cast<long long> (n));//since int cant handle INT_MIN as theres no negative available for it...
        long long b=n;
        if(b<0){
            x=1/x;
            b=-b;
        }
        while(b!=0){
            if(b&1)ans=ans*x;//if odd,multiply once
            x*=x; //squaring the base
            b>>=1; //dividing by 2
        }
        return ans;
    }
};

