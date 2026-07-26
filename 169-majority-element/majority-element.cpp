class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> mpp;
        for (int i:nums){
            mpp[i]++;
        }
        vector<pair<int,int>> arr(mpp.begin(),mpp.end());
        sort(arr.begin(),arr.end(), [](pair<int,int> a, pair<int,int> b){
            return a.second>b.second;
        });
        
        return arr[0].first;
    }
};