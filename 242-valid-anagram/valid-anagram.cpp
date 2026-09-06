class Solution {
public:
    bool isAnagram(string s, string t) {
        int n1 = s.size();
        int n2 = t.size();
        if (n1!=n2) return false;
        unordered_map<char,int> mpp;
        for (char ch: s){
            mpp[ch]++;
        }
        for (char ch:t){
            if (mpp.find(ch)==mpp.end() || mpp[ch]==0) return false;
            mpp[ch]--;
        }
        return true;
    }
};