class Solution {
public:
    string s1, s2;
    int n, m;
    unordered_map<long long, int> memo;

    long long key(int i, int j) {
        return ((long long)i << 32) ^ (unsigned long long)j;
    }

    int run(int i, int j) {
        long long k = key(i, j);
        if (memo.count(k)) return memo[k];

        if (i == n) {
            int sum = 0;
            for (int t = j; t < m; ++t) sum += (int)s2[t];
            return memo[k] = sum;
        }
        if (j == m) {
            int sum = 0;
            for (int t = i; t < n; ++t) sum += (int)s1[t];
            return memo[k] = sum;
        }

        if (s1[i] == s2[j]) return memo[k] = run(i + 1, j + 1);

        return memo[k] = min((int)s1[i] + run(i + 1, j),
                             (int)s2[j] + run(i, j + 1));
    }

    int minimumDeleteSum(string a, string b) {
        s1 = a; s2 = b;
        n = (int)s1.size();
        m = (int)s2.size();
        memo.clear();
        return run(0, 0);
    }
};