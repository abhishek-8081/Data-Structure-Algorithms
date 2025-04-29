class Solution {
public:
    long long countSubarrays(vector<int>& a, int k) {
        int n = a.size();
        int maxVal = *max_element(a.begin(), a.end());
        long long ans = 0;
        int cnt = 0;
        int i = 0, j = 0;

        while (j < n) {
            if (a[j] == maxVal) cnt++;

            while (i <= j && cnt == k) {
                if (a[i] == maxVal) cnt--;
                i++;
            }

            ans += i;
            j++;
        }

        return ans;
    }
};
