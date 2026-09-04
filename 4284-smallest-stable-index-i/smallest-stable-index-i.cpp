class Solution {
public:
    int firstStableIndex(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> suffixMin(n);
        suffixMin[n-1] = arr[n-1];
        for (int i=n-2;i>=0;i--){
            suffixMin[i] = min(suffixMin[i+1],arr[i]);
        }
        vector<int> prefixMax(n);
        prefixMax[0] = arr[0];
        for (int i=1;i<n;i++){
            prefixMax[i] = max(prefixMax[i-1],arr[i]);
            //if (prefixMax[i]-suffixMin[i] <= k) return i;
        }
        for (int i = 0; i < n; i++) {
            if (prefixMax[i]-suffixMin[i] <= k) {
                return i;
            }
        }
        return -1;
    }
};