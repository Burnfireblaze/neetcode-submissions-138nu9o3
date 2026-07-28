class MinStack {
private:
    stack<int> main_st;
    stack<int> min_st;
public:
    MinStack() {
        
    }
    
    void push(int value) {
        main_st.push(value);
        int min_val=INT_MAX;

        if(!min_st.empty())
        min_val= min(value,min_st.top());
        else
        min_val = value;

        min_st.push(min_val);
        return;
    }
    
    void pop() {
        main_st.pop();
        min_st.pop();
        return;
    }
    
    int top() {
        return main_st.top();
    }
    
    int getMin() {
        return min_st.top();
    }
};
