class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
       unordered_map<int,int> mpp;
       int n=nums.size();
       vector<pair<int,int>> store;
       vector<int> ans;

       for(int i=0; i<n; i++){
        mpp[nums[i]]++;
       } 

       for(const auto&i : mpp){
        store.push_back({i.second,i.first});
       }

       sort(store.rbegin(), store.rend());

       for(int j=0; j<k; j++){
        ans.push_back(store[j].second);
       }

       return ans;
    }
};
