https://leetcode.com/problems/palindrome-partitioning/submissions/1871365549/

class Solution {
public:
vector<vector<string>>ans;

bool ispalin(string s,int l,int r){
    while(l<r){
        if(s[l]!=s[r])return false;
        l++;
        r--;
    }
    return true;
}

 void palind(int idx, string cur, string s,vector<string> res){
    if(s.size()==idx){
        ans.push_back(res);
        return;
    }
    for(int i=idx;i<s.size();i++){
if(ispalin(s,idx,i)){
    res.push_back(s.substr(idx,i-idx+1));
    palind(i+1,cur,s,res);
    res.pop_back();
}
    }


 }
    vector<vector<string>> partition(string s) {
        string cur="";
        vector<string>res;
        if(s.size()==0)return {{}};
        palind(0,cur,s,res);
        return ans;

    }
};