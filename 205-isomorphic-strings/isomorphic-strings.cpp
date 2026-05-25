class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int n1 = s.length(),n2 = t.length();
        if (n1!=n2) return false;
        unordered_map<char,int> mpp1;
        unordered_map<char,int> mpp2;
        for (int i=0;i<n1;i++){
            if (mpp1.find(s[i])==mpp1.end()) mpp1[s[i]] = i;
            if (mpp2.find(t[i])==mpp2.end()) mpp2[t[i]] = i;
            if (mpp1[s[i]]!=mpp2[t[i]]) return false;
        }
        return true;

    }
};
