class Solution {
public:
    int characterReplacement(string s, int k) {
        int left=0, right, maxFreq=0, ans=0, len=0;
        int n=s.size();
        unordered_map<char, int> mp;

        for(right=0; right<n; right++){
            
            mp[s[right]]++;

            maxFreq= max(maxFreq, mp[s[right]]);

            while((right-left+1)-maxFreq>k){
                mp[s[left]]--;
                left++;
            }

            ans= max(ans, right-left+1);
        }
        return ans;
    }
};
