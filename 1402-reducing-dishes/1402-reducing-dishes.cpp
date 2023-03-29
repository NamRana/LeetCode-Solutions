class Solution {
public:
    int maxSatisfaction(vector<int>& A) {
        sort(A.begin(), A.end());
        int res = 0, total = 0, n = A.size();
        int ans = 0;
        for (int i = n - 1; i >= 0; --i) {
            total += A[i];
            res += total;
            ans = max(ans,res);
        }
        return ans;
    }
};