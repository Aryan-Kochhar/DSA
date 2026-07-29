class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return (int) atmost(nums,goal)-atmost(nums,goal-1);
    }
    int atmost(const vector<int> &nums,int goals){
        if (goals<0) return 0;
        int l = 0,sum=0, ans = 0;
        for (int r=0;r<nums.size();r++){
            sum+=nums[r];
            while (sum>goals){
                sum-=nums[l];
                l++;
            }
            ans += r-l+1;
        }
        return ans;
    }
};