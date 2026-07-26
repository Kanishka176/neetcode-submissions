class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> subset;

        dfs(nums, 0, subset, ans);
        return ans;
    }

private:
    void dfs(vector<int>& nums, int index, vector<int>& subset, vector<vector<int>>& ans){
        if(index >= nums.size()){
            ans.push_back(subset);
            return;
        }

        subset.push_back(nums[index]);
        dfs(nums, index+1, subset, ans);
        subset.pop_back();
        dfs(nums, index+1, subset, ans);
    }
};
