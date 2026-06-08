class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n = nums.size();
        if(n == 1) return nums;

        vector<int> more;
        int equal = 0;
        int lessid = 0;

        for(int x : nums){
            if(x < pivot){
                nums[lessid] = x;
                lessid++;
            }
            else if(x > pivot){
                more.push_back(x);
            }
            else{
                equal++;
            }
        }

        for(int i = 0; i < equal; i++){
            nums[lessid + i] = pivot;
        }

        int start = lessid + equal;

        for(int i = 0; i < more.size(); i++){
            nums[start + i] = more[i];
        }

        return nums;
    }
};