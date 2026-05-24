class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        int index = 0;
        int i = 0;
        while(i < n){
            int count = 0;
            char cur = chars[i];
            while(i < n && cur == chars[i]){
                i++;
                count++;
            }
            chars[index++] = cur;
            if(count > 1){
                string cnt = to_string(count);
                for(char c : cnt){
                    chars[index++] = c;
                }
            }
        }
        return index;
    }
};