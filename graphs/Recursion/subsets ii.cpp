https://leetcode.com/problems/subsets-ii/submissions/1870630917/

class Solution {
public:
vector<vector<int>> result;
void powset(vector<int>&nums,int start,vector<int>&res){
    result.push_back(res);
    for(int i=start;i<nums.size();i++){
        if(i>start && nums[i]==nums[i-1]){
            continue;
        }
        res.push_back(nums[i]);
        powset(nums,i+1,res);
        res.pop_back();
    }
}
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n=nums.size();
        vector<int>res;
        sort(nums.begin(),nums.end());
        powset(nums,0,res);
        return result;

    }
};