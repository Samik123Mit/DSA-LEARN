https://leetcode.com/problems/combination-sum-ii/submissions/1870638060/


class Solution {
public:
vector<vector<int>> result;
void powset(vector<int>&candidates,int start,int target,int sum,vector<int>&res){
   
    if(sum==target){
        result.push_back(res);
        return;}
        if(sum>target)return;

    for(int i=start;i<candidates.size();i++){
         if(i>start && candidates[i]==candidates[i-1]){
        continue;
    }
        res.push_back(candidates[i]);
        sum+=candidates[i];
        powset(candidates,i+1,target,sum,res);
        sum-=candidates[i];
        res.pop_back();
    }
}
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        int n=candidates.size();
        sort(candidates.begin(),candidates.end());
        vector<int> res;
        int sum=0;
        powset(candidates,0,target,sum,res);
        return result;
    }
};
