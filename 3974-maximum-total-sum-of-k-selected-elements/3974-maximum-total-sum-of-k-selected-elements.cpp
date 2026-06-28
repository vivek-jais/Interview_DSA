class Solution {
public:
    long long maxSum(vector<int>& nums, int k, int mul) {
        long long ans = 0;
        sort(begin(nums),end(nums));
        int n = nums.size();
        int left = 0, right = n-1;
        for(int i=0;i<k;i++){
            if(mul>0){
                ans += (long long) nums[right]*mul;
                right--;
            }else{
                ans += (long long) nums[right];
               right--;
            }
            mul--;
        }
        return ans;
    }
};