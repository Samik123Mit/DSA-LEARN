https://leetcode.com/problems/letter-combinations-of-a-phone-number/submissions/1871352415/

class Solution {
public:
vector<string> res;
void generate(int idx,string digits,string cur,vector<string>&mp){
    if(idx==digits.size()){
        res.push_back(cur);
        return ;
    }
    string letters=mp[digits[idx]-'0'];
    for(char c:letters){
        cur.push_back(c);
        generate(idx+1,digits,cur,mp);
        cur.pop_back();
    }
   
}
    vector<string> letterCombinations(string digits) {
        if(digits.size()==0)return {};
        vector<string>mp(10);
        mp[2]="abc";
        mp[3]="def";
        mp[4]="ghi";
        mp[5]="jkl";
        mp[6]="mno";
        mp[7]="pqrs";
        mp[8]="tuv";
        mp[9]="wxyz";
        
        string cur="";
        generate(0,digits,cur,mp);
        return res;
    }
    
};