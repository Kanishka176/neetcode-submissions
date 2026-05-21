class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n= nums.size();
        int prod=1;
        int zeroCount = 0;
        vector<int> result;

        for(int i=0; i<n; i++){
            if (nums[i] != 0) prod=prod*nums[i];
            else zeroCount++;
        }

        for(int i=0; i<n; i++){
            if (zeroCount > 1) {
                result.push_back(0);
            } else if (zeroCount == 1) {
                if (nums[i] == 0) result.push_back(prod);
                else result.push_back(0);
            } else {
                int store=(prod/nums[i]);
                result.push_back(store);
            }
        }

        return result;
    }
};
