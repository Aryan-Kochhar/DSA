class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int cnt = 0;
        for (int i=0;i<nums.size();i++){
            int cnt1=nums[i];
            int j = i+1;
            if (cnt1 == goal) cnt++;
            while (j<nums.size()){
                cnt1+=nums[j];
                if (cnt1 == goal) cnt+=1;
                j++;
            }
        }
        return cnt;
    }
};