class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> ans;
        priority_queue<pair<int, pair<int, int>>> maxHeap;

        for(auto itr : points){
            int dist= itr[0]*itr[0] + itr[1]*itr[1];

            maxHeap.push({dist, {itr[0], itr[1]}});
            if(maxHeap.size() > k){
                maxHeap.pop();
            }
        }

        while(!maxHeap.empty()){
            ans.push_back({maxHeap.top().second.first, maxHeap.top().second.second});
            maxHeap.pop();
        }

        return ans;
    }
};
