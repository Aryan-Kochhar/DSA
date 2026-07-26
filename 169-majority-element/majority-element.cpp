class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> mpp;
        for (int i:nums){
            mpp[i]++;
            if (mpp[i] > nums.size()/2) return i;
        }
        return -1;
    }
};