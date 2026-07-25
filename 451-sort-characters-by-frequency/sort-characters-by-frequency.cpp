class Solution {
public:
    string frequencySort(string s) {
        map<char,int> mpp;
        int n = s.size();
        for (char ch:s){
            mpp[ch]++;
        }
        string ans;
        vector<pair<char,int>> v(mpp.begin(),mpp.end());
        sort(v.begin(),v.end(),[](const pair<char,int> a,const pair<char,int> b){
            return a.second<b.second;
        });

        for (auto it = v.rbegin(); it!=v.rend();it++){
            char ch = it->first;
            int count = it->second;
            for (int i=0;i<count;i++){
                ans.push_back(ch);
            }
        }
        return ans;
    }
};