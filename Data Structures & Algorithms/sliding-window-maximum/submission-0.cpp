class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n=nums.size();
        int left=0, right=k-1;
        vector<int> ans;

        while(right<n){
            int maxEl=INT_MIN;
            for(int i=left; i<=right; i++){
                maxEl=max(maxEl, nums[i]);
            }
            ans.push_back(maxEl);
            left++;
            right++;
        }
        return ans;
    }
};
