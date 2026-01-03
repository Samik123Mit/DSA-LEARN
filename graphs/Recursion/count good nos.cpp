https://leetcode.com/problems/count-good-numbers/submissions/1870624195/
log n ->1e15

class Solution {
public:
int mod=1e9+7;

//Binary exponentiation to get pow(x,n), here n<=1e15;
long long pow(long long x,long long n){
    long long b=n;
    long long a=1;
    // if(b<0){
    //     x=1/x;
    //     b=-b;
    // }
    while(b>0){
        if(b&1){
            a=(a*x)%mod;
        }
        x=(x*x)%mod;
        b>>=1;
        // a=(x*a)%mod;
    }
    return a;
}
    int countGoodNumbers(long long n) {
        long long evenpos=(n+1)/2;
        long long oddpos=n/2;
        long long ans=1;
        ans=(pow(5,evenpos)*pow(4,oddpos))%mod;
        return ans;
    }
};