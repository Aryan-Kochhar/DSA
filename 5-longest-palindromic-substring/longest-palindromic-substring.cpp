class Solution {
public:
    string longestPalindrome(string s){
        if (s.empty()) return "";
        int start=0,end=0;
        for (int i=0;i<s.length();i++){
            int odd = expandAroundCentre(s,i,i);
            int even = expandAroundCentre(s,i,i+1);
            int maxi = max(odd,even);
            if (maxi>end-start){
                start = i-(maxi-1)/2;
                end = i+maxi/2;
            }
        }
        return s.substr(start,end-start+1);
    }

    int expandAroundCentre(string s, int left, int right){
        while (left>=0 && right<s.length() && s[left]==s[right]){
            left--;
            right++;
        }
        return right-left-1;
    }

};