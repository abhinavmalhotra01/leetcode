class MyQueue {
    stack<int> s;
public:
    MyQueue() {
        
    }
    
    void push(int x) {
//         int sz = s.size();
//         s.push(x);
//         for(int i=0;i<sz;i++){
//             s.push(s.top());
            
//         }
        s.push(x);
    }
    
    int pop() {
        stack<int> s2;
        while(s.size()>1){
            s2.push(s.top());
            s.pop();
        }
        int x = s.top();
        s.pop();
        while(s2.size()){
            s.push(s2.top());
            s2.pop();
        }
        return x;
    }
    
    int peek() {
        stack<int> s2;
        while(s.size()>1){
            s2.push(s.top());
            s.pop();
        }
        int x = s.top();
        // s.pop();
        while(s2.size()){
            s.push(s2.top());
            s2.pop();
        }
        return x;
    }
    
    bool empty() {
        return !(s.size());
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */