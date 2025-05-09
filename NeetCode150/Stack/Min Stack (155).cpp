#include <stack>
using namespace std;

class MinStack {    // Single stack solution (more space efficient)
    public:
        stack<long> s;
        long min_val;

        MinStack() {
        }
        
        void push(int val) {
            if(s.empty()){
                s.push(0);
                min_val = val;
            }   else {
                s.push(val - min_val);
                if(val < min_val)   min_val = val;   // update min_val
            }
        }
        
        void pop() {
            if(s.empty())   return;
            if(s.top() < 0) min_val -= s.top();
            s.pop();
        }
        
        int top() {
            return (s.top() > 0) ? (s.top() + min_val) : min_val;
        }
        
        int getMin() {
            return min_val;
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