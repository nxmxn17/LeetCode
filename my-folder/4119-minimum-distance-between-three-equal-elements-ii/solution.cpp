class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        unordered_map<int, vector<int>> mp;
        int n = nums.size();
        for(int i=0; i<n; i++) {
            mp[nums[i]].push_back(i);
        }
        int ans = INT_MAX;
        for(auto &ele:mp) {
            vector<int> v = ele.second;
            if(v.size() < 3) continue;
            for(int i=0; i<v.size()-2; i++) {
                int dist = abs(v[i]-v[i+1]) + abs(v[i]-v[i+2]) + abs(v[i+2]-v[i+1]);
                ans = min(ans, dist);
            }
        }
        if(ans == INT_MAX) return -1;
        return ans;
    }
};
