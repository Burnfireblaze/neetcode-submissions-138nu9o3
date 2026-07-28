class Solution {
public:
    string decodeString(string s) {
        stack<int> counts;
        stack<string> strings;
        string curr = "";
        int k = 0;
        
        for (char c : s) {
            if (isdigit(c)) {
                k = k * 10 + (c - '0');
            } else if (c == '[') {
                counts.push(k);
                strings.push(curr);
                k = 0;
                curr = "";
            } else if (c == ']') {
                int repeat = counts.top(); counts.pop();
                string prev = strings.top(); strings.pop();
                string repeated = "";
                for (int i = 0; i < repeat; i++) repeated += curr;
                curr = prev + repeated;
            } else {
                curr += c;
            }
        }
        
        return curr;
    }
};