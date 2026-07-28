class Solution {
public:
    int compress(vector<char>& chars) {
        int read = 0, write = 0;
        int n = chars.size();

        while (read < n) {
            char c = chars[read];
            int count = 0;
            
            // count consecutive occurrences of c
            while (read < n && chars[read] == c) {
                read++;
                count++;
            }
            
            // write the character
            chars[write++] = c;
            
            // if count > 1, write the count as digits
            if (count > 1) {
                for (char digit : to_string(count)) {
                    chars[write++] = digit;
                }
            }
        }

        return write;
    }
};