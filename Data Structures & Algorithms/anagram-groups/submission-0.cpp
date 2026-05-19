class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        unordered_map<string, vector<string>> store;
        for (const auto& s : strs) {
            string sorted = s;
            sort(sorted.begin(), sorted.end());
            store[sorted].push_back(s);
        }
        vector<vector<string>> result;
        for (auto& pair : store) {
            result.push_back(pair.second);
        }
        return result;
    }
};
        
    
