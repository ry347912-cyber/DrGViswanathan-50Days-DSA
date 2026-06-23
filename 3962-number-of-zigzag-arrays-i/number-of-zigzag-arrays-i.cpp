class Solution {
public:
    int zigZagArrays(int n, int l, int r) {

        const int MOD = 1e9 + 7;

        int M = r - l + 1;

        vector<int> up(M), down(M);
        vector<int> nup(M), ndown(M);
        vector<int> pre(M), suf(M);

        for(int i=0;i<M;i++){
            up[i]=i;
            down[i]=M-1-i;
        }

        for(int len=3;len<=n;len++){

            pre[0]=down[0];

            for(int i=1;i<M;i++)
                pre[i]=(pre[i-1]+down[i])%MOD;

            suf[M-1]=up[M-1];

            for(int i=M-2;i>=0;i--)
                suf[i]=(suf[i+1]+up[i])%MOD;

            for(int i=0;i<M;i++){

                nup[i]=(i?pre[i-1]:0);

                ndown[i]=(i+1<M?suf[i+1]:0);
            }

            up.swap(nup);
            down.swap(ndown);
        }

        long long ans=0;

        for(int i=0;i<M;i++)
            ans=(ans+up[i]+down[i])%MOD;

        return ans;
    }
};