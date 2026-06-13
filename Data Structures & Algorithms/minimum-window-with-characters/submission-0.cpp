class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map <char, int> have, need;
        for(auto c : t){
            need[c]++;
        }
        int minLen=INT_MAX, minL = 0;
        int formed=0, required = need.size(), left=0;
        for(int i=0;i<s.size();++i){
            char c = s[i];
            if(++have[c] == need[c]){
                formed++;
            }
            while(formed == required){
                if((i - left + 1) < minLen){
                    minLen = i - left + 1;
                    minL = left;
                }
                if(have[s[left]]-- == need[s[left]]) formed--;
                ++left;
            }
        }
        return minLen == INT_MAX ? "" : s.substr(minL,minLen);
    }
};
