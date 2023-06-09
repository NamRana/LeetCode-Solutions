class Solution {
    int dfs(int i, int t, vector<int> &nums, vector<vector<int>> &dp) {
        if(!i) {
            if(!nums[0] && !t) return 2;
            if(!t) return 1;
            return nums[0] == t;
        }
        if(dp[i][t] != -1) return dp[i][t];

        int notPick = dfs(i - 1, t, nums, dp);
        int pick = nums[i] <= t ? dfs(i - 1, t - nums[i], nums, dp) : 0;

        return dp[i][t] = pick + notPick;
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int ts = accumulate(nums.begin(), nums.end(), 0), n = nums.size();
        if((target + ts) % 2 || target > ts || target < -ts) return 0;
        int t = (target + ts) / 2;

        vector<vector<int>> dp(n, vector<int>(t + 1, -1));
        return dfs(n - 1, t, nums, dp);
    }
};