class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        ans.clear();
        sort(candidates.begin(), candidates.end());

        dfs(0, {}, 0, candidates, target);
        return ans;
    }

private:
    void dfs(int index, vector<int> subset, int cur, vector<int>& candidates, int target){
        if(cur == target){
            ans.push_back(subset);
            return;
        }

        for(int i= index; i< candidates.size(); i++){
            if(i > index && candidates[i]==candidates[i-1]){
                continue;
            }

            if(cur + candidates[i] > target){
                break;
            }

            subset.push_back(candidates[i]);

            dfs(i+1, subset, cur + candidates[i], candidates, target);

            subset.pop_back();
        }
    }
};
