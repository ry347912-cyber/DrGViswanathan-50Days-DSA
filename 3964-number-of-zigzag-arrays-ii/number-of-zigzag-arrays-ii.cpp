#include <vector>
using namespace std;

class Solution {
    const int MOD = 1e9 + 7;

    vector<vector<long long>> multiply(const vector<vector<long long>>& A, const vector<vector<long long>>& B, int sz) {
        vector<vector<long long>> C(sz, vector<long long>(sz, 0));
        for (int i = 0; i < sz; ++i) {
            for (int k = 0; k < sz; ++k) {
                if (!A[i][k]) continue;
                for (int j = 0; j < sz; ++j) {
                    C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % MOD;
                }
            }
        }
        return C;
    }

    vector<vector<long long>> power(vector<vector<long long>> A, long long p, int sz) {
        vector<vector<long long>> res(sz, vector<long long>(sz, 0));
        for (int i = 0; i < sz; ++i) res[i][i] = 1;
        while (p > 0) {
            if (p & 1) res = multiply(res, A, sz);
            A = multiply(A, A, sz);
            p >>= 1;
        }
        return res;
    }

public:
    int zigZagArrays(int n, int l, int r) {
        int M = r - l + 1, sz = 2 * M;
        vector<vector<long long>> T(sz, vector<long long>(sz, 0));
        
        for (int j = 0; j < M; ++j) {
            for (int k = 0; k < j; ++k) T[j][M + k] = 1;
            for (int k = j + 1; k < M; ++k) T[M + j][k] = 1;
        }

        vector<vector<long long>> T_pow = power(T, n - 1, sz);
        long long total = 0;

        for (int i = 0; i < sz; ++i) {
            for (int j = 0; j < sz; ++j) {
                total = (total + T_pow[i][j]) % MOD;
            }
        }
        return total;
    }
};