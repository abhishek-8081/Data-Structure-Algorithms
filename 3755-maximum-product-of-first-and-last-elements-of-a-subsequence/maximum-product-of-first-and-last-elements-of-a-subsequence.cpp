class Solution {
public:
    long long maximumProduct(vector<int>& nums, int m) {
        int n = nums.size();
        if (n == 1) return 1LL * nums[0] * nums[0];
        vector<int> minFromRight(n), maxFromRight(n);

        minFromRight[n - 1] = nums[n - 1];
        maxFromRight[n - 1] = nums[n - 1];

        for (int i = n - 2; i >= 0; i--) {
            minFromRight[i] = min(nums[i], minFromRight[i + 1]);
            maxFromRight[i] = max(nums[i], maxFromRight[i + 1]);
        }

        long long maxProduct = LLONG_MIN;

        for (int i = 0; i <= n - m; i++) {
    
            int j = i + m - 1;

            if (nums[i] >= 0) {
                maxProduct = max(maxProduct, 1LL * nums[i] * maxFromRight[j]);
            } else {
                
                maxProduct = max(maxProduct, 1LL * nums[i] * minFromRight[j]);
            }
        }

        return maxProduct;
    }
};
