class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        if (n==0) return 0;
        int l=0,r=0;
        int maxi = INT_MIN;
        unordered_map<char,int> mpp;
        while (r<n){
            if (mpp.find(s[r])!=mpp.end() && mpp[s[r]]>=l){
                l = mpp[s[r]]+1;
            }
            maxi = max(maxi,r-l+1);
            mpp[s[r]] = r;
            r++;
        }
        return maxi;
    }
};