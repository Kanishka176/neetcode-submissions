class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        if (n == 0) return 0;
        int len=1;
        int max_len=1;

        sort(nums.begin(), nums.end());

        for(int i=0; i<n-1; i++){
            if(nums[i+1] == nums[i]) {
                continue;
            }
            if(nums[i+1]==nums[i]+1){
                len++;

            }
            else{
                len=1;
            }
                
            max_len = max(max_len, len);
            }
        return max_len;
        
    }
};

