class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char, int> freq;
        for (char c : text) {
            if (c == 'b' || c == 'a' || c == 'l' || c == 'o' || c == 'n') {
                freq[c]++;
            }
        }
        int a = freq['a'];
        int b = freq['b'];
        int n = freq['n'];
        int o = freq['o'] / 2;
        int l = freq['l'] / 2;
        return min({b, a, l, o, n});
    }
};