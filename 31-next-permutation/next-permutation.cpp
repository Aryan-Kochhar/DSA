class Solution {
public:
    void nextPermutation(vector<int>& arr) {
        int n = arr.size();
        int firstIndex = -1;
        for (int i=n-1;i>0;i--){
            if (arr[i-1]<arr[i]){
                firstIndex = i-1;
                break;
            }
        }
        if (firstIndex != -1){
        int swapIndex = firstIndex;
            for (int i=n-1;i>=firstIndex+1;i--){
                if (arr[i]>arr[firstIndex]){
                    swapIndex = i;
                    break;
                }
            }
            swap(arr[swapIndex],arr[firstIndex]);
        }
        reverse(arr.begin()+firstIndex+1,arr.end());
    }
};