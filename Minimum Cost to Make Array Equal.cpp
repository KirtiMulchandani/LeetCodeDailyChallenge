class Solution {
public:
    long long minCost(vector<int>& nums, vector<int>& cost) {
        vector<pair<int, int>> v;

        for(int i = 0; i < nums.size(); i++) v.push_back({nums[i], cost[i]});

        sort(v.begin(), v.end());

        long long sum = 0, total = 0, med = 0, i = 0, ans = 0;

        for(auto i : v) sum += i.second;

        while(i < v.size() && total < (sum + 1)/2){
            total += v[i].second;
            med = v[i].first;
            i++;
        }

        for(int i = 0; i < v.size(); i++) ans += abs(nums[i] - med) * cost[i];
        
        return ans;
    }
};
