class Solution {
public:
    int dp[101][201];
    int m = 1e9 + 7;
    int solve(int start, int finish, int fuel, vector<int>& locations){
        if(dp[start][fuel] != -1) return dp[start][fuel];
        int ans = 0;
        if(start == finish){
            ans = 1;
        }

        for(int j = 0; j < locations.size(); j++){
            if(locations[j] == locations[start]) continue;
            if(abs(locations[j] - locations[start]) <= fuel){
                ans = (ans + solve(j, finish, fuel - abs(locations[j] - locations[start]), locations)) % m;
            } 
        }

        return dp[start][fuel] = ans % m;
    }
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        memset(dp, -1, sizeof(dp));
        return solve(start, finish, fuel, locations) % m;
    }
};
