class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        unordered_map<char,char>hm = {
            {'}', '{'},
            {')', '('},
            {']', '['}
        };
        
        for (auto c : s){
            auto test = hm.find(c);
            if(test == hm.end()){
                st.push(c);
            }
            else{
                if (st.empty() || st.top() != test -> second)
                    return false;
                st.pop();
            }
        }
        return st.empty();
    }
};
