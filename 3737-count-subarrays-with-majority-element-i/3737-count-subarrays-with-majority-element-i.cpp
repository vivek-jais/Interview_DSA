class Solution {
    //Brute Force appraoch
    //O(n^2)
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        int count = 0;
        vector<int> freq2(n,0);

        if(nums[0]==target) freq2[0] = 1;

        for(int i=1;i<n;i++){
            if(nums[i] == target) freq2[i]  = 1 + freq2[i-1];
            else freq2[i] = freq2[i-1];
        }

        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
               int size = j -i +1;
               int half = (size)/2;
               int freq = (i==0)? freq2[j] :  freq2[j] - freq2[i-1];
               if(freq>half) count++;
            }
        }
        return count;
    }
};