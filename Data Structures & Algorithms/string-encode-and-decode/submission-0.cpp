class Solution {
public:

    string encode(vector<string>& strs) {
        string result;
        for (const string& s : strs) {
            result += to_string(s.size()) + "#" + s;
        }
        return result;
    }

    vector<string> decode(string s) {
        vector<string> result;
        int i = 0;
        while (i < s.size()) {
            int j = i;
            while (s[j] != '#') j++;   // find delimiter
            int len = stoi(s.substr(i, j - i));  // parse length
            result.push_back(s.substr(j + 1, len));  // extract that many characters
            i = j + 1 + len;  // advance past this string
        }
        return result;
    }
};
