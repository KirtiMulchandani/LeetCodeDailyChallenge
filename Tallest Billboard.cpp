class Solution {
public:
    int dp[20][10001];
    int solve(int index, int diff, vector<int>& rods){
        if(index == rods.size()){
            if(diff == 0) return 0;
            return -1e5;
        }

        if(dp[index][diff + 5000] != -1) return dp[index][diff + 5000];
        int ans1 = solve(index + 1, diff, rods);
        int ans2 = rods[index] + solve(index + 1, diff + rods[index], rods);
        int ans3 = rods[index] + solve(index + 1, rods[index] - diff, rods);

        return dp[index][diff + 5000] = max(ans1, max(ans2, ans3));

    }
    int tallestBillboard(vector<int>& rods) {
        memset(dp, -1, sizeof(dp));
        int ans = solve(0, 0, rods)/2;
        if(ans < 0) ans = 0;
        return ans;
        
    }
};
