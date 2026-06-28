class Solution {
public:
    long long solve(vector<int> &nums, function<long long(long long)> modify){
        const long long NEG = -(1LL << 60);
        long long dp0 = NEG, dp1= NEG, dp2 = NEG;

        long long ans = NEG;

        for(long long x:nums){
            long long y = modify(x);
            long long ndp0 = max(dp0+x, x);
            long long ndp1 = max({
                y,
                dp0 +y,
                dp1+y
            });

            long long ndp2 = max(
                {dp1 +x, 
                dp2 +x}
            );

            dp0 = ndp0;
            dp1 = ndp1;
            dp2 = ndp2;

            ans = max({ans, dp1, dp2});
        }
        return ans;
    }
    long long maxSubarraySum(vector<int>& nums, int k) {
        auto mult = [&](long long x){
            return x*1LL*k;
        };
        auto divide = [&](long long x){
            if(x>=0) return x/k;
            return -((-x))/k; //ceiling for negative
        };

        return max(solve(nums, mult),solve(nums, divide));
    }
};