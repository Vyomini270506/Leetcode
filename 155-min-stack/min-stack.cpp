class MinStack {
public:
    vector<int> arr;
    int m=INT_MAX;
    MinStack() {
        
    }
    
    void push(int val) {
        arr.push_back(val);
        m=min(m,val);
    }
    
    void pop() {
        int x=arr.back();
        arr.pop_back();
        if(x==m){
            m=INT_MAX;
            for(auto y:arr){
                m=min(m,y);
            }
        }
    }
    
    int top() {
        return arr.back();
    }
    
    int getMin() {
        return m;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */