class Solution {
public:
    int minMoves(vector<int>& nums) {
        int maxi = INT_MIN;
        int answer = 0;
        for (int i:nums){
            maxi = max(i,maxi);
        }
        for (auto &x:nums){
            answer += maxi-x;
        }
        return answer;
    }
};