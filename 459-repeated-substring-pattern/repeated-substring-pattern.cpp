class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n = s.length();
        int n2 = n/2;
        for (int i=1;i<=n2;i++){
            if (n%i == 0){
                string pattern = s.substr(0,i);
                string tmp = "";
                int cnt = n/i;
                for (int j=0;j<cnt;j++){
                    tmp+=pattern;;
                }
                if (tmp==s) return true;
            }
            //if ((s.substr(i,n2)+s.substr(i,n2)) == s) return true;
        }
        return false;    
    }
};