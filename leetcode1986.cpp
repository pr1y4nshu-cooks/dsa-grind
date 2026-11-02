class Solution {
public:
    vector<vector<int>> dp;
    int solve(int bits, int session, vector<int>& tasks, int sessionTime, vector<vector<int>>& dp){
        int n = tasks.size();
        if (bits==((1<<n)-1)) return 1;
        if (dp[bits][session] != -1) return dp[bits][session];
        int ans = 1e8;
        for (int i = 0; i< n;i++){
            if (bits&(1<<i))continue;
            int nbits = bits | (1<<i);
            if (session >= tasks[i]){
                ans = min(ans, solve(nbits, session-tasks[i], tasks, sessionTime, dp));
            } else {
                ans = min(ans, 1+solve(nbits, sessionTime-tasks[i], tasks, sessionTime,dp));
            }
        }
        return dp[bits][session] = ans;
    }
    int minSessions(vector<int>& tasks, int sessionTime) {
        dp.resize(1 << tasks.size(), vector<int>(sessionTime + 1, -1));
        return solve(0, sessionTime, tasks, sessionTime, dp);
    }
};
