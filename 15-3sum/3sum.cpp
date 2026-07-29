class Solution {
public:
    vector<vector<int>> threeSum(vector<int> &nums){
        sort(nums.begin(),nums.end());
        int n = nums.size();
        vector<vector<int>> ans;
        for (int i=0;i<n-2;i++){
            if (i>0 && nums[i-1] == nums[i]) continue;
            int l=i+1,r=n-1;
            while (l<r){
                int sum = nums[l]+nums[r]+nums[i];
                if (sum<0) l++;
                else if (sum>0) r--;
                else {
                    ans.push_back({nums[i],nums[l],nums[r]});
                    while (l+1<r && nums[l]==nums[l+1]) l++;
                    while (l<r-1 && nums[r]==nums[r-1]) r--;
                    l++;r--;
                }
            } 
        }
        return ans;
    }
};