class Solution {
public:
    
    //Just naively calculating the original sum of absolute differences.
    int calcAbsDiffSum(vector<int>& a) {
        int n = (int) a.size();
        long long sum = 0;
        for(int i = 0; i < n - 1; ++i) {
            sum += abs(a[i] - a[i + 1]);
        }
        return sum;
    }
    
    const long long inf = (long long) 1e18;
    
    //Calculates the maximum result after reversing the subarray which is neither prefix, nor suffix.
    int reverseMiddleSubarray(vector<int>& a) {
        int n = (int) a.size();
        long long sum = calcAbsDiffSum(a);
        long long ans = sum;
        long long mx1 = -inf, _mx1 = -inf, mx2 = -inf, _mx2 = -inf;
        long long mx3 = -inf, _mx3 = -inf, mx4 = -inf, _mx4 = -inf; 
        for(int i = 1; i < n - 1; ++i) {
            mx1 = max(mx1, 1LL * (-abs(a[i] - a[i - 1]) - a[i - 1] - a[i]));
            _mx1 = max(_mx1, 1LL * (-abs(a[i] - a[i + 1]) + a[i] + a[i + 1]));
            mx2 = max(mx2, 1LL * (-abs(a[i] - a[i - 1]) + a[i] - a[i - 1]));
            _mx2 = max(_mx2, 1LL * (-abs(a[i] - a[i + 1]) + a[i] - a[i + 1]));
            mx3 = max(mx3, 1LL * (-abs(a[i] - a[i - 1]) + a[i - 1] - a[i]));
            _mx3 = max(_mx3, 1LL * (-abs(a[i] - a[i + 1]) + a[i + 1] - a[i]));
            mx4 = max(mx4, 1LL * (-abs(a[i] - a[i - 1]) + a[i] + a[i - 1]));
            _mx4 = max(_mx4, 1LL * (-abs(a[i] - a[i + 1]) - a[i] - a[i + 1]));
        }
        ans = max(ans, sum + mx1 + _mx1);
        ans = max(ans, sum + mx2 + _mx2);
        ans = max(ans, sum + mx3 + _mx3);
        ans = max(ans, sum + mx4 + _mx4);
        return ans;
    }
    
    //Calculates the maximum result after reversing a prefix subarray.
    int reversePrefix(vector<int>& a) {
        int n = (int) a.size();
        long long sum = calcAbsDiffSum(a);
        long long ans = sum;
        long long mx1 = a[0], _mx1 = -inf, mx2 = -a[0], _mx2 = -inf;
        for(int i = 0; i < n - 1; ++i) {
            _mx1 = max(_mx1, 1LL * (-a[i + 1] - abs(a[i] - a[i + 1])));
            _mx2 = max(_mx2, 1LL * (a[i + 1] - abs(a[i] - a[i + 1])));
        }
        ans = max(ans, sum + mx1 + _mx1);
        ans = max(ans, sum + mx2 + _mx2);
        return ans;
    }
    
    //Calculates the maximum result after reversing a suffix subarray.
    int reverseSuffix(vector<int>& a) {
        int n = (int) a.size();
        long long sum = calcAbsDiffSum(a);
        long long ans = sum;
        long long mx1 = -inf, _mx1 = -a[n - 1], mx2 = -inf, _mx2 = a[n - 1];
        for(int i = 1; i < n; ++i) {
            mx1 = max(mx1, 1LL * (-abs(a[i] - a[i - 1]) + a[i - 1]));
            mx2 = max(mx2, 1LL * (-abs(a[i] - a[i - 1]) - a[i - 1]));
        }
        ans = max(ans, sum + _mx1 + mx1);
        ans = max(ans, sum + _mx2 + mx2);
        return ans;
    }
    
    int maxValueAfterReverse(vector<int>& nums) {
        int len = (int) nums.size();
        if(len <= 1) return 0;
        if(len == 2) return abs(nums[0] - nums[1]);
        return max(reverseMiddleSubarray(nums), max(reversePrefix(nums), reverseSuffix(nums)));
    }
};