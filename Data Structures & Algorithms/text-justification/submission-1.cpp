class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int i = 0, n = words.size();
        vector<string> res;
        while(i < n){
            int lineSize = 0;
            int start = i;
            while(i<n && (lineSize + (int)words[i].size() + (i - start)) <= maxWidth){
                lineSize += words[i].size();
                i++;
            }
            string s;
            if(i < n && (i - start) > 1){
                int totalSpaces = maxWidth - lineSize;
                int totalGaps = i - start - 1;
                int base = totalSpaces / totalGaps;
                int extra = totalSpaces % totalGaps;
                for(int k = start; k < i; k++){
                    s += words[k];
                    if(k < i - 1){
                        int spaces = base + (k - start < extra ? 1 : 0);
                        s += string(spaces, ' ');
                    }
                }
            } else {
                s += words[start];
                for(int j = start + 1; j < i; j++){
                    s += " " + words[j];
                }
                s += string(maxWidth - s.size(), ' ');
            }
            res.push_back(s);
        }
        return res;
    }
};