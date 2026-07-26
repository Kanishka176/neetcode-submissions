class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());

        
        int index=0, total=0;
        vector<int> subset;

        dfs(index, subset, total, nums, target);

        return ans;
    }

    void dfs(int index, vector<int>& subset, int total, vector<int>& nums, int target){
        if(total==target){
            ans.push_back(subset);
            return;
        }

        for(int i= index; i < nums.size(); i++){
            if(total + nums[i] > target){
                return;
            }

            subset.push_back(nums[i]);

            dfs(i, subset, total+nums[i], nums, target);

            subset.pop_back();
        }
    }
};
