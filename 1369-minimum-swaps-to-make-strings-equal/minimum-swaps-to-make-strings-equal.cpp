class Solution {
public:
    int minimumSwap(string s1, string s2) {
        int xy_count=0, yx_count = 0;
        int n = s1.size();
        for (int i=0;i<n;i++){
            if (s1[i]==s2[i]) continue;
            if (s1[i] == 'x') xy_count++;
            else yx_count++;
        }
        if ((xy_count+yx_count)%2!=0) return -1;
        int res = xy_count/2 + yx_count/2;
        if (xy_count%2==1) res+=2;
        return res;
    }
};