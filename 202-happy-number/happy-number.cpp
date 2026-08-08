class Solution {
public:
    int NextNum(int n){
        int out = 0;
        while(n>0){
            int ones = n%10;
            out += ones*ones;
            n/=10;
        }
        return out;
    }
    bool isHappy(int n) {
        int slow = n;
        int fast = n;
        do{
            slow = NextNum(slow);
            fast = NextNum(NextNum(fast));
        } while (slow!=fast);

        return slow == 1;
    }
};