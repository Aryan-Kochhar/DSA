class Solution {
public:
    int check(int a) {
        string s = to_string(a);
        int cnt = 0;

        for (int i = 1; i < s.size() - 1; i++) {

            int back = s[i - 1] - '0';
            int front = s[i + 1] - '0';
            int cur = s[i] - '0';

            // peak
            if (back < cur && front < cur)
                cnt++;

            // valley
            else if (back > cur && front > cur)
                cnt++;
        }
        return cnt;
    }
    int totalWaviness(int num1, int num2) {
        int ans = 0;

        for (int i = num1; i <= num2; i++) {
            ans += check(i);
        }

        return ans;
    }
};