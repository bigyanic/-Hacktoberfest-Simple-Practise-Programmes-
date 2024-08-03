class MinStack {
public:
    stack<long> st;
    long long min=INT_MAX;
public:
    MinStack() { 
    }
    
    void push(int val) {
        long long value = (long)val;
        if(st.empty()){
            min=value;
            st.push(value);
        }
        else if(val<min){
            st.push(2*value-min);
            min=value;
        }
        else st.push(value);
    }
    
    void pop() {
        if(st.empty()) return;
        if(st.top()<min) min=(2*min - st.top());
        st.pop();
    }
    
    int top() {
        if(st.empty()) return -1;
        if(st.top()<min) return min;
        return st.top();
    }
    
    int getMin() {
        return min;
    }
};
