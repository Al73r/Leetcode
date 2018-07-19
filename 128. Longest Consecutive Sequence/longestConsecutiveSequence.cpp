class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> dict(nums.begin(), nums.end());
        unordered_set<int> visited;
        int ans=0;
        for(auto n: nums) {
            if(visited.find(n)!=visited.end()) continue;
            visited.insert(n);
            int start=n;
            while(dict.find(start-1)!=dict.end()) {
                start--;
                visited.insert(start);
            }
            int end=n;
            while(dict.find(end+1)!=dict.end()) {
                end++;
                visited.insert(end);
            }
            ans = max(ans, end-start+1);
        }
        return ans;
    }
};