class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map <char,int> hm;

        int left = 0;
        int right = 0;
        int max_len = 0;

        for(auto ch : s) {
            hm[ch]++;

            if(hm[ch] > 1){
                while(hm[ch] != 1){
                    hm[s[left]]--;
                    left++;
                }
                max_len = max(right-left + 1, max_len);
            }
            else{
                max_len = max(right-left + 1, max_len);
            }
            right++;
        }
        return max_len;
    }
};
