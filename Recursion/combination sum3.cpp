https://leetcode.com/problems/combination-sum-iii/submissions/1870639484/


class Solution {
public:
vector<vector<int>> result;
void powset(vector<int>&candidates,int start,int target,int sum,vector<int>&res,int k){
   
    if(sum==target && res.size()==k){
        result.push_back(res);
        return;}
        if(sum>target)return;

    for(int i=start;i<candidates.size();i++){
         if(i>start && candidates[i]==candidates[i-1]){
        continue;
    }
        res.push_back(candidates[i]);
        sum+=candidates[i];
        powset(candidates,i+1,target,sum,res,k);
        sum-=candidates[i];
        res.pop_back();
    }
}
    vector<vector<int>> combinationSum3(int k,int target) {
       // int n=candidates.size();
        vector<int>candidates{1,2,3,4,5,6,7,8,9};
        sort(candidates.begin(),candidates.end());
        vector<int> res;
        int sum=0;
        powset(candidates,0,target,sum,res,k);
        return result;
    }
};
