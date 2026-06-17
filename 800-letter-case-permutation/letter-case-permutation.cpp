class Solution {
public:
    vector<string> letterCasePermutation(string s) {
        vector<string> res;
        solve(s, 0, res);

        return res;
    }
    void solve(string s, int i, vector<string>&res){
        if(i >= s.size()){
            res.push_back(s);
            return;
        }
        if(std::isdigit(s[i])){
            solve(s, i + 1, res);
            return;
        }
        s[i] = (char)std::toupper(s[i]);
        solve(s, i + 1, res);
        s[i] = (char)std::tolower(s[i]);
        solve(s, i + 1, res);
        return;
    }
};