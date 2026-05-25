class Solution {
public:
    bool checkIfPangram(string sentence) {
        if (sentence.length()<26) return false;
        vector<int> arr(26,0);
        for (char &ch : sentence){
            int idx = ch-'a';
            arr[idx]++;
        }
        for (int &i:arr){
            if (i==0) return false;            
        }
        return true;
    }
};